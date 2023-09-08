#include <maple_codegen/mapledefines.hpp>
#include <maple_codegen/motor_sys_lb_x.hpp>
#include <maple_codegen/motor_sys_lb_x_params.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector motor_sys_lb_x() {

  Vector func = Vector::Zero(2);

  const float_t tmp__2 = i__min;

  func(1) = tmp__2;

  return func;
}
