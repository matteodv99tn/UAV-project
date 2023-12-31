import numpy as np
import matplotlib.pyplot as plt
import os

from data_preparation import normalize_x_data, denormalize_y_data
from neuralnetworks import load_model
from glob import glob
from config import \
        force, motor_mdl, \
        MODEL_DIR, \
        F_lb, F_ub, \
        dt

from utils.ode_integration import RK4


if __name__ == "__main__":
    models_list = glob(os.path.join(MODEL_DIR, "*.keras"))
    print("Available models:")

    t = np.arange(0, 1, dt)
    N = t.size
    dF = F_ub - F_lb
    F_refs = F_lb + 0.5*dF + 0.3*dF*np.sin(2*np.pi*t)
    plt.figure()
    plt.plot(t, F_refs, label="reference")

    for model_filename in models_list:
        print(f"Processing {model_filename}")
        nn = load_model(os.path.join(MODEL_DIR, model_filename))
        print(nn)

        Xhist = np.zeros((N, 2))
        Fhist = np.zeros(N)

        for i in range(N-1):
            Fhist[i] = force(Xhist[i, :])
            nn_input = np.concatenate((Xhist[i, :], np.array([F_refs[i+1]]))) \
                         .reshape((1, -1))
            u_applied = nn.model.predict(normalize_x_data(nn_input), verbose=0)
            u_denorm = u_applied.astype(np.float64).flatten() * 14.8
            tmp, _ = RK4.integrate(motor_mdl, Xhist[i, :], u_denorm, dt, 3)
            Xhist[i+1, :] = tmp

        plt.plot(t, Fhist, label=os.path.basename(model_filename))

    plt.legend()
    plt.show()
