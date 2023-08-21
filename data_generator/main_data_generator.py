import numpy as np
import pandas as pd
import os

from scipy.optimize import minimize
from cost_function import cost_function

from setup import N_turrets, N_inputs, N_states, X_lb, X_ub, U_lb, U_ub
from timeit import default_timer as timer


filedir = os.path.dirname(__file__)
parentdir = os.path.normpath(os.path.join(filedir, ".."))
datadir = os.path.join(parentdir, "data")

N_samples = 100
X_delta = X_ub - X_lb


def main():
    col_names = ["states", "reference", "inputs"]

    df = pd.DataFrame(columns=col_names)

    u = np.zeros(N_inputs)
    start = timer()

    for i in range(N_samples):
        x0 = generate_initial_condition()
        dFref = np.random.rand(3)

        res = minimize(cost_function, u, args=(x0, dFref), jac=True)
        u = res.x
        # df.loc[i] = [list(x0), list(dFref), list(u)]
        df.loc[i] = [x0, dFref, u]

    end = timer()
    print(f"Time elapsed: {end - start}")
    print(f"Average time per iteration: {(end - start) / N_samples}")
    print(df.dtypes)
    print(type(df.loc[0, "states"]))

    df.to_pickle(os.path.join(datadir, "data.pkl"))


def generate_initial_condition():
    return X_lb + np.random.rand(N_states) * X_delta


if __name__ == "__main__":
    main()
