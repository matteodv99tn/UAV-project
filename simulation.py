import numpy as np
import matplotlib.pyplot as plt

from os.path import join

from utils.ode_integration import RK4, Function

from autogen.lib.system_model import system_model
from autogen.lib.turret_force import turret_force
from autogen.lib.contact_force import contact_force
from autogen.lib.motor_force_mdl import motor_force_mdl
from autogen.lib.rospo_com_force import rospo_com_force

from neuralnetworks import FullyConnectedNN, load_model

import allocator.data_preparation as alloc
import motor_model.data_preparation as motor

from simulator.visualisation import plot_rospo
from simulator.HLController import control_law
from simulator.functions import overall_force
from simulator.simutils import extract_turret_state
from simulator.setup import (t, N_timesteps,
                             p_ref, p_ref_dot,
                             p_ref_ddot, p_ref_dddot,
                             )

from allocator.data_generation import cost_function, u_lb, u_ub
from scipy.optimize import minimize

from data import (N_states, N_turr, dt_controller)


x = np.zeros(18)

X_hist = np.zeros((len(t), N_states))

u = np.array([0, 0, 0, 0, 0, 0, 0, 0])
u[0::2] = 6
print(u)


allocator = load_model(join(".", "allocator", "models",
                            "11_16_16_8.keras"))
speedcontroller = load_model(join(".", "motor_model", "models",
                                  "3_32_32_1.keras"))


def dynamic_func(x, u):
    F = overall_force(x)
    return system_model(x, np.concatenate((F, u)))


def compute_controls(x: np.ndarray, uvc: np.ndarray) -> np.ndarray:
    print("------------")
    print("Current state:", x)
    print("Desired:", uvc)
    u = np.zeros(2*N_turr)
    # separate the state of the different turrets and for each one compute the
    # force
    x_turrets = [extract_turret_state(x.copy(), i) for i in range(N_turr)]
    F_turrets = [motor_force_mdl(X) for X in x_turrets]
    X = np.array([[F_turrets[i][0], x_turrets[i][-1]] for i in range(N_turr)])\
          .flatten()
    # build the input for the allocator
    tmp = [[F_turrets[i][0], x_turrets[i][-1]] for i in range(N_turr)]
    x_allocator = np.concatenate((np.array(tmp).flatten(),
                                  uvc))
    print("NN input pre-normalization:", x_allocator)
    x_allocator = alloc.normalize_x_data(x_allocator.reshape(1, -1))
    print("NN input:", x_allocator)
    # Compute allocation as prediction of the NN
    u_allocator = allocator.model.predict(x_allocator, verbose=0)
    print("Prediction:", u_allocator)
    u_allocator = alloc.denormalize_y_data(u_allocator.reshape(1, -1))
    print("Denormalized:", u_allocator)
    u_allocator = u_allocator.flatten()
    X = X + dt_controller*u_allocator

    # Build the inputs for the speed controller
    for i in range(N_turr):
        xnn = x_turrets[i]
        xnn[-1] = X[2*i]
        xnn = motor.normalize_x_data(xnn.reshape(1, -1))
        unn = speedcontroller.model.predict(xnn, verbose=0)
        u[2*i] = motor.denormalize_y_data(unn.reshape(1, -1))
        u[2*i + 1] = u_allocator[2*i + 1]

    print(u)
    return u


def controls(x: np.ndarray, uvc: np.ndarray) -> np.ndarray:
    bounds = [(u_lb[i], u_ub[i]) for i in range(8)]
    x_turrets = [extract_turret_state(x.copy(), i) for i in range(N_turr)]
    F_turrets = [motor_force_mdl(X) for X in x_turrets]
    X = np.array([[F_turrets[i][0], x_turrets[i][-1]] for i in range(N_turr)])\
          .flatten().copy()
    uall = np.zeros(2*N_turr)
    minsol = minimize(cost_function, uall, args=(X, uvc),
                      jac=True, bounds=bounds, method="SLSQP")
    uall = minsol.x
    X = X + dt_controller*uall

    u = np.zeros(2*N_turr)
    for i in range(N_turr):
        # print("Turr #,", i, "->", x_turrets[i])
        Ftarget = F_turrets[i][0] + uall[2*i]*dt_controller
        xnn = x_turrets[i].copy()
        xnn[-1] = Ftarget
        xnn = motor.normalize_x_data(xnn.reshape(1, -1))
        u[2*i] = speedcontroller.model.predict(xnn, verbose=0)
        u[2*i] = motor.denormalize_y_data(u[2*i].reshape(1, -1))
        u[2*i + 1] = uall[2*i + 1]

    return u


rospo_dynamics = Function(dynamic_func, None, None)


bounds = [(u_lb[i], u_ub[i]) for i in range(8)]
print("LB:", u_lb)
print("UB:", u_ub)
print("Bounds:", bounds)
input("Press Enter to continue...")

x[0] = 1
x[8] = 1
x[11] = 0.2
x[14] = -0.4
x[17] = 0.2
tmp = 3.14/2
x[11] = tmp
x[14] = tmp
x[17] = tmp

Uvc_hist = np.zeros((N_timesteps, 3))
U_hist = np.zeros((N_timesteps, 2*N_turr))
X_hist = np.zeros((N_timesteps, 6 + 3*N_turr))


print("x: ", x)
for k, v in enumerate(t):
    uvc = control_law(x, p_ref[:, k], p_ref_dot[:, k],
                      p_ref_ddot[:, k], p_ref_dddot[:, k])
    # u = compute_controls(x, uvc)
    u = controls(x, uvc)
    x = RK4.integrate(rospo_dynamics,
                      x, u,
                      dt_controller, 3,
                      jacobian=False)
    Uvc_hist[k, :] = uvc
    U_hist[k, :] = u
    X_hist[k, :] = x
    plt.ion()
    plt.clf()
    plot_rospo(x, Pdes=p_ref[:, k], Fdes=uvc)
    plt.plot(p_ref[0, :], p_ref[1, :], 'k--')
    plt.gca().set_xlim([-2, 2])
    plt.gca().set_ylim([-2, 2])
    plt.show()
    plt.pause(0.01)


np.save("Uvc_hist.npy", Uvc_hist)
np.save("U_hist.npy", U_hist)
np.save("X_hist.npy", X_hist)

plt.figure()
x_coord = X_hist[:, 0]
y_coord = X_hist[:, 1]
plt.plot(t, x_coord, label="x")
plt.plot(t, p_ref[0, :], label="x_ref")
plt.plot(t, y_coord, label="y")
plt.plot(t, p_ref[1, :], label="y_ref")
plt.show()
