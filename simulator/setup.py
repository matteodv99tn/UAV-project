import numpy as np

from math import pi

from data import (rho__x, c__1,
                  rho__y, c__2,
                  dt_controller)

T_simulation = 2 * pi / min(c__1, c__2)

t = np.arange(0, T_simulation, dt_controller)
N_timesteps = len(t)


p_ref = np.stack((rho__x * np.cos(c__1 * t),
                  rho__y * np.sin(c__2 * t),
                  0 * t))
p_ref_dot = np.stack((-rho__x * c__1 * np.sin(c__1 * t),
                      rho__y * c__2 * np.cos(c__2 * t),
                      0 * t))
p_ref_ddot = np.stack((-rho__x * c__1**2 * np.cos(c__1 * t),
                       -rho__y * c__2**2 * np.sin(c__2 * t),
                       0 * t))
p_ref_dddot = np.stack((rho__x * c__1**3 * np.sin(c__1 * t),
                        -rho__y * c__2**3 * np.cos(c__2 * t),
                        0 * t))
