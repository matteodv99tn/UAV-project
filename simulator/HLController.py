import numpy as np

from scipy.signal import place_poles

from .simutils import extract_position, extract_velocity, rotation_matrix_2d
from data import (
        m__body, J__body,
        kp__P, kd__P, kp__psi, kd__psi,
        gamma_P,
        N_turr
        )
from .functions import contact_force_dt, overall_force, contact_force

from autogen.lib.system_model import system_model
from autogen.lib.turret_force import turret_force
from autogen.lib.body_mdl import body_mdl

Kp = np.diag([kp__P, kp__P, kp__psi])
Kd = np.diag([kd__P, kd__P, kd__psi])

W2 = np.diag([1/m__body, 1/m__body, 1/J__body])

A = -gamma_P * np.eye(3)
B = gamma_P * np.eye(3)
K = place_poles(A, B, [-6, -6, -6]).gain_matrix

print("A:")
print(A)
print("B:")
print(B)
print("K:")
print(K)


def virtual_input(x: np.ndarray,
                  pref: np.ndarray,
                  pref_dot: np.ndarray,
                  pref_ddot: np.ndarray) -> np.ndarray:
    W1 = np.zeros((3, 3))
    R = rotation_matrix_2d(x[2])
    W1[0:2, 0:2] = m__body * R.T
    W1[2, 2] = J__body

    p = extract_position(x)
    v = extract_velocity(x)
    Fr = contact_force(x)

    return W1 @ (- Kp @ (p - pref)
                 - Kd @ (v - pref_dot)
                 + pref_ddot - W2 @ Fr)


def virtual_input_dt(x: np.ndarray,
                     pref: np.ndarray,
                     pref_dot: np.ndarray,
                     pref_ddot: np.ndarray,
                     pref_dddot: np.ndarray) -> np.ndarray:
    # Ft = turret_force(x)
    Fr = contact_force(x)
    F = overall_force(x)
    acc = body_mdl(x[0:6], F)[3:6]
    Fr_dt = contact_force_dt(x)
    W1 = np.zeros((3, 3))
    R = rotation_matrix_2d(x[2])
    S = np.array([[0, 1, 0], [-1, 0, 0], [0, 0, 0]]) * x[2]
    W1[0:2, 0:2] = m__body * R.T
    W1[2, 2] = J__body

    pos = extract_position(x)
    vel = extract_velocity(x)

    v = - Kp @ (pos - pref) - Kd @ (vel - pref_dot) \
        + pref_ddot - W2 @ Fr
    vd = - Kp @ (vel - pref_dot) - Kd @ (acc - pref_ddot) \
         + pref_dddot - W2 @ Fr_dt

    return W1 @ (S @ v + vd)


def control_law(x: np.ndarray,
                pref: np.ndarray,
                pref_dot: np.ndarray,
                pref_ddot: np.ndarray,
                pref_dddot: np.ndarray) -> np.ndarray:
    ut = turret_force(x.copy())
    uv = virtual_input(x.copy(), pref, pref_dot, pref_ddot)
    uvdot = virtual_input_dt(x.copy(), pref, pref_dot, pref_ddot, pref_dddot)
    Binv = np.linalg.inv(B)
    return Binv @ (uvdot - A@uv) - K @ (ut - uv)
