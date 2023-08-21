import os
import sys
import numpy as np

filedir = os.path.dirname(__file__)
parentdir = os.path.normpath(os.path.join(filedir, ".."))
sys.path.insert(0, parentdir)

from autogen.lib.x_lower_bound import x_lower_bound
from autogen.lib.x_upper_bound import x_upper_bound
from autogen.lib.u_lower_bound import u_lower_bound
from autogen.lib.u_upper_bound import u_upper_bound

X_lb: np.ndarray = x_lower_bound()
X_ub: np.ndarray = x_upper_bound()
U_lb: np.ndarray = u_lower_bound()
U_ub: np.ndarray = u_upper_bound()

N_inputs = U_lb.shape[0]
N_states = X_lb.shape[0]
N_turrets = int((N_states - 6) / 3)

if N_turrets != N_inputs/2:
    raise ValueError("N_turrets != N_inputs/2")
