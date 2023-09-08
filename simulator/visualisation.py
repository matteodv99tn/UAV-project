import numpy as np
import matplotlib.pyplot as plt

from .simutils import extract_position, extract_turret_state
from .functions import overall_force
from data import (pos__x__contact as dimx, pos__y__contact as dimy,
                  P_turret1, P_turret2, P_turret3, P_turret4,
                  P_contact1, P_contact2, P_contact3, P_contact4,
                  F_contact_max, F_turr_max
                  )

from autogen.lib.force_contact1 import force_contact1
from autogen.lib.force_contact2 import force_contact2
from autogen.lib.force_contact3 import force_contact3
from autogen.lib.force_contact4 import force_contact4
from autogen.lib.motor_force_mdl import motor_force_mdl


arrow_len = 0.7

max_overall_force = 3*F_turr_max


contact_pairs = [
        (force_contact1, np.array(P_contact1).flatten()),
        (force_contact2, np.array(P_contact2).flatten()),
        (force_contact3, np.array(P_contact3).flatten()),
        (force_contact4, np.array(P_contact4).flatten()),
        ]

turret_positions = [np.array(P_turret1).flatten(),
                    np.array(P_turret2).flatten(),
                    np.array(P_turret3).flatten(),
                    np.array(P_turret4).flatten()]


def affine_transformation_matrix(X: np.ndarray):
    x = X[0]
    y = X[1]
    theta = X[2]
    return np.array([[np.cos(theta), -np.sin(theta), x],
                     [np.sin(theta), np.cos(theta), y],
                     [0, 0, 1]])


def plot_rospo(x: np.ndarray,
               axis: plt.Axes = None,
               Fdes: np.ndarray = None,
               Pdes: np.ndarray = None):
    pos = extract_position(x)
    M = affine_transformation_matrix(pos)
    baseline = np.array([[dimx, dimy, 1], [dimx, -dimy, 1],
                         [-dimx, -dimy, 1], [-dimx, dimy, 1],
                         [dimx, dimy, 1]]).T
    robot_base = M @ baseline

    if axis is None:
        axis = plt.gca()

    axis.plot(robot_base[0, :], robot_base[1, :], color="0.8")

    for Flaw, P in contact_pairs:
        F: np.ndarray = Flaw(x)
        if np.linalg.norm(F) < 1e-6:
            continue
        delta = F / max_overall_force * arrow_len
        P = M @ P
        axis.arrow(P[0], P[1], delta[0], delta[1],
                   color="red", head_width=0.01, head_length=0.03)

    for i, P in enumerate(turret_positions):
        Xturr = extract_turret_state(x, i)
        F = np.array([motor_force_mdl(Xturr)[0], 0])
        if np.linalg.norm(F) < 1e-6:
            continue
        Mturr = np.array([[np.cos(Xturr[2]), -np.sin(Xturr[2])],
                          [np.sin(Xturr[2]),  np.cos(Xturr[2])]])
        delta = Mturr @ F / max_overall_force * arrow_len
        deltamax = Mturr @ np.array([arrow_len * F_turr_max / max_overall_force, 0])
        P = M @ P
        axis.arrow(P[0], P[1], deltamax[0], deltamax[1],
                   color="0.95", head_width=0.01, head_length=0.03)
        axis.arrow(P[0], P[1], delta[0], delta[1],
                   color="green", head_width=0.01, head_length=0.03)
    Ftot = overall_force(x) / max_overall_force * arrow_len
    axis.arrow(x[0], x[1], Ftot[0], Ftot[1],
               color="blue", head_width=0.01, head_length=0.03)

    if Fdes is not None:
        Fdes = Fdes / max_overall_force * arrow_len
        axis.arrow(x[0], x[1], Fdes[0], Fdes[1],
                   color="brown", head_width=0.01, head_length=0.03)

    if Pdes is not None:
        Mdes = affine_transformation_matrix(Pdes)
        des_base = Mdes @ baseline
        axis.plot(des_base[0, :], des_base[1, :], color="0.8", linestyle="--")
