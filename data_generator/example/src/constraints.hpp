#include <constraints.hpp>

G0::G0() :
        TwiceDifferentiableFunction (4, 1, "x0*x1*x2*x3") {}


void G0::impl_compute(
        roboptim::result_ref res,
        roboptim::const_argument_ref x) const {
    res[0] = x[0] * x[1] * x[2] * x[3];
}



