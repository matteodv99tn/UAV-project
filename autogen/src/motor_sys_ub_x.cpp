#include <maple_codegen/mapledefines.hpp>
#include <maple_codegen/motor_sys_ub_x.hpp>
#include <maple_codegen/motor_sys_ub_x_params.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector motor_sys_ub_x() {

  Vector func = Vector::Zero(2);

  const float_t tmp__1 = Omega__ref;
  const float_t tmp__2 = i__max;

  func(0) = tmp__1;
  func(1) = tmp__2;

  return func;
}
