#include <maple_codegen/mapledefines.hpp>
#include <maple_codegen/motor_sys_ub_u.hpp>
#include <maple_codegen/motor_sys_ub_u_params.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector motor_sys_ub_u() {

  Vector func = Vector::Zero(1);

  const float_t tmp__1 = v__ref;

  func(0) = tmp__1;

  return func;
}
