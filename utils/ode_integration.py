import numpy as np


class Function:

    def __init__(self, fun, fun_dx, fun_du):
        self.fun = fun
        self.fun_dx = fun_dx
        self.fun_du = fun_du


class RKTableu:

    a:              np.ndarray = None
    b:              np.ndarray = None
    c:              np.ndarray = None
    order:          int = None
    is_explicit:    bool = None

    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c
        self.check_consistency()
        self.is_explicit = np.all(np.triu(self.a) == 0)

        if not self.is_explicit:
            raise NotImplementedError("Implicit RK methods "
                                      "are not implemented yet")

    def check_consistency(self):
        order = self.b.shape[0]
        assert self.a.shape == (order, order)
        assert self.c.shape[0] == order
        self.order = order

    def onestep_integrate(self,
                          function:     Function,
                          x0:           np.ndarray,
                          u:            np.ndarray,
                          dt:           float,
                          jacobian:     bool = False
                          ) -> np.ndarray:
        x_next = x0.copy()
        if jacobian:
            jac_dx = np.eye(x0.size)
            jac_du = np.zeros((x0.size, u.size))
        K = np.zeros((self.order, x0.size))

        for i in range(self.order):
            x = x0.copy()
            for j in range(i):
                x += dt * self.a[i, j] * K[j]

            K[i] = function.fun(x, u)
            x_next += dt * self.b[i] * K[i]
            if jacobian:
                jac_dx += dt * self.b[i] * function.fun_dx(x, u)
                jac_du += dt * self.b[i] * function.fun_du(x, u)

        if jacobian:
            return x_next, jac_dx, jac_du
        return x_next

    def integrate(self,
                  function:     Function,
                  x0:           np.ndarray,
                  u:            np.ndarray,
                  dt:           float,
                  N:            int,
                  jacobian:     bool = True
                  ) -> np.ndarray:
        x = x0.copy()
        dx_du = np.zeros((x0.size, u.size))
        h = float(dt / N)

        for i in range(N):
            if jacobian:
                x, jac_dx, jac_du = self.onestep_integrate(function, x, u, h,
                                                           jacobian=jacobian)
                dx_du += jac_dx @ dx_du + jac_du
            else:
                x = self.onestep_integrate(function, x, u, h,
                                           jacobian=jacobian)

        if jacobian:
            return x, dx_du
        return x


RK1 = RKTableu(a=np.array([[0]]).astype(np.float64),
               b=np.array([1]).astype(np.float64),
               c=np.array([0]).astype(np.float64))

RK4 = RKTableu(a=np.array([[0,   0,   0, 0],
                           [1/2, 0,   0, 0],
                           [0,   1/2, 0, 0],
                           [0,   0,   1, 0]]).astype(np.float64),
               b=np.array([1/6, 1/3, 1/3, 1/6]).astype(np.float64),
               c=np.array([0,   1/2, 1/2, 1]).astype(np.float64))
