#include <maple_codegen/mapledefines.hpp>
#include <maple_codegen/motor_force_ub.hpp>
#include <maple_codegen/motor_force_ub_params.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector motor_force_ub() {

  Vector func = Vector::Zero(1);

  const float_t t1 = Omega__ref * Omega__ref;
  const float_t tmp__1 = t1 * k__l;

  func(0) = tmp__1;

  return func;
}
