import numpy as np


class Turret():
    """ Turret class

    The state `x` of the model is regared as a 3-dimensional vector with
    components
        - Omega: angular speed of the turret;
        - I: current of the circuit;
        - phi: angle of the turret in it's local reference frame.
    Inputs are instead:
        - v: voltage applied to the circuit;
        - d_phi: angular speed of the turret in it's local reference frame.

    Properties
    ----------
    R: float
        resistance of the circuit
    L: float
        inductance of the circuit
    kt: float
        motor torque coefficient
    kv: float
        motor velocity constant
    J: float
        moment of inertia of the propeller
    """
    R:      float
    L:      float
    kv:     float
    kt:     float
    kl:     float
    J:      float

    def __init__(self, parameters):
        """ Turret constructor """
        self.R = parameters['R']
        self.L = parameters['L']
        self.kt = parameters['kt']
        self.kv = parameters['kv']
        self.kl = parameters['kl']
        self.J = parameters['J']

    def f(self, x: np.ndarray,
          u: np.ndarray):
        """ System's dynamic """
        dx = np.zeros(3)

        Omega = x[0]
        ii = x[1]
        v = u[0]
        d_phi = u[1]

        dx[0] = (ii/self.kv - self.kt*Omega**2) / self.J
        dx[1] = (v - self.R*ii - Omega/self.kv) / self.L
        dx[2] = d_phi

        return dx

    def f_x(self, x: np.ndarray,
            u: np.ndarray):
        """ Jacobian of the system's dynamic w.r.t. the state """
        df_dx = np.zeros((3, 3))

        Omega = x[0]

        df_dx[0, 0] = -2 * self.kt * Omega / self.J
        df_dx[0, 1] = 1 / (self.J*self.kv)
        df_dx[1, 0] = -1 / (self.kv*self.L)
        df_dx[1, 1] = -self.R / self.L

        return df_dx

    def f_u(self, x: np.ndarray,
            u: np.ndarray):
        df_du = np.zeros((3, 2))

        df_du[1, 0] = 1 / self.L
        df_du[2, 1] = 1

    def force_vector(self, x: np.ndarray):
        """ Force vector of the system """
        f = np.zeros(3)
        mod = self.kl * x[0]**2
        phi = x[2]
        f[1] = mod * np.cos(phi)
        f[2] = mod * np.sin(phi)
        return f
