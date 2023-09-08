#include <maple_codegen/force_contact4.hpp>
#include <maple_codegen/force_contact4_params.hpp>
#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector force_contact4(VectorRef x) {
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

  Vector func = Vector::Zero(3);

  const float_t t1 = pos__x__contact * vy__body;
  const float_t t2 = pos__y__contact * vx__body;
  const float_t t5 = cos(theta__body);
  const float_t t8 = pos__x__contact * vx__body;
  const float_t t9 = pos__y__contact * vy__body;
  const float_t t12 = sin(theta__body);
  const float_t t15 = omega__body * omega__body;
  const float_t t16 = pos__x__contact * pos__x__contact;
  const float_t t18 = pos__y__contact * pos__y__contact;
  const float_t t20 = vx__body * vx__body;
  const float_t t21 = vy__body * vy__body;
  const float_t t23 = sqrt(2 * t5 * (-t1 + t2) * omega__body +
                           2 * t12 * (t8 + t9) * omega__body + t16 * t15 +
                           t18 * t15 + t20 + t21);
  const float_t t25 = tanh(t23 * gamma__5);
  const float_t t26 = t25 * gamma__4;
  const float_t t27 = t12 * omega__body;
  const float_t t29 = t5 * omega__body;
  const float_t t42 = t16 + t18;
  const float_t t45 = sqrt(t5 * omega__body * (-0.2e1 * t1 + 0.2e1 * t2) +
                           t12 * omega__body * (0.2e1 * t8 + 0.2e1 * t9) +
                           t15 * t42 + t20 + t21);
  const float_t t47 = 0.1e1 / (0.1e-3 + t45);
  const float_t tmp__1 =
      t47 * (pos__x__contact * t27 + pos__y__contact * t29 + vx__body) * t26;
  const float_t tmp__2 =
      t47 * (pos__y__contact * t27 - pos__x__contact * t29 + vy__body) * t26;
  const float_t tmp__3 =
      t47 * t25 * gamma__4 * (t5 * t42 * omega__body - t1 + t2);

  func(0) = tmp__1;
  func(1) = tmp__2;
  func(2) = tmp__3;

  return func;
}

Matrix force_contact4_dx(VectorRef x) {
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

  Vector func_dx = Vector::Zero(1);

  return func_dx;
}
