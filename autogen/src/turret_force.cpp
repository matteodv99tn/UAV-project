#include <maple_codegen/mapledefines.hpp>
#include <maple_codegen/turret_force.hpp>
#include <maple_codegen/turret_force_params.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector turret_force(VectorRef x) {
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

  const float_t t1 = cos(phi__1);
  const float_t t2 = Omega__1 * Omega__1;
  const float_t t3 = t2 * t1;
  const float_t t4 = cos(phi__2);
  const float_t t5 = Omega__2 * Omega__2;
  const float_t t6 = t5 * t4;
  const float_t t7 = cos(phi__3);
  const float_t t8 = Omega__3 * Omega__3;
  const float_t t9 = t8 * t7;
  const float_t t10 = cos(phi__4);
  const float_t t11 = Omega__4 * Omega__4;
  const float_t t12 = t11 * t10;
  const float_t t13 = t3 + t6 + t9 + t12;
  const float_t t14 = cos(theta__body);
  const float_t t16 = sin(theta__body);
  const float_t t17 = sin(phi__1);
  const float_t t18 = t2 * t17;
  const float_t t19 = sin(phi__2);
  const float_t t20 = t5 * t19;
  const float_t t21 = sin(phi__3);
  const float_t t22 = t8 * t21;
  const float_t t23 = sin(phi__4);
  const float_t t24 = t11 * t23;
  const float_t t25 = t18 + t20 + t22 + t24;
  const float_t tmp__1 = k__l * (t14 * t13 - t25 * t16);
  const float_t tmp__2 = k__l * (t13 * t16 + t14 * t25);
  const float_t tmp__3 =
      k__l * (-pos__y__turr * t3 + pos__y__turr * t6 - pos__y__turr * t9 +
              pos__y__turr * t12 + (t18 + t20 - t22 - t24) * pos__x__turr);

  func(0) = tmp__1;
  func(1) = tmp__2;
  func(2) = tmp__3;

  return func;
}

Matrix turret_force_dx(VectorRef x) {
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
