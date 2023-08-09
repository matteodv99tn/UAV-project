#ifndef OBJECTIVE_HPP__
#define OBJECTIVE_HPP__

#include <roboptim/core/twice-differentiable-function.hh>
#include <roboptim/core/io.hh>
#include <boost/shared_ptr.hpp>
#include <roboptim/core/solver.hh>
#include <roboptim/core/solver-factory.hh>

#include <include/defines.hpp>

struct Objective : public roboptim::TwiceDifferentiableFunction {

    Objective();

    void operator()(Vector1_t& result, const Vector4_t& x) const;
    Vector4_t gradient(const Vector4_t&  x) const;
    Matrix4_t hessian(const Vector4_t& x) const;





};


#endif // OBJECTIVE_HPP__
