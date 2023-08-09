#include "roboptim/core/fwd.hh"
#include "include/objective.hpp"

using roboptim::GenericFunction;

int run_test() {

    typedef roboptim::Solver<roboptim::EigenMatrixDense> solver_t;

    boost::shared_ptr<GenericFunction> f(new GenericFunction());


    return 0;
}


int main(void)  {

    return 0;
}
