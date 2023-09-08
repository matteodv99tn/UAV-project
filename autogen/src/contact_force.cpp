#include <maple_codegen/contact_force.hpp>
#include <maple_codegen/contact_force_params.hpp>
#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector contact_force(VectorRef x) {
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

  const float_t t1 = sin(theta__body);
  const float_t t2 = t1 * omega__body;
  const float_t t3 = pos__x__contact * t2;
  const float_t t4 = cos(theta__body);
  const float_t t5 = t4 * omega__body;
  const float_t t6 = pos__y__contact * t5;
  const float_t t7 = 0.1e1 * t6;
  const float_t t9 = vy__body * pos__x__contact;
  const float_t t10 = vx__body * pos__y__contact;
  const float_t t14 = 2 * t4 * (-t9 + t10) * omega__body;
  const float_t t15 = vx__body * pos__x__contact;
  const float_t t16 = vy__body * pos__y__contact;
  const float_t t20 = 2 * t1 * (t15 + t16) * omega__body;
  const float_t t21 = omega__body * omega__body;
  const float_t t22 = pos__x__contact * pos__x__contact;
  const float_t t23 = t22 * t21;
  const float_t t24 = pos__y__contact * pos__y__contact;
  const float_t t25 = t24 * t21;
  const float_t t26 = vx__body * vx__body;
  const float_t t27 = vy__body * vy__body;
  const float_t t29 = sqrt(t14 + t20 + t23 + t25 + t26 + t27);
  const float_t t31 = 0.1e-3 * vx__body;
  const float_t t32 = 0.1e-3 * t3;
  const float_t t33 = 0.1e-3 * t6;
  const float_t t38 = 2 * t4 * (t9 + t10) * omega__body;
  const float_t t42 = 2 * t1 * (t15 - t16) * omega__body;
  const float_t t44 = sqrt(t38 - t42 + t23 + t25 + t26 + t27);
  const float_t t47 = t29 * (t31 + t32 - t33);
  const float_t t48 = 0.1e-7 * vx__body;
  const float_t t49 = 0.1e-7 * t3;
  const float_t t50 = 0.1e-7 * t6;
  const float_t t53 = sqrt(-t14 - t20 + t23 + t25 + t26 + t27);
  const float_t t59 = 0.1e-11 * t6;
  const float_t t60 = 0.1e-11 * t3;
  const float_t t61 = 0.1e-11 * vx__body;
  const float_t t64 = sqrt(-t38 + t42 + t23 + t25 + t26 + t27);
  const float_t t66 = tanh(t64 * gamma__5);
  const float_t t68 = 0.1e1 * t3;
  const float_t t74 = t29 * (t31 - t32 - t33);
  const float_t t83 = tanh(t53 * gamma__5);
  const float_t t90 = t29 * (t31 - t32 + t33);
  const float_t t99 = tanh(t44 * gamma__5);
  const float_t t106 = t44 * (t31 + t32 + t33);
  const float_t t115 = tanh(t29 * gamma__5);
  const float_t t119 = 0.2000000000e1 * t9;
  const float_t t120 = 0.2000000000e1 * t10;
  const float_t t121 = -t119 + t120;
  const float_t t124 = 0.2000000000e1 * t15;
  const float_t t125 = 0.2000000000e1 * t16;
  const float_t t126 = t124 + t125;
  const float_t t129 = t22 + t24;
  const float_t t130 = t21 * t129;
  const float_t t132 = sqrt(t1 * omega__body * t126 + t4 * omega__body * t121 +
                            t130 + t26 + t27);
  const float_t t134 = 0.1e1 / (0.1e-3 + t132);
  const float_t t136 = -t119 - t120;
  const float_t t139 = t124 - t125;
  const float_t t143 = sqrt(t1 * omega__body * t139 + t4 * omega__body * t136 +
                            t130 + t26 + t27);
  const float_t t153 = sqrt(-t1 * omega__body * t139 - t4 * omega__body * t136 +
                            t130 + t26 + t27);
  const float_t t164 = sqrt(-t1 * omega__body * t126 - t4 * omega__body * t121 +
                            t130 + t26 + t27);
  const float_t t167 =
      0.1e1 / (0.1e-3 + t164) / (0.1e-3 + t153) / (0.1e-3 + t143);
  const float_t tmp__1 =
      t167 * t134 *
      (t66 * (t53 * (t44 * (t29 * (t3 - t7 + vx__body) + t31 + t32 - t33) +
                     t47 + t48 + t49 - t50) +
              t44 * (t47 + t48 + t49 - t50) + t29 * (t48 + t49 - t50) - t59 +
              t60 + t61) +
       t83 * (t64 * (t44 * (t29 * (-t7 - t68 + vx__body) + t31 - t32 - t33) +
                     t74 + t48 - t49 - t50) +
              t44 * (t74 + t48 - t49 - t50) + t29 * (t48 - t49 - t50) - t59 -
              t60 + t61) +
       t99 * (t64 * (t53 * (t29 * (-t68 + t6 + vx__body) + t31 - t32 + t33) +
                     t90 + t48 - t49 + t50) +
              t53 * (t90 + t48 - t49 + t50) + t29 * (t48 - t49 + t50) + t59 -
              t60 + t61) +
       t115 * (t64 * (t53 * (t44 * (t3 + t6 + vx__body) + t31 + t32 + t33) +
                      t106 + t48 + t49 + t50) +
               t53 * (t106 + t48 + t49 + t50) + t44 * (t48 + t49 + t50) + t59 +
               t60 + t61)) *
      gamma__4;
  const float_t t168 = pos__x__contact * t5;
  const float_t t169 = 0.1e1 * t168;
  const float_t t170 = pos__y__contact * t2;
  const float_t t171 = 0.1e1 * t170;
  const float_t t174 = 0.1e-3 * vy__body;
  const float_t t175 = 0.1e-3 * t168;
  const float_t t176 = 0.1e-3 * t170;
  const float_t t180 = t29 * (t174 - t175 - t176);
  const float_t t181 = 0.1e-7 * vy__body;
  const float_t t182 = 0.1e-7 * t168;
  const float_t t183 = 0.1e-7 * t170;
  const float_t t190 = 0.1e-11 * t170;
  const float_t t191 = 0.1e-11 * t168;
  const float_t t192 = 0.1e-11 * vy__body;
  const float_t t200 = t29 * (t174 - t176 + t175);
  const float_t t214 = t29 * (t174 + t175 + t176);
  const float_t t228 = t44 * (t174 - t175 + t176);
  const float_t tmp__2 =
      t167 * t134 *
      (t66 * (t53 * (t44 * (t29 * (-t169 - t171 + vy__body) + t174 - t175 -
                            t176) +
                     t180 + t181 - t182 - t183) +
              t44 * (t180 + t181 - t182 - t183) + t29 * (t181 - t182 - t183) -
              t190 - t191 + t192) +
       t83 *
           (t64 * (t44 * (t29 * (t168 - t171 + vy__body) + t174 - t176 + t175) +
                   t200 + t181 + t182 - t183) +
            t44 * (t200 + t181 + t182 - t183) + t29 * (t181 + t182 - t183) +
            t192 - t190 + t191) +
       t99 *
           (t64 * (t53 * (t29 * (t168 + t170 + vy__body) + t174 + t175 + t176) +
                   t214 + t181 + t182 + t183) +
            t53 * (t214 + t181 + t182 + t183) + t29 * (t181 + t182 + t183) +
            t192 + t190 + t191) +
       t115 * (t64 * (t53 * (t44 * (-t169 + t170 + vy__body) + t174 - t175 +
                             t176) +
                      t228 + t181 - t182 + t183) +
               t53 * (t228 + t181 - t182 + t183) + t44 * (t181 - t182 + t183) +
               t190 - t191 + t192)) *
      gamma__4;
  const float_t t240 = sqrt(t129);
  const float_t tmp__3 = (t66 + t115 + t83 + t99) * gamma__4 * t240;

  func(0) = tmp__1;
  func(1) = tmp__2;
  func(2) = tmp__3;

  return func;
}

Matrix contact_force_dx(VectorRef x) {
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
