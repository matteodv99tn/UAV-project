import numpy as np
from abc import ABC, abstractmethod


class Model(ABC):
    """ Model abstrac class

    This will define the common methods that each instance of Model will have.
    """

    @abstractmethod
    def f(self, x: np.ndarray,
          u: np.ndarray | None = None,
          *args, **kwargs) -> np.ndarray:
        """
        Function of the differental equation

        The function returns the value of the ODE of the form
            x' = f(x, u)


        Parameters
        ----------
        x : np.ndarray
            state of the dynamic system.
        u : np.ndarray | None
            inpupt of the dynamic system; optional.

        Returns
        -------
        np.ndarray
            function evaluated for the given input
        """
        pass

    @abstractmethod
    def f_x(self, x: np.ndarray,
            u: np.ndarray | None = None,
            *args, **kwargs) -> np.ndarray:
        """
        Jacobian of the function of the differental equation

        Given an ODE of the form
            x' = f(x, u)
        this function returns the Jacobian of f with respect to x.

        Parameters
        ----------
        x : np.ndarray
            state of the dynamic system.
        u : np.ndarray | None
            inpupt of the dynamic system; optional.

        Returns
        -------
        np.ndarray
            Jacobian of f with respect to x
        """
        pass
