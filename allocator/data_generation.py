import numpy as np
import os

from allocator.config import \
    dt, force, force_dx, \
    x_lb, x_ub, u_lb, u_ub, F_max

from data import N_turr
from autogen.lib.rospo_com_cost_func import \
        rospo_com_cost_func, rospo_com_cost_func_du

kcost1 = 1.0
kcost2 = 0.1
kcost3 = 0.2
# Weight matrix for reaching target
W1 = np.diag([1.0, 1.0, 0.3])

# Weight matrix for staying within bounds
W2 = np.diag([0.1, 1.0] * N_turr)

W3 = np.diag([1.0, 0.1] * N_turr)

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
    # F = force(x + dt*u)
    # dF = F - Fref

    # -- Get close to target
    # cost1 = dF.T @ W1 @ dF
    # jac1 = 2 * dt * dF.T @ W1 @ force_dx(x)
    cost1 = rospo_com_cost_func(np.concatenate((x, Fref)), u)
    jac1 = rospo_com_cost_func_du(np.concatenate((x, Fref)), u)

    # -- Stay within bounds
    xnext = x + dt_bound*u
    dxmax = np.maximum(xnext - x_ub, x_lb - xnext)
    dxmax[dxmax < 0] = 0
    cost2 = dxmax.T @ W2 @ dxmax
    jac2 = 2 * W2 @ dxmax

    cost3 = u.T @ W3 @ u
    jac3 = 2 * W3 @ u

    cost = kcost1*cost1 + kcost2*cost2 + kcost3*cost3
    jac = kcost1*jac1 + kcost2*jac2 + kcost3*jac3
    return cost, jac


if __name__ == "__main__":
    import pandas as pd
    from scipy.optimize import minimize

    from timeit import default_timer as timer

    bounds = [(u_lb[i], u_ub[i]) for i in range(8)]
    col_names = ["state", "target", "input", "cost"]
    df = pd.DataFrame(columns=col_names)

    Ntests = 400
    Ninitcond = 60
    Nforwardstep = 15

    Fnorm = F_max[0]
    torque_max = F_max[1]
    u = np.zeros(2*N_turr)

    Nall = Ntests*Ninitcond*Nforwardstep
    xdata = np.zeros((Nall, 2*N_turr))
    Fdata = np.zeros((Nall, 3))
    udata = np.zeros((Nall, 2*N_turr))
    cdata = np.zeros((Nall,))
    idx = 0
    print("Generating %d samples..." % Nall)
    start = timer()
    for i in range(Ntests):
        angle = np.random.rand() * 2 * np.pi
        torque = np.random.normal() * torque_max / 3
        Fref = np.array([Fnorm * np.cos(angle),
                         Fnorm * np.sin(angle),
                         torque])

        for j in range(Ninitcond):
            x = x_lb + (x_ub - x_lb)*np.random.rand(2*N_turr)

            for k in range(Nforwardstep):
                res = minimize(cost_function, u, args=(x, Fref),
                               jac=True, bounds=bounds)
                u = res.x
                x = x + dt*u*np.random.rand()*20
                xdata[idx] = x
                Fdata[idx] = Fref
                udata[idx] = u
                cdata[idx] = res.fun
                idx = idx + 1

    df1 = pd.DataFrame(xdata)
    df1 = df1.apply(lambda r: tuple(r), axis=1).apply(np.array)
    df1.name = "state"
    df2 = pd.DataFrame(Fdata)
    df2 = df2.apply(lambda r: tuple(r), axis=1).apply(np.array)
    df2.name = "target"
    df3 = pd.DataFrame(udata)
    df3 = df3.apply(lambda r: tuple(r), axis=1).apply(np.array)
    df3.name = "input"
    df4 = pd.Series(cdata)
    df4.name = "cost"
    df_tmp = pd.concat([df1, df2, df3, df4], axis=1)
    df = pd.concat([df, df_tmp], axis=0)

    stop = timer()
    print(f"Average time per iteration: {(stop - start) / Nall}")

    Ntests = 2000
    Ninitcond = 200
    Nforwardstep = 3

    Nall = Ntests*Ninitcond*Nforwardstep
    xdata = np.zeros((Nall, 2*N_turr))
    Fdata = np.zeros((Nall, 3))
    udata = np.zeros((Nall, 2*N_turr))
    cdata = np.zeros((Nall,))
    idx = 0
    print("Generating %d samples..." % Nall)
    start = timer()
    for i in range(Ntests):
        x = x_lb + (x_ub - x_lb)*np.random.rand(2*N_turr)

        for j in range(Ninitcond):
            Fref = force(x) + np.random.normal(0, 1, 3)

            for k in range(Nforwardstep):
                res = minimize(cost_function, u, args=(x, Fref),
                               jac=True, bounds=bounds)
                u = res.x
                x = x + dt*u*np.random.rand()*20
                xdata[idx] = x
                Fdata[idx] = Fref
                udata[idx] = u
                cdata[idx] = res.fun
                idx = idx + 1

    df1 = pd.DataFrame(xdata)
    df1 = df1.apply(lambda r: tuple(r), axis=1).apply(np.array)
    df1.name = "state"
    df2 = pd.DataFrame(Fdata)
    df2 = df2.apply(lambda r: tuple(r), axis=1).apply(np.array)
    df2.name = "target"
    df3 = pd.DataFrame(udata)
    df3 = df3.apply(lambda r: tuple(r), axis=1).apply(np.array)
    df3.name = "input"
    df4 = pd.Series(cdata)
    df4.name = "cost"
    df_tmp = pd.concat([df1, df2, df3, df4], axis=1)
    df = pd.concat([df, df_tmp], axis=0)

    stop = timer()
    print(f"Average time per iteration: {(stop - start) / Nall}")

    print("Saving data...")
    path = os.path.join(os.path.dirname(__file__), "data.pkl")
    df.to_pickle(path)
