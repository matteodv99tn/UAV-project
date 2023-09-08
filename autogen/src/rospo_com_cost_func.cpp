#include <maple_codegen/mapledefines.hpp>
#include <maple_codegen/rospo_com_cost_func.hpp>
#include <maple_codegen/rospo_com_cost_func_params.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector rospo_com_cost_func(VectorRef x, VectorRef u) {
  const float_t F__1 = x[0];
  const float_t phi__1 = x[1];
  const float_t F__2 = x[2];
  const float_t phi__2 = x[3];
  const float_t F__3 = x[4];
  const float_t phi__3 = x[5];
  const float_t F__4 = x[6];
  const float_t phi__4 = x[7];
  const float_t Fx__ref = x[8];
  const float_t Fy__ref = x[9];
  const float_t Tz__ref = x[10];
  const float_t dF__1 = u[0];
  const float_t dphi__1 = u[1];
  const float_t dF__2 = u[2];
  const float_t dphi__2 = u[3];
  const float_t dF__3 = u[4];
  const float_t dphi__3 = u[5];
  const float_t dF__4 = u[6];
  const float_t dphi__4 = u[7];

  Vector func = Vector::Zero(1);

  const float_t t2 = dt_controller * dphi__1 + phi__1;
  const float_t t3 = cos(t2);
  const float_t t4 = dF__1 * t3;
  const float_t t7 = dt_controller * dphi__2 + phi__2;
  const float_t t8 = cos(t7);
  const float_t t9 = dF__2 * t8;
  const float_t t12 = dt_controller * dphi__3 + phi__3;
  const float_t t13 = cos(t12);
  const float_t t14 = dF__3 * t13;
  const float_t t17 = dt_controller * dphi__4 + phi__4;
  const float_t t18 = cos(t17);
  const float_t t19 = dF__4 * t18;
  const float_t t21 = F__1 * t3;
  const float_t t22 = F__2 * t8;
  const float_t t23 = F__3 * t13;
  const float_t t24 = F__4 * t18;
  const float_t t26 =
      pow(dt_controller * t14 + dt_controller * t19 + dt_controller * t4 +
              dt_controller * t9 - Fx__ref + t21 + t22 + t23 + t24,
          2);
  const float_t t27 = sin(t2);
  const float_t t30 = sin(t7);
  const float_t t33 = sin(t12);
  const float_t t36 = sin(t17);
  const float_t t37 = t36 * dF__4;
  const float_t t39 = F__1 * t27;
  const float_t t40 = F__2 * t30;
  const float_t t41 = F__3 * t33;
  const float_t t42 = F__4 * t36;
  const float_t t44 =
      pow(dF__1 * dt_controller * t27 + dF__2 * dt_controller * t30 +
              dF__3 * dt_controller * t33 + dt_controller * t37 - Fy__ref +
              t39 + t40 + t41 + t42,
          2);
  const float_t t45 = dt_controller * pos__y__turr;
  const float_t t48 = dt_controller * pos__x__turr;
  const float_t t66 =
      t48 * t27 * dF__1 + t48 * t30 * dF__2 - t48 * t33 * dF__3 - t45 * t14 +
      t45 * t19 - pos__y__turr * t21 + pos__y__turr * t22 - pos__y__turr * t23 +
      pos__y__turr * t24 - t48 * t37 + pos__x__turr * t39 - t45 * t4 +
      pos__x__turr * t40 - pos__x__turr * t41 - pos__x__turr * t42 + t45 * t9 -
      Tz__ref;
  const float_t t67 = t66 * t66;
  const float_t t69 = dF__1 * dF__1;
  const float_t t71 = dphi__1 * dphi__1;
  const float_t t73 = dF__2 * dF__2;
  const float_t t75 = dphi__2 * dphi__2;
  const float_t t77 = dF__3 * dF__3;
  const float_t t79 = dphi__3 * dphi__3;
  const float_t t81 = dF__4 * dF__4;
  const float_t t83 = dphi__4 * dphi__4;
  const float_t tmp__1 = t26 + t44 + 20 * t67 + 0.1e0 * t69 + 0.1e0 * t71 +
                         0.1e0 * t73 + 0.1e0 * t75 + 0.1e0 * t77 + 0.1e0 * t79 +
                         0.1e0 * t81 + 0.1e0 * t83;

  func(0) = tmp__1;

  return func;
}

Matrix rospo_com_cost_func_dx(VectorRef x, VectorRef u) {
  const float_t F__1 = x[0];
  const float_t phi__1 = x[1];
  const float_t F__2 = x[2];
  const float_t phi__2 = x[3];
  const float_t F__3 = x[4];
  const float_t phi__3 = x[5];
  const float_t F__4 = x[6];
  const float_t phi__4 = x[7];
  const float_t Fx__ref = x[8];
  const float_t Fy__ref = x[9];
  const float_t Tz__ref = x[10];
  const float_t dF__1 = u[0];
  const float_t dphi__1 = u[1];
  const float_t dF__2 = u[2];
  const float_t dphi__2 = u[3];
  const float_t dF__3 = u[4];
  const float_t dphi__3 = u[5];
  const float_t dF__4 = u[6];
  const float_t dphi__4 = u[7];

  Matrix func_dx = Matrix::Zero(1, 11);

  const float_t t1 = pos__y__turr * pos__y__turr;
  const float_t t2 = t1 + 0.1e1 / 0.20e2;
  const float_t t4 = dF__1 * dt_controller + F__1;
  const float_t t5 = t4 * t2;
  const float_t t7 = dt_controller * dphi__1 + phi__1;
  const float_t t8 = cos(t7);
  const float_t t9 = t8 * t8;
  const float_t t12 = pos__x__turr * pos__y__turr;
  const float_t t13 = sin(t7);
  const float_t t14 = t13 * t4;
  const float_t t15 = t14 * t12;
  const float_t t18 = dF__2 * dt_controller + F__2;
  const float_t t19 = t1 - 0.1e1 / 0.20e2;
  const float_t t22 = dt_controller * dphi__2 + phi__2;
  const float_t t23 = cos(t22);
  const float_t t24 = t23 * t19 * t18;
  const float_t t25 = 40 * t24;
  const float_t t27 = dt_controller * dF__3 + F__3;
  const float_t t28 = t2 * t27;
  const float_t t30 = dt_controller * dphi__3 + phi__3;
  const float_t t31 = cos(t30);
  const float_t t32 = t31 * t28;
  const float_t t35 = dF__4 * dt_controller + F__4;
  const float_t t38 = dt_controller * dphi__4 + phi__4;
  const float_t t39 = cos(t38);
  const float_t t40 = t39 * t19 * t35;
  const float_t t41 = 40 * t40;
  const float_t t42 = sin(t22);
  const float_t t43 = t42 * t18;
  const float_t t44 = t43 * t12;
  const float_t t45 = 40 * t44;
  const float_t t46 = sin(t30);
  const float_t t47 = t46 * t27;
  const float_t t48 = t47 * t12;
  const float_t t49 = 40 * t48;
  const float_t t50 = sin(t38);
  const float_t t51 = t50 * t35;
  const float_t t52 = t51 * t12;
  const float_t t53 = 40 * t52;
  const float_t t54 = Tz__ref * pos__y__turr;
  const float_t t55 = 40 * t54;
  const float_t t56 = 2 * Fx__ref;
  const float_t t59 = pos__x__turr * pos__x__turr;
  const float_t t60 = t59 + 0.1e1 / 0.20e2;
  const float_t t62 = t13 * t60 * t4;
  const float_t t64 = t23 * t18 * t12;
  const float_t t66 = t31 * t27 * t12;
  const float_t t68 = t39 * t35 * t12;
  const float_t t70 = t42 * t60 * t18;
  const float_t t71 = t59 - 0.1e1 / 0.20e2;
  const float_t t73 = t46 * t27 * t71;
  const float_t t75 = t50 * t71 * t35;
  const float_t t76 = Tz__ref * pos__x__turr;
  const float_t t77 = Fy__ref / 20;
  const float_t tmp__1_1 =
      40 * t9 * t5 +
      t8 * (-80 * t15 - t25 + 40 * t32 - t41 - t45 + t49 + t53 + t55 - t56) +
      40 * t13 * (t62 + t64 - t66 + t68 + t70 - t73 - t75 - t76 - t77);
  const float_t t85 =
      (pos__x__turr - pos__y__turr) * (pos__x__turr + pos__y__turr);
  const float_t t89 = Fx__ref / 20;
  const float_t tmp__1_2 =
      40 * t4 *
      (-t9 * t4 * t12 +
       t8 * (t14 * t85 + t64 - t66 + t68 + t70 - t73 - t75 - t76 - t77) +
       (t15 + t24 - t32 + t40 + t44 - t48 - t52 + t89 - t54) * t13);
  const float_t t94 = t2 * t18;
  const float_t t95 = t23 * t23;
  const float_t t100 = t8 * t4 * t19;
  const float_t t101 = 40 * t100;
  const float_t t103 = t31 * t27 * t19;
  const float_t t104 = 40 * t103;
  const float_t t105 = t2 * t35;
  const float_t t106 = t39 * t105;
  const float_t t108 = 40 * t15;
  const float_t t112 = t8 * t4 * t12;
  const float_t tmp__1_3 =
      40 * t95 * t94 +
      t23 *
          (80 * t44 - t101 - t104 + 40 * t106 + t108 - t49 - t53 - t55 - t56) +
      40 * t42 * (t70 - t112 - t66 + t68 + t62 - t73 - t75 - t76 - t77);
  const float_t tmp__1_4 =
      40 *
      (t95 * t18 * t12 +
       t23 * (t43 * t85 - t112 + t62 - t66 + t68 - t73 - t75 - t76 - t77) -
       (t44 - t100 - t103 + t106 + t15 - t48 - t52 - t54 - t89) * t42) *
      t18;
  const float_t t125 = t31 * t31;
  const float_t t129 = t8 * t5;
  const float_t t134 = t46 * t60 * t27;
  const float_t t136 = t13 * t4 * t71;
  const float_t t138 = t42 * t18 * t71;
  const float_t t140 = t50 * t60 * t35;
  const float_t tmp__1_5 =
      40 * t125 * t28 +
      t31 * (80 * t48 + 40 * t129 - t25 - t41 - t108 - t45 + t53 + t55 - t56) -
      40 * (-t134 - t112 + t64 + t68 + t136 + t138 - t140 - t76 + t77) * t46;
  const float_t tmp__1_6 =
      -40 * t27 *
      (-t125 * t27 * t12 +
       t31 * (-t47 * t85 - t112 + t136 + t138 - t140 + t64 + t68 - t76 + t77) -
       t46 * (-t48 - t129 + t24 + t40 + t15 + t44 - t52 + t89 - t54));
  const float_t t154 = t39 * t39;
  const float_t t158 = t23 * t94;
  const float_t tmp__1_7 =
      40 * t154 * t105 +
      t39 *
          (-80 * t52 - t101 + 40 * t158 - t104 + t108 + t45 - t49 - t55 - t56) -
      40 * t50 * (-t140 - t112 + t64 - t66 + t136 + t138 - t134 - t76 + t77);
  const float_t tmp__1_8 =
      -40 *
      (t154 * t35 * t12 +
       t39 * (-t51 * t85 - t112 - t134 + t136 + t138 + t64 - t66 - t76 + t77) +
       t50 * (-t52 - t100 + t158 - t103 + t15 + t44 - t48 - t54 - t89)) *
      t35;
  const float_t t176 = -2 * t4;
  const float_t t179 = -2 * t18;
  const float_t t182 = -2 * t27;
  const float_t t185 = -2 * t35;
  const float_t tmp__1_9 =
      t8 * t176 + t23 * t179 + t31 * t182 + t39 * t185 + t56;
  const float_t tmp__1_10 =
      t13 * t176 + t42 * t179 + t46 * t182 + t50 * t185 + 2 * Fy__ref;
  const float_t tmp__1_11 =
      -40 * t13 * t4 * pos__x__turr - 40 * t23 * t18 * pos__y__turr -
      40 * t42 * t18 * pos__x__turr + 40 * t31 * t27 * pos__y__turr +
      40 * t46 * t27 * pos__x__turr - 40 * t39 * t35 * pos__y__turr +
      40 * t50 * t35 * pos__x__turr + 40 * t8 * t4 * pos__y__turr +
      40 * Tz__ref;

  func_dx(0, 0) = tmp__1_1;
  func_dx(0, 1) = tmp__1_2;
  func_dx(0, 2) = tmp__1_3;
  func_dx(0, 3) = tmp__1_4;
  func_dx(0, 4) = tmp__1_5;
  func_dx(0, 5) = tmp__1_6;
  func_dx(0, 6) = tmp__1_7;
  func_dx(0, 7) = tmp__1_8;
  func_dx(0, 8) = tmp__1_9;
  func_dx(0, 9) = tmp__1_10;
  func_dx(0, 10) = tmp__1_11;

  return func_dx;
}

Matrix rospo_com_cost_func_du(VectorRef x, VectorRef u) {
  const float_t F__1 = x[0];
  const float_t phi__1 = x[1];
  const float_t F__2 = x[2];
  const float_t phi__2 = x[3];
  const float_t F__3 = x[4];
  const float_t phi__3 = x[5];
  const float_t F__4 = x[6];
  const float_t phi__4 = x[7];
  const float_t Fx__ref = x[8];
  const float_t Fy__ref = x[9];
  const float_t Tz__ref = x[10];
  const float_t dF__1 = u[0];
  const float_t dphi__1 = u[1];
  const float_t dF__2 = u[2];
  const float_t dphi__2 = u[3];
  const float_t dF__3 = u[4];
  const float_t dphi__3 = u[5];
  const float_t dF__4 = u[6];
  const float_t dphi__4 = u[7];

  Matrix func_du = Matrix::Zero(1, 8);

  const float_t t1 = pos__y__turr * pos__y__turr;
  const float_t t2 = 0.40e2 * t1;
  const float_t t3 = 0.2e1 + t2;
  const float_t t4 = dt_controller * dt_controller;
  const float_t t5 = t4 * dF__1;
  const float_t t6 = F__1 * dt_controller;
  const float_t t7 = t5 + t6;
  const float_t t8 = t7 * t3;
  const float_t t10 = dt_controller * dphi__1 + phi__1;
  const float_t t11 = cos(t10);
  const float_t t12 = t11 * t11;
  const float_t t14 = pos__x__turr * pos__y__turr;
  const float_t t17 = 0.1000000000e1 * t5 + 0.1000000000e1 * t6;
  const float_t t18 = sin(t10);
  const float_t t20 = t18 * t17 * t14;
  const float_t t22 = 0.2e1 - t2;
  const float_t t23 = t4 * dF__2;
  const float_t t24 = F__2 * dt_controller;
  const float_t t25 = t23 + t24;
  const float_t t28 = dt_controller * dphi__2 + phi__2;
  const float_t t29 = cos(t28);
  const float_t t30 = t29 * t25 * t22;
  const float_t t31 = t4 * dF__3;
  const float_t t32 = F__3 * dt_controller;
  const float_t t33 = t31 + t32;
  const float_t t34 = t33 * t3;
  const float_t t36 = dt_controller * dphi__3 + phi__3;
  const float_t t37 = cos(t36);
  const float_t t39 = t4 * dF__4;
  const float_t t40 = F__4 * dt_controller;
  const float_t t41 = t39 + t40;
  const float_t t44 = dt_controller * dphi__4 + phi__4;
  const float_t t45 = cos(t44);
  const float_t t46 = t45 * t41 * t22;
  const float_t t49 = 0.1000000000e1 * t23 + 0.1000000000e1 * t24;
  const float_t t50 = sin(t28);
  const float_t t52 = t50 * t49 * t14;
  const float_t t53 = 0.40e2 * t52;
  const float_t t56 = 0.1000000000e1 * t32 + 0.1000000000e1 * t31;
  const float_t t57 = sin(t36);
  const float_t t59 = t57 * t56 * t14;
  const float_t t60 = 0.40e2 * t59;
  const float_t t63 = 0.1000000000e1 * t40 + 0.1000000000e1 * t39;
  const float_t t64 = sin(t44);
  const float_t t66 = t64 * t63 * t14;
  const float_t t67 = 0.40e2 * t66;
  const float_t t69 = 0.40e2 * Tz__ref * pos__y__turr;
  const float_t t70 = 0.2e1 * Fx__ref;
  const float_t t72 = dt_controller * (t69 - t70);
  const float_t t75 = pos__x__turr * pos__x__turr;
  const float_t t76 = 0.40e2 * t75;
  const float_t t77 = t76 + 0.2e1;
  const float_t t78 = t7 * t77;
  const float_t t79 = t18 * t18;
  const float_t t83 = 0.40e2 * t29 * t49 * t14;
  const float_t t86 = 0.40e2 * t37 * t56 * t14;
  const float_t t89 = 0.40e2 * t45 * t63 * t14;
  const float_t t90 = t25 * t77;
  const float_t t92 = 0.2e1 - t76;
  const float_t t94 = t57 * t33 * t92;
  const float_t t96 = t64 * t41 * t92;
  const float_t t98 = 0.40e2 * Tz__ref * pos__x__turr;
  const float_t t99 = 0.2e1 * Fy__ref;
  const float_t t101 = dt_controller * (-t98 - t99);
  const float_t tmp__1_1 =
      t12 * t8 +
      t11 * (-0.80e2 * t20 + t30 + t37 * t34 + t46 - t53 + t60 + t67 + t72) +
      t79 * t78 + t18 * (t50 * t90 + t101 + t83 - t86 + t89 + t94 + t96) +
      0.2e0 * dF__1;
  const float_t t106 = dF__1 * dt_controller + F__1;
  const float_t t107 = t18 * t106;
  const float_t t109 = dF__2 * dt_controller + F__2;
  const float_t t110 = t29 * t109;
  const float_t t112 = dt_controller * dF__3 + F__3;
  const float_t t115 = dF__4 * dt_controller + F__4;
  const float_t t116 = t45 * t115;
  const float_t t117 = t11 * t106;
  const float_t t118 = t37 * t112 - Fx__ref + t110 + t116 + t117;
  const float_t t119 = dt_controller * t118;
  const float_t t122 = t50 * t109;
  const float_t t124 = t64 * t115;
  const float_t t125 = t57 * t112 - Fy__ref + t107 + t122 + t124;
  const float_t t126 = t125 * dt_controller;
  const float_t t146 = -t11 * t106 * pos__y__turr + t18 * t106 * pos__x__turr +
                       t29 * t109 * pos__y__turr + t50 * t109 * pos__x__turr -
                       t37 * t112 * pos__y__turr - t57 * t112 * pos__x__turr +
                       t45 * t115 * pos__y__turr - t64 * t115 * pos__x__turr -
                       Tz__ref;
  const float_t tmp__1_2 = -2 * t119 * t107 + 2 * t126 * t117 +
                           40 * (t11 * pos__x__turr + t18 * pos__y__turr) *
                               t146 * dt_controller * t106 +
                           0.2e0 * dphi__1;
  const float_t t154 = t25 * t3;
  const float_t t155 = t29 * t29;
  const float_t t159 = t11 * t7 * t22;
  const float_t t161 = t37 * t33 * t22;
  const float_t t162 = t41 * t3;
  const float_t t164 = 0.40e2 * t20;
  const float_t t166 = dt_controller * (-t70 - t69);
  const float_t t169 = t50 * t50;
  const float_t t173 = 0.40e2 * t11 * t17 * t14;
  const float_t tmp__1_3 =
      t155 * t154 +
      t29 *
          (0.80e2 * t52 + t159 + t161 + t45 * t162 + t164 - t60 - t67 + t166) +
      t169 * t90 + t50 * (t18 * t78 + t101 - t173 - t86 + t89 + t94 + t96) +
      0.2e0 * dF__2;
  const float_t tmp__1_4 = -2 * t119 * t122 + 2 * t126 * t110 +
                           40 * t146 *
                               (t29 * pos__x__turr - t50 * pos__y__turr) *
                               dt_controller * t109 +
                           0.2e0 * dphi__2;
  const float_t t190 = t37 * t37;
  const float_t t196 = t33 * t77;
  const float_t t197 = t57 * t57;
  const float_t t200 = t18 * t7 * t92;
  const float_t t202 = t50 * t25 * t92;
  const float_t t203 = t41 * t77;
  const float_t t206 = dt_controller * (-t99 + t98);
  const float_t tmp__1_5 =
      t190 * t34 +
      t37 * (0.80e2 * t59 + t11 * t8 + t30 + t46 - t164 - t53 + t67 + t72) +
      t197 * t196 + t57 * (t64 * t203 + t173 + t200 + t202 + t206 - t83 - t89) +
      0.2e0 * dF__3;
  const float_t tmp__1_6 = -2 * t112 * dt_controller * t118 * t57 +
                           2 * t125 * t112 * dt_controller * t37 -
                           40 * t146 * t112 * dt_controller *
                               (t37 * pos__x__turr - t57 * pos__y__turr) +
                           0.2e0 * dphi__3;
  const float_t t226 = t45 * t45;
  const float_t t232 = t64 * t64;
  const float_t tmp__1_7 =
      t226 * t162 +
      t45 *
          (-0.80e2 * t66 + t159 + t29 * t154 + t161 + t164 + t53 - t60 + t166) +
      t232 * t203 + t64 * (t57 * t196 + t173 + t200 + t202 + t206 - t83 + t86) +
      0.2e0 * dF__4;
  const float_t tmp__1_8 = -2 * t119 * t124 + 2 * t126 * t116 -
                           40 * (t45 * pos__x__turr + t64 * pos__y__turr) *
                               t146 * dt_controller * t115 +
                           0.2e0 * dphi__4;

  func_du(0, 0) = tmp__1_1;
  func_du(0, 1) = tmp__1_2;
  func_du(0, 2) = tmp__1_3;
  func_du(0, 3) = tmp__1_4;
  func_du(0, 4) = tmp__1_5;
  func_du(0, 5) = tmp__1_6;
  func_du(0, 6) = tmp__1_7;
  func_du(0, 7) = tmp__1_8;

  return func_du;
}
