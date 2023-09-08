#include <maple_codegen/mapledefines.hpp>
#include <maple_codegen/motor_force_mdl.hpp>
#include <maple_codegen/motor_force_mdl_params.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector motor_force_mdl(VectorRef x) {
  const float_t Omega = x[0];
  const float_t ii = x[1];

  Vector func = Vector::Zero(1);

  const float_t t1 = Omega * Omega;
  const float_t tmp__1 = t1 * k__l;

  func(0) = tmp__1;

  return func;
}

Matrix motor_force_mdl_dx(VectorRef x) {
  const float_t Omega = x[0];
  const float_t ii = x[1];

  Matrix func_dx = Matrix::Zero(1, 2);

  const float_t tmp__1_1 = 2 * k__l * Omega;

  func_dx(0, 0) = tmp__1_1;

  return func_dx;
}
