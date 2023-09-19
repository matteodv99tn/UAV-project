import numpy as np
import matplotlib.pyplot as plt
import sys
import os

from simulator.setup import p_ref, t
from os.path import join
from simulator.simutils import extract_turret_state
from autogen.lib.motor_force_mdl import motor_force_mdl
from autogen.lib.rospo_com_force import rospo_com_force

root_dir = os.path.dirname(os.path.abspath(__file__))
img_dir = os.path.join(root_dir, "report", "Images")

X_hist = np.load("X_hist.npy")
U_hist = np.load("U_hist.npy")
Uvc_hist = np.load("Uvc_hist.npy")

plt.figure(figsize=(7, 4))
plt.plot(p_ref[0, :], p_ref[1, :], "--", label="reference")
plt.plot(X_hist[:, 0], X_hist[:, 1], label="actual")
plt.gca().set_xlim([-1.1, 1.1])
plt.gca().set_ylim([-1.1, 1.1])
plt.xlabel("x [m]")
plt.ylabel("y [m]")
plt.gca().set_aspect("equal")
plt.grid(linestyle="--")
plt.savefig(join(img_dir, "path.eps"), bbox_inches="tight")

plt.figure(figsize=(7, 3))
plt.plot(t, p_ref[0, :], "--", label="x reference")
plt.plot(t, p_ref[1, :], "--", label="y reference")
plt.plot(t, p_ref[2, :], "--", label="psi reference")
plt.plot(t, X_hist[:, 0], label="x actual")
plt.plot(t, X_hist[:, 1], label="y actual")
plt.plot(t, X_hist[:, 2], label="psi actual")
plt.legend(loc="lower right")
plt.xlabel("t [s]")
plt.ylabel("x/y [m]")
plt.grid(linestyle="--")
plt.savefig(join(img_dir, "delta.eps"), bbox_inches="tight")

plt.figure(figsize=(7, 1.5))
dx = X_hist[:, 0] - p_ref[0, :]
dy = X_hist[:, 1] - p_ref[1, :]
err = np.sqrt(dx ** 2 + dy ** 2)
plt.plot(t, err, label="x reference")
plt.xlabel("t [s]")
plt.ylabel("error [m]")
plt.grid(linestyle="--")
plt.savefig(join(img_dir, "error.eps"), bbox_inches="tight")


Ftrue = np.zeros(Uvc_hist.shape)
for i in range(len(t)):
    x_turrets = [extract_turret_state(X_hist[i, :].copy(), j) for j in range(4)]
    F_turrets = [motor_force_mdl(X) for X in x_turrets]
    X = np.array([[F_turrets[i][0], x_turrets[i][-1]] for i in range(4)])\
          .flatten()
    Ftrue[i, :] = rospo_com_force(X)

plt.figure(figsize=(7, 1.5))
plt.plot(t, Uvc_hist[:, 0], "--", label="reference")
plt.plot(t, Ftrue[:, 0], label="actual")
plt.xlabel("t [s]")
plt.ylabel("Fx [N]")
plt.grid(linestyle="--")
plt.savefig(join(img_dir, "force-1.eps"), bbox_inches="tight")

plt.figure(figsize=(7, 1.5))
plt.plot(t, Uvc_hist[:, 1], "--", label="reference")
plt.plot(t, Ftrue[:, 1], label="actual")
plt.xlabel("t [s]")
plt.ylabel("Fy [N]")
plt.grid(linestyle="--")
plt.savefig(join(img_dir, "force-2.eps"), bbox_inches="tight")

plt.figure(figsize=(7, 1.5))
plt.plot(t, Uvc_hist[:, 2], "--", label="reference")
plt.plot(t, Ftrue[:, 2], label="actual")
plt.xlabel("t [s]")
plt.ylabel("Tz [N]")
plt.grid(linestyle="--")
plt.savefig(join(img_dir, "force-3.eps"), bbox_inches="tight")


plt.show()
