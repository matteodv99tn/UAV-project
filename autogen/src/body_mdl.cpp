#include <maple_codegen/body_mdl.hpp>
#include <maple_codegen/body_mdl_params.hpp>
#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector body_mdl(VectorRef x, VectorRef u) {
  const float_t x__body = x[0];
  const float_t y__body = x[1];
  const float_t theta__body = x[2];
  const float_t vx__body = x[3];
  const float_t vy__body = x[4];
  const float_t omega__body = x[5];
  const float_t Fx__body = u[0];
  const float_t Fy__body = u[1];
  const float_t Tz__body = u[2];

  Vector func = Vector::Zero(6);

  const float_t tmp__1 = vx__body;
  const float_t tmp__2 = vy__body;
  const float_t tmp__3 = omega__body;
  const float_t t1 = 0.1e1 / m__body;
  const float_t tmp__4 = Fx__body * t1;
  const float_t tmp__5 = Fy__body * t1;
  const float_t tmp__6 = 0.1e1 / J__body * Tz__body;

  func(0) = tmp__1;
  func(1) = tmp__2;
  func(2) = tmp__3;
  func(3) = tmp__4;
  func(4) = tmp__5;
  func(5) = tmp__6;

  return func;
}

Matrix body_mdl_dx(VectorRef x, VectorRef u) {
  const float_t x__body = x[0];
  const float_t y__body = x[1];
  const float_t theta__body = x[2];
  const float_t vx__body = x[3];
  const float_t vy__body = x[4];
  const float_t omega__body = x[5];
  const float_t Fx__body = u[0];
  const float_t Fy__body = u[1];
  const float_t Tz__body = u[2];

  Matrix func_dx = Matrix::Zero(6, 6);

  const float_t tmp__1_4 = 1;
  const float_t tmp__2_5 = 1;
  const float_t tmp__3_6 = 1;

  func_dx(0, 3) = tmp__1_4;
  func_dx(1, 4) = tmp__2_5;
  func_dx(2, 5) = tmp__3_6;

  return func_dx;
}

Matrix body_mdl_du(VectorRef x, VectorRef u) {
  const float_t x__body = x[0];
  const float_t y__body = x[1];
  const float_t theta__body = x[2];
  const float_t vx__body = x[3];
  const float_t vy__body = x[4];
  const float_t omega__body = x[5];
  const float_t Fx__body = u[0];
  const float_t Fy__body = u[1];
  const float_t Tz__body = u[2];

  Matrix func_du = Matrix::Zero(6, 3);

  const float_t tmp__4_1 = 0.1e1 / m__body;
  const float_t tmp__5_2 = tmp__4_1;
  const float_t tmp__6_3 = 0.1e1 / J__body;

  func_du(3, 0) = tmp__4_1;
  func_du(4, 1) = tmp__5_2;
  func_du(5, 2) = tmp__6_3;

  return func_du;
}
