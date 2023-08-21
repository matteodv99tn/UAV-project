import os
import sys
import numpy as np

filedir = os.path.dirname(__file__)
parentdir = os.path.normpath(os.path.join(filedir, ".."))
sys.path.insert(0, parentdir)


from autogen.lib.turret_force_mdl import turret_force_mdl_dx
from autogen.lib.system_mdl import system_mdl, system_mdl_du


def force_dt(x: np.ndarray, u: np.ndarray) -> np.ndarray:
    return turret_force_mdl_dx(x, u) @ system_mdl(x, u)


def cost_function(u: np.ndarray,
                  x: np.ndarray,
                  dF_dt_ref: np.ndarray,
                  with_jacobian: bool = True
                  ) -> np.ndarray | tuple:
    f = system_mdl(x, u)
    dF_dx = turret_force_mdl_dx(x, u)

    dF_dt = dF_dx @ f
    dF_dt_delta = dF_dt - dF_dt_ref
    cost = dF_dt_delta.T @ dF_dt_delta

    if not with_jacobian:
        return cost

    df_du = system_mdl_du(x, u)
    A = dF_dx.T @ dF_dx
    jac = 2 * df_du.T @ A @ f
    return (cost, jac)
