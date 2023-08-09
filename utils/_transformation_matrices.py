import numpy as np


def rotation_matrix(theta: float):
    """ Homogeneous rotation matrix along the z axis

    theta expressed in radians
    """
    return np.array([[np.cos(theta), -np.sin(theta), 0],
                     [np.sin(theta), np.cos(theta), 0],
                     [0, 0, 1]])


def translation_matrix(x: float | np.ndarray, y: float | None = None):
    """ Create a translation matrix

    If x is a numpy vector, then it is assumed to be the translation and y is
    disregarded.
    Otherwise x and y are the translational components
    """

    if isinstance(x, np.ndarray):
        X = x[0]
        Y = x[1]
    else:
        X = x
        Y = y
    return np.array([[1, 0, X],
                     [0, 1, Y],
                     [0, 0, 1]])
