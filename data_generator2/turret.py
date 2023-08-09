import numpy as np

from parameters import TURR_KT, TURR_KV, TURR_KL, TURR_J, TURR_R, TURR_L


def turret_f(x: np.ndarray,
             u: np.ndarray) -> np.ndarray:
    """ Dynamics of the turret

    x of type [Omega, ii, phi]
    u of type [v, d_phi]
    """
    f = np.zeros(3)

    Omega = x[0]
    ii = x[1]
    v = u[0]

    num0 = ii - TURR_KT*TURR_KV*Omega**2
    den0 = TURR_J*TURR_KV
    num1 = TURR_KV*v - Omega - TURR_R*TURR_KV*ii
    den1 = TURR_L*TURR_KV
    f[0] = num0/den0
    f[1] = num1/den1
    f[2] = u[2]

    return f


def turret_df_dx(x: np.ndarray,
                 u: np.ndarray) -> np.ndarray:
    """ Jacobian of turret_f w.r.t. x """
    df_dx = np.zeros((3, 3))

    Omega = x[0]

    df_dx[0, 0] = -2*TURR_KT*Omega/TURR_J
    df_dx[0, 1] = 1/(TURR_J*TURR_KV)
    df_dx[1, 0] = -1/(TURR_L*TURR_KV)
    df_dx[1, 1] = -TURR_R/TURR_L

    return df_dx


def turret_df_du(x: np.ndarray,
                 u: np.ndarray) -> np.ndarray:
    """ Jacobian of turret_f w.r.t. u """
    df_du = np.zeros((3, 2))
    df_du[1, 0] = 1/TURR_L
    df_du[2, 1] = 1
    return df_du


def turret_Force_vector(x: np.ndarray) -> np.ndarray:
    F = np.zeros(3)
    Fmod = TURR_KL*x[0]**2
    F[0] = Fmod * np.cos(x[2])
    F[1] = Fmod * np.sin(x[2])
    return F
