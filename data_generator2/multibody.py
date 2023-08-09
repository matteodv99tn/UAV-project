import numpy as np


def rotation_matrix(angle: float) -> np.ndarray:
    return np.array([[np.cos(angle), -np.sin(angle), 0],
                     [np.sin(angle),  np.cos(angle), 0],
                     [0,              0,             1]])


def translation_matrix(x: float, y: float) -> np.ndarray:
    return np.array([[1, 0, x],
                     [0, 1, y],
                     [0, 0, 1]])


def rototranslation_matrix(x: float, y: float, angle: float) -> np.ndarray:
    return np.dot(translation_matrix(x, y), rotation_matrix(angle))
