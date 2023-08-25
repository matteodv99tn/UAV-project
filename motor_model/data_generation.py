import numpy as np
import sys
import os

from config import \
        motor_mdl, force, ode_solver, motor_force_mdl_dx, \
        dt, Ndt, \
        x_lb, x_ub, u_lb, u_ub, F_lb, F_ub

filedir = os.path.dirname(__file__)
parentdir = os.path.normpath(os.path.join(filedir, ".."))
sys.path.insert(0, parentdir)

from autogen.lib.motor_current import motor_current


def cost_function(u: np.ndarray,
                  x: np.ndarray,
                  Fref: np.ndarray) -> tuple[np.ndarray, np.ndarray]:
    u = u.reshape((-1,))
    xnext, dx_du = ode_solver.integrate(motor_mdl, x, u, dt, Ndt)
    F = force(xnext)
    dF = F - Fref
    cost = dF.T @ dF
    jac = 2 * dF * motor_force_mdl_dx(x) @ dx_du

    return cost, jac


def test():
    t = np.arange(0, 10, dt)
    N = t.size
    dF = F_ub - F_lb
    F_refs = F_lb + 0.5*dF + 0.3*dF*np.sin(2*np.pi*t)

    plt.figure()
    plt.plot(t, F_refs)

    Xhist = np.zeros((N, 2))
    Fhist = np.zeros(N)
    x = Xhist[0, :]
    u = np.array([14.0])

    for i in range(N-1):
        Fdes = F_refs[i]
        res = minimize(cost_function, u, args=(x, Fdes),
                       jac=True, bounds=[(u_lb[0], u_ub[0])])
        u = res.x
        Fhist[i] = force(x)
        x, _ = ode_solver.integrate(motor_mdl, x, u, dt, 3)
        Xhist[i+1, :] = x

    plt.plot(t, Fhist)
    plt.show()



if __name__ == "__main__":
    import pandas as pd
    from scipy.optimize import minimize
    import matplotlib.pyplot as plt

    from timeit import default_timer as timer

    test()
    sys.exit(0)

    df = pd.DataFrame(columns=["state", "target", "input", "Fi", "Fe", "cost"])

    Nstep1 = 10000
    Nstep2 = 50000
    Nstep3 = 100000

    force_sigma_divider = 15
    current_sigma_divider = 25

    print("x_lb: ", x_lb)
    print("x_ub: ", x_ub)
    print("u_lb: ", u_lb)
    print("u_ub: ", u_ub)
    print("F_lb: ", F_lb)
    print("F_ub: ", F_ub)

    print("Generating %d random samples..." % Nstep1)
    start = timer()
    for i in range(Nstep1):
        u = np.random.uniform(u_lb, u_ub)
        Fdes = np.random.uniform(F_lb, F_ub)
        x0 = np.random.uniform(x_lb, x_ub)
        res = minimize(cost_function, u, args=(x0, Fdes),
                       jac=True, bounds=[(u_lb[0], u_ub[0])])
        df.loc[i] = [x0, Fdes, res.x,
                     force(x0),
                     force(x0, res.x),
                     res.fun]

    stop = timer()
    print(f"Average time per iteration: {(stop - start) / Nstep1}")

    print("Generating %d samples based on current force..." % Nstep2)
    sigma_F = (F_ub - F_lb) / force_sigma_divider
    start = timer()
    for i in range(Nstep2):
        u = np.random.uniform(u_lb, u_ub)
        x0 = np.random.uniform(x_lb, x_ub)
        Fdes = force(x0) + np.random.normal(0, sigma_F)
        res = minimize(cost_function, u, args=(x0, Fdes),
                       jac=True, bounds=[(u_lb[0], u_ub[0])])
        df.loc[len(df)] = [x0, Fdes, res.x,
                           force(x0),
                           force(x0, res.x),
                           res.fun]

    stop = timer()
    print(f"Average time per iteration: {(stop - start) / Nstep2}")

    print("Generating %d samples based on current angular speed..." % Nstep3)
    sigma_i = (x_ub[1] - x_lb[1]) / current_sigma_divider
    start = timer()
    for i in range(Nstep3):
        u = np.random.uniform(u_lb, u_ub)
        x0 = np.random.uniform(x_lb, x_ub)
        x0[1] = motor_current(np.array([x0[1]])) + np.random.normal(0, sigma_i)
        Fdes = force(x0) + np.random.normal(0, sigma_F)
        res = minimize(cost_function, u, args=(x0, Fdes),
                       jac=True, bounds=[(u_lb[0], u_ub[0])])
        df.loc[len(df)] = [x0, Fdes, res.x,
                           force(x0),
                           force(x0, res.x),
                           res.fun]

    stop = timer()
    print(f"Average time per iteration: {(stop - start) / Nstep3}")

    print("Saving data...")
    path = os.path.join(os.path.dirname(__file__), "data.pkl")
    df.to_pickle(path)

    data = np.stack(df["input"].values).reshape(-1)
    plt.hist(data, bins=10)
    plt.show()
