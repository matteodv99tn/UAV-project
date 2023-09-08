#include <maple_codegen/mapledefines.hpp>
#include <maple_codegen/motor_current.hpp>
#include <maple_codegen/motor_current_params.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector motor_current(VectorRef x) {
  const float_t Omega = x[0];

  Vector func = Vector::Zero(1);

  const float_t t13 = Omega * Omega;
  const float_t tmp__1 = kv * t13 * k__tau;

  func(0) = tmp__1;

  return func;
}

Matrix motor_current_dx(VectorRef x) {
  const float_t Omega = x[0];

  Matrix func_dx = Matrix::Zero(1, 1);

  const float_t tmp__1_1 = 2 * k__tau * Omega * kv;

  func_dx(0, 0) = tmp__1_1;

  return func_dx;
}
