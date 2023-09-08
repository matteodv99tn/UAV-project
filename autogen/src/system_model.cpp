#include <maple_codegen/mapledefines.hpp>
#include <maple_codegen/system_model.hpp>
#include <maple_codegen/system_model_params.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector system_model(VectorRef x, VectorRef u) {
  const float_t x__body = x[0];
  const float_t y__body = x[1];
  const float_t theta__body = x[2];
  const float_t vx__body = x[3];
  const float_t vy__body = x[4];
  const float_t omega__body = x[5];
  const float_t Omega__1 = x[6];
  const float_t ii__1 = x[7];
  const float_t phi__1 = x[8];
  const float_t Omega__2 = x[9];
  const float_t ii__2 = x[10];
  const float_t phi__2 = x[11];
  const float_t Omega__3 = x[12];
  const float_t ii__3 = x[13];
  const float_t phi__3 = x[14];
  const float_t Omega__4 = x[15];
  const float_t ii__4 = x[16];
  const float_t phi__4 = x[17];
  const float_t Fx__body = u[0];
  const float_t Fy__body = u[1];
  const float_t Tz__body = u[2];
  const float_t v__1 = u[3];
  const float_t delta__1 = u[4];
  const float_t v__2 = u[5];
  const float_t delta__2 = u[6];
  const float_t v__3 = u[7];
  const float_t delta__3 = u[8];
  const float_t v__4 = u[9];
  const float_t delta__4 = u[10];

  Vector func = Vector::Zero(18);

  const float_t tmp__1 = vx__body;
  const float_t tmp__2 = vy__body;
  const float_t tmp__3 = omega__body;
  const float_t t1 = 0.1e1 / m__body;
  const float_t tmp__4 = Fx__body * t1;
  const float_t tmp__5 = Fy__body * t1;
  const float_t tmp__6 = 0.1e1 / J__body * Tz__body;
  const float_t t3 = Omega__1 * Omega__1;
  const float_t t7 = 0.1e1 / J;
  const float_t t9 = 0.1e1 / kv;
  const float_t tmp__7 = t9 * t7 * (-kv * t3 * k__tau + ii__1);
  const float_t t14 = 0.1e1 / L;
  const float_t tmp__8 = t9 * t14 * ((-R * ii__1 + v__1) * kv - Omega__1);
  const float_t tmp__9 = delta__1;
  const float_t t16 = Omega__2 * Omega__2;
  const float_t tmp__10 = t9 * t7 * (-kv * t16 * k__tau + ii__2);
  const float_t tmp__11 = t9 * t14 * ((-R * ii__2 + v__2) * kv - Omega__2);
  const float_t tmp__12 = delta__2;
  const float_t t26 = Omega__3 * Omega__3;
  const float_t tmp__13 = t9 * t7 * (-kv * t26 * k__tau + ii__3);
  const float_t tmp__14 = t9 * t14 * ((-R * ii__3 + v__3) * kv - Omega__3);
  const float_t tmp__15 = delta__3;
  const float_t t36 = Omega__4 * Omega__4;
  const float_t tmp__16 = t9 * t7 * (-kv * t36 * k__tau + ii__4);
  const float_t tmp__17 = t9 * t14 * ((-R * ii__4 + v__4) * kv - Omega__4);
  const float_t tmp__18 = delta__4;

  func(0) = tmp__1;
  func(1) = tmp__2;
  func(2) = tmp__3;
  func(3) = tmp__4;
  func(4) = tmp__5;
  func(5) = tmp__6;
  func(6) = tmp__7;
  func(7) = tmp__8;
  func(8) = tmp__9;
  func(9) = tmp__10;
  func(10) = tmp__11;
  func(11) = tmp__12;
  func(12) = tmp__13;
  func(13) = tmp__14;
  func(14) = tmp__15;
  func(15) = tmp__16;
  func(16) = tmp__17;
  func(17) = tmp__18;

  return func;
}

Matrix system_model_dx(VectorRef x, VectorRef u) {
  const float_t x__body = x[0];
  const float_t y__body = x[1];
  const float_t theta__body = x[2];
  const float_t vx__body = x[3];
  const float_t vy__body = x[4];
  const float_t omega__body = x[5];
  const float_t Omega__1 = x[6];
  const float_t ii__1 = x[7];
  const float_t phi__1 = x[8];
  const float_t Omega__2 = x[9];
  const float_t ii__2 = x[10];
  const float_t phi__2 = x[11];
  const float_t Omega__3 = x[12];
  const float_t ii__3 = x[13];
  const float_t phi__3 = x[14];
  const float_t Omega__4 = x[15];
  const float_t ii__4 = x[16];
  const float_t phi__4 = x[17];
  const float_t Fx__body = u[0];
  const float_t Fy__body = u[1];
  const float_t Tz__body = u[2];
  const float_t v__1 = u[3];
  const float_t delta__1 = u[4];
  const float_t v__2 = u[5];
  const float_t delta__2 = u[6];
  const float_t v__3 = u[7];
  const float_t delta__3 = u[8];
  const float_t v__4 = u[9];
  const float_t delta__4 = u[10];

  Vector func_dx = Vector::Zero(1);

  return func_dx;
}

Matrix system_model_du(VectorRef x, VectorRef u) {
  const float_t x__body = x[0];
  const float_t y__body = x[1];
  const float_t theta__body = x[2];
  const float_t vx__body = x[3];
  const float_t vy__body = x[4];
  const float_t omega__body = x[5];
  const float_t Omega__1 = x[6];
  const float_t ii__1 = x[7];
  const float_t phi__1 = x[8];
  const float_t Omega__2 = x[9];
  const float_t ii__2 = x[10];
  const float_t phi__2 = x[11];
  const float_t Omega__3 = x[12];
  const float_t ii__3 = x[13];
  const float_t phi__3 = x[14];
  const float_t Omega__4 = x[15];
  const float_t ii__4 = x[16];
  const float_t phi__4 = x[17];
  const float_t Fx__body = u[0];
  const float_t Fy__body = u[1];
  const float_t Tz__body = u[2];
  const float_t v__1 = u[3];
  const float_t delta__1 = u[4];
  const float_t v__2 = u[5];
  const float_t delta__2 = u[6];
  const float_t v__3 = u[7];
  const float_t delta__3 = u[8];
  const float_t v__4 = u[9];
  const float_t delta__4 = u[10];

  Vector func_du = Vector::Zero(1);

  return func_du;
}
