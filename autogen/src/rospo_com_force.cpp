#include <maple_codegen/mapledefines.hpp>
#include <maple_codegen/rospo_com_force.hpp>
#include <maple_codegen/rospo_com_force_params.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector rospo_com_force(VectorRef x) {
  const float_t F__1 = x[0];
  const float_t phi__1 = x[1];
  const float_t F__2 = x[2];
  const float_t phi__2 = x[3];
  const float_t F__3 = x[4];
  const float_t phi__3 = x[5];
  const float_t F__4 = x[6];
  const float_t phi__4 = x[7];

  Vector func = Vector::Zero(3);

  const float_t t1 = cos(phi__1);
  const float_t t3 = cos(phi__2);
  const float_t t5 = cos(phi__3);
  const float_t t7 = cos(phi__4);
  const float_t tmp__1 = F__1 * t1 + F__2 * t3 + F__3 * t5 + F__4 * t7;
  const float_t t9 = sin(phi__1);
  const float_t t10 = F__1 * t9;
  const float_t t11 = sin(phi__2);
  const float_t t12 = F__2 * t11;
  const float_t t13 = sin(phi__3);
  const float_t t14 = F__3 * t13;
  const float_t t15 = sin(phi__4);
  const float_t t16 = F__4 * t15;
  const float_t tmp__2 = t10 + t12 + t14 + t16;
  const float_t tmp__3 = -F__1 * t1 * pos__y__turr + F__2 * t3 * pos__y__turr -
                         F__3 * t5 * pos__y__turr + F__4 * t7 * pos__y__turr +
                         (t10 + t12 - t14 - t16) * pos__x__turr;

  func(0) = tmp__1;
  func(1) = tmp__2;
  func(2) = tmp__3;

  return func;
}

Matrix rospo_com_force_dx(VectorRef x) {
  const float_t F__1 = x[0];
  const float_t phi__1 = x[1];
  const float_t F__2 = x[2];
  const float_t phi__2 = x[3];
  const float_t F__3 = x[4];
  const float_t phi__3 = x[5];
  const float_t F__4 = x[6];
  const float_t phi__4 = x[7];

  Matrix func_dx = Matrix::Zero(3, 8);

  const float_t tmp__1_1 = cos(phi__1);
  const float_t t1 = sin(phi__1);
  const float_t tmp__1_2 = -F__1 * t1;
  const float_t tmp__1_3 = cos(phi__2);
  const float_t t3 = sin(phi__2);
  const float_t tmp__1_4 = -F__2 * t3;
  const float_t tmp__1_5 = cos(phi__3);
  const float_t t5 = sin(phi__3);
  const float_t tmp__1_6 = -F__3 * t5;
  const float_t tmp__1_7 = cos(phi__4);
  const float_t t7 = sin(phi__4);
  const float_t tmp__1_8 = -F__4 * t7;
  const float_t tmp__2_1 = t1;
  const float_t tmp__2_2 = F__1 * tmp__1_1;
  const float_t tmp__2_3 = t3;
  const float_t tmp__2_4 = F__2 * tmp__1_3;
  const float_t tmp__2_5 = t5;
  const float_t tmp__2_6 = F__3 * tmp__1_5;
  const float_t tmp__2_7 = t7;
  const float_t tmp__2_8 = F__4 * tmp__1_7;
  const float_t tmp__3_1 = tmp__2_1 * pos__x__turr - tmp__1_1 * pos__y__turr;
  const float_t tmp__3_2 =
      (pos__x__turr * tmp__1_1 + pos__y__turr * tmp__2_1) * F__1;
  const float_t tmp__3_3 = tmp__2_3 * pos__x__turr + tmp__1_3 * pos__y__turr;
  const float_t tmp__3_4 =
      (pos__x__turr * tmp__1_3 - pos__y__turr * tmp__2_3) * F__2;
  const float_t tmp__3_5 = -tmp__2_5 * pos__x__turr - tmp__1_5 * pos__y__turr;
  const float_t tmp__3_6 =
      (-pos__x__turr * tmp__1_5 + pos__y__turr * tmp__2_5) * F__3;
  const float_t tmp__3_7 = -tmp__2_7 * pos__x__turr + tmp__1_7 * pos__y__turr;
  const float_t tmp__3_8 =
      -(pos__x__turr * tmp__1_7 + pos__y__turr * tmp__2_7) * F__4;

  func_dx(0, 0) = tmp__1_1;
  func_dx(0, 1) = tmp__1_2;
  func_dx(0, 2) = tmp__1_3;
  func_dx(0, 3) = tmp__1_4;
  func_dx(0, 4) = tmp__1_5;
  func_dx(0, 5) = tmp__1_6;
  func_dx(0, 6) = tmp__1_7;
  func_dx(0, 7) = tmp__1_8;
  func_dx(1, 0) = tmp__2_1;
  func_dx(1, 1) = tmp__2_2;
  func_dx(1, 2) = tmp__2_3;
  func_dx(1, 3) = tmp__2_4;
  func_dx(1, 4) = tmp__2_5;
  func_dx(1, 5) = tmp__2_6;
  func_dx(1, 6) = tmp__2_7;
  func_dx(1, 7) = tmp__2_8;
  func_dx(2, 0) = tmp__3_1;
  func_dx(2, 1) = tmp__3_2;
  func_dx(2, 2) = tmp__3_3;
  func_dx(2, 3) = tmp__3_4;
  func_dx(2, 4) = tmp__3_5;
  func_dx(2, 5) = tmp__3_6;
  func_dx(2, 6) = tmp__3_7;
  func_dx(2, 7) = tmp__3_8;

  return func_dx;
}
