import numpy as np


from multibody import translation_matrix




class System:

    N_turrets: int
    pos_turrets: list(np.ndarray)

    def __init__(self,
                 N_turrets: int = 3):
        self.N_turrets = N_turrets
        self.pos_turrets = list()

    def set_turret_pos(self, *args):
        if len(args) != self.N_turrets:
            raise ValueError("Number of turrets does not match")
        for arg in args:
            self.pos_turrets.append(np.array(arg))

    def build_force(self, x: np.ndarray) -> tuple(np.ndarray, float):
        """ Computes force and torque applied on the COM """
        F = np.zeros(3)
        for i in range(self.N_turrets):
            turr_pos = self.pos_turrets[i]
            turr_RF =translation_matrix(turr_pos[0], turr_pos[1])
            F += turret_Force_vector(x[3*i:3*(i+1)])




def system_f(x: np.ndarray,
             u: np.ndarray,
             N_turrets: int,
             with_jacobians: bool = False) -> np.ndarray:
    dx = np.zeros(x.shape)

    # --- Step 1: build the applied forces and torques
    F = np.zeros(2)
    for i in range(self.N_turrets):
        turr_pos = self.pos_turrets[i]
        F += turret_Force_vector(x[3*i:3*(i+1)])



    return dx
