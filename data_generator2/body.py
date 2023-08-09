import numpy as np

from parameters import BODY_M, BODY_J


def body_f(x: np.ndarray,
           F: np.ndarray) -> np.ndarray:
    """ Dynamics of the body

    x: state vector of the type
        (x_dot, y_dot, theta_dot, x, y, theta)
    F: force vector of the type (F_x, F_y, tau) resulting applied to the COM
    """
    dx = np.zeros(6)

    dx[0:2] = F[0:2] / BODY_M
    dx[2] = F[2] / BODY_J
    dx[3:6] = x[0:3]

    return dx
