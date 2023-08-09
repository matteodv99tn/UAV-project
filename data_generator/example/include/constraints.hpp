#ifndef CONSTRAINTS_HPP__
#define CONSTRAINTS_HPP__

#include "roboptim/core/fwd.hh"
#include <roboptim/core/twice-differentiable-function.hh>

struct G0 : public roboptim::TwiceDifferentiableFunction {

    G0();

    void impl_compute(roboptim::result_ref res, roboptim::const_argument_ref x) const;
    void impl_gradient(roboptim::gradient_ref grad, roboptim::const_argument_ref x, size_t functionId = 0) const;
    void impl_hessian(roboptim::hessian_ref hess, roboptim::const_argument_ref x, size_t functionId = 0) const;
}

#endif // CONSTRAINTS_HPP__
