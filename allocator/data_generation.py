import numpy as np
import sys
import os

from config import \
    dt, force, force_dx, \
    x_lb, x_ub, u_lb, u_ub, F_max

N_turrets = int(len(x_lb) / 2)

kcost1 = 10.0
kcost2 = 1.0
# Weight matrix for reaching target
W1 = np.diag([1.0, 1.0, 0.3])

# Weight matrix for staying within bounds
W2 = np.diag([0.1, 1.0] * N_turrets)

dt_bound = 1


def cost1(u: np.ndarray, x: np.ndarray, Fref: np.ndarray) -> float:
    u = u.reshape((-1,))
    F = force(x + dt*u)
    dF = F - Fref
    return kcost1 * dF.T @ dF


def cost2(u: np.ndarray, x: np.ndarray, Fref: np.ndarray) -> float:
    xnext = x + dt_bound*u
    dxmax = np.maximum(xnext - x_ub, x_lb - xnext)
    dxmax[dxmax < 0] = 0
    return kcost2 * dxmax.T @ W2 @ dxmax


def cost_function(u: np.ndarray,
                  x: np.ndarray,
                  Fref: np.ndarray) -> tuple[np.ndarray, np.ndarray]:
    u = u.reshape((-1,))
    F = force(x + dt*u)
    dF = F - Fref

    # -- Get close to target
    cost1 = dF.T @ dF
    jac1 = 2 * dF.T @ W1 @ force_dx(x)

    # -- Stay within bounds
    xnext = x + dt_bound*u
    dxmax = np.maximum(xnext - x_ub, x_lb - xnext)
    dxmax[dxmax < 0] = 0
    cost2 = dxmax.T @ W2 @ dxmax
    jac2 = 2 * W2 @ dxmax

    cost = kcost1*cost1 + kcost2*cost2
    jac = kcost1*jac1 + kcost2*jac2
    return cost, jac


if __name__ == "__main__":
    import pandas as pd
    from scipy.optimize import minimize
    import matplotlib.pyplot as plt

    from timeit import default_timer as timer

    bounds = [(u_lb[i], u_ub[i]) for i in range(8)]

    df = pd.DataFrame(columns=["state", "target", "input", "cost"])

    Ntests = 100
    Ninitcond = 100
    Nforwardstep = 15

    Fnorm = F_max[0]
    torque_max = F_max[1]
    u = np.zeros(2*N_turrets)

    Nall = Ntests*Ninitcond*Nforwardstep
    print("Generating %d samples..." % Nall)
    start = timer()
    for i in range(Ntests):
        angle = np.random.rand() * 2 * np.pi
        torque = np.random.normal() * torque_max / 3
        Fref = np.array([Fnorm * np.cos(angle),
                         Fnorm * np.sin(angle),
                         torque])

        for j in range(Ninitcond):
            x = x_lb + (x_ub - x_lb)*np.random.rand(2*N_turrets)

            for k in range(Nforwardstep):
                res = minimize(cost_function, u, args=(x, Fref),
                               jac=True, bounds=bounds)
                u = res.x
                x = x + dt*u*np.random.rand()*20
                df[len(df)] = [x, Fref, u, res.fun]

    stop = timer()
    print(f"Average time per iteration: {(stop - start) / Nall}")

    print("Generating %d samples..." % Nall)
    start = timer()
    for i in range(Ntests):
        x = x_lb + (x_ub - x_lb)*np.random.rand(2*N_turrets)

        for j in range(Ninitcond):
            Fref = force(x) + np.random.normal(0, 0.1, 3)

            for k in range(Nforwardstep):
                res = minimize(cost_function, u, args=(x, Fref),
                               jac=True, bounds=bounds)
                u = res.x
                x = x + dt*u*np.random.rand()*20
                df[len(df)] = [x, Fref, u, res.fun]

    stop = timer()
    print(f"Average time per iteration: {(stop - start) / Nall}")

    print("Saving data...")
    path = os.path.join(os.path.dirname(__file__), "data.pkl")
    df.to_pickle(path)
