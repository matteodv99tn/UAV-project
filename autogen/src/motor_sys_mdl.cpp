#include <maple_codegen/mapledefines.hpp>
#include <maple_codegen/motor_sys_mdl.hpp>
#include <maple_codegen/motor_sys_mdl_params.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector motor_sys_mdl(VectorRef x, VectorRef u) {
  const float_t Omega = x[0];
  const float_t ii = x[1];
  const float_t v = u[0];

  Vector func = Vector::Zero(2);

  const float_t t1 = Omega * Omega;
  const float_t t7 = 0.1e1 / kv;
  const float_t tmp__1 = t7 / J * (-kv * k__tau * t1 + ii);
  const float_t tmp__2 = t7 / L * ((-R * ii + v) * kv - Omega);

  func(0) = tmp__1;
  func(1) = tmp__2;

  return func;
}

Matrix motor_sys_mdl_dx(VectorRef x, VectorRef u) {
  const float_t Omega = x[0];
  const float_t ii = x[1];
  const float_t v = u[0];

  Matrix func_dx = Matrix::Zero(2, 2);

  const float_t t1 = 0.1e1 / J;
  const float_t tmp__1_1 = -2 * k__tau * Omega * t1;
  const float_t t5 = 0.1e1 / kv;
  const float_t tmp__1_2 = t5 * t1;
  const float_t t6 = 0.1e1 / L;
  const float_t tmp__2_1 = -t5 * t6;
  const float_t tmp__2_2 = -R * t6;

  func_dx(0, 0) = tmp__1_1;
  func_dx(0, 1) = tmp__1_2;
  func_dx(1, 0) = tmp__2_1;
  func_dx(1, 1) = tmp__2_2;

  return func_dx;
}

Matrix motor_sys_mdl_du(VectorRef x, VectorRef u) {
  const float_t Omega = x[0];
  const float_t ii = x[1];
  const float_t v = u[0];

  Matrix func_du = Matrix::Zero(2, 1);

  const float_t tmp__2_1 = 0.1e1 / L;

  func_du(1, 0) = tmp__2_1;

  return func_du;
}
