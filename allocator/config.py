import numpy as np
import os

from autogen.lib.rospo_com_force import rospo_com_force, rospo_com_force_dx
from autogen.lib.rospo_com_force_lb import rospo_com_force_lb
from autogen.lib.rospo_com_force_ub import rospo_com_force_ub
from autogen.lib.rospo_com_force_in_lb import rospo_com_force_in_lb
from autogen.lib.rospo_com_force_in_ub import rospo_com_force_in_ub
from autogen.lib.rospo_com_force_max import rospo_com_force_max

from data import dt_controller

filedir = os.path.dirname(__file__)
MODEL_DIR = os.path.join(filedir, "models")

dt = dt_controller
Ndt = 3


def force(x: np.ndarray, u: np.ndarray = None) -> np.ndarray:
    if u is None:
        return rospo_com_force(x)

    return rospo_com_force(x + dt*u)


def force_dx(x: np.ndarray) -> np.ndarray:
    return rospo_com_force_dx(x)


x_lb: np.ndarray = rospo_com_force_lb()
x_ub: np.ndarray = rospo_com_force_ub()
u_lb: np.ndarray = rospo_com_force_in_lb()
u_ub: np.ndarray = rospo_com_force_in_ub()
F_max: np.ndarray = rospo_com_force_max()
