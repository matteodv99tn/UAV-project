import numpy as np
import sys
import os

from utils.ode_integration import RK1, RK4, Function

from autogen.lib.motor_sys_lb_x import motor_sys_lb_x
from autogen.lib.motor_sys_ub_x import motor_sys_ub_x
from autogen.lib.motor_sys_lb_u import motor_sys_lb_u
from autogen.lib.motor_sys_ub_u import motor_sys_ub_u
from autogen.lib.motor_force_lb import motor_force_lb
from autogen.lib.motor_force_ub import motor_force_ub
from autogen.lib.motor_sys_mdl import \
        motor_sys_mdl, \
        motor_sys_mdl_dx, \
        motor_sys_mdl_du
from autogen.lib.motor_force_mdl import \
        motor_force_mdl, \
        motor_force_mdl_dx
from data import dt_controller


filedir = os.path.dirname(__file__)
MODEL_DIR = os.path.join(filedir, "models")

dt = float(dt_controller)
Ndt = 3
ode_solver = RK4

motor_mdl = Function(fun=motor_sys_mdl,
                     fun_dx=motor_sys_mdl_dx,
                     fun_du=motor_sys_mdl_du)


def force(x: np.ndarray, u: np.ndarray = None) -> np.ndarray:
    if u is None:
        return motor_force_mdl(x)

    xnext, _ = ode_solver.integrate(motor_mdl, x, u, dt, Ndt)
    return motor_force_mdl(xnext)


x_lb: np.ndarray = motor_sys_lb_x()
x_ub: np.ndarray = motor_sys_ub_x()
u_lb: np.ndarray = motor_sys_lb_u()
u_ub: np.ndarray = motor_sys_ub_u()
F_lb: np.ndarray = motor_force_lb()
F_ub: np.ndarray = motor_force_ub()
