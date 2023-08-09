#include <include/objective.hpp>


Objective::Objective() :
        roboptim::TwiceDifferentiableFunction(4, 1, "x0 * x3 * (x0 + x1 + x2) + x2") {};


void Objective::impl_compute(
        roboptim::result_ref result,
        roboptim::const_argument_ref x) const {
    result[0] = x[0] * x[3] * (x[0] + x[1] + x[2]) + x[2];
}


void Objective::impl_gradient(
        roboptim::gradient_ref grad,
        roboptim::const_argument_ref x,
        roboptim::size_type) const {
    grad << x[0]*x[3] + x[3]*(x[0] + x[1] + x[2]),
            x[0]*x[3],
            x[0]*x[3] + 1,
            x[0]*(x[0] + x[1] + x[2]);
}


void Objective::impl_hessian(
        roboptim::hessian_ref hess,
        roboptim::const_argument_ref x,
        roboptim::size_type) const {
    hess << 2*x[3],          x[3], x[3], 2*x[0]+x[1]+x[2],
            x[3],            0.,   0.,   x[0],
            x[3],            0. ,  0.,   x[1],
            2*x[0]+x[1]+x[2], x[0], x[0], 0.;
}
