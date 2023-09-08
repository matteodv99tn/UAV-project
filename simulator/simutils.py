import numpy as np


def extract_position(x: np.ndarray) -> np.ndarray:
    return x[0:3]


def extract_velocity(x: np.ndarray) -> np.ndarray:
    return x[3:6]


def extract_turret_state(x: np.ndarray, i: int = 0) -> np.ndarray:
    return x[6 + i * 3:9 + i * 3]


def rotation_matrix_2d(theta: float) -> np.ndarray:
    return np.array([[np.cos(theta), -np.sin(theta)],
                     [np.sin(theta), np.cos(theta)]])
