#include <maple_codegen/mapledefines.hpp>
#include <maple_codegen/overall_force.hpp>
#include <maple_codegen/overall_force_params.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector overall_force(VectorRef x) {
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
  const float_t t4 = 0.1e1 * t3;
  const float_t t5 = cos(theta__body);
  const float_t t6 = t5 * omega__body;
  const float_t t7 = pos__y__contact * t6;
  const float_t t8 = 0.1e1 * t7;
  const float_t t10 = vy__body * pos__x__contact;
  const float_t t11 = vx__body * pos__y__contact;
  const float_t t15 = 2 * t5 * (-t10 + t11) * omega__body;
  const float_t t16 = vx__body * pos__x__contact;
  const float_t t17 = vy__body * pos__y__contact;
  const float_t t21 = 2 * t1 * (t16 + t17) * omega__body;
  const float_t t22 = omega__body * omega__body;
  const float_t t23 = pos__x__contact * pos__x__contact;
  const float_t t24 = t23 * t22;
  const float_t t25 = pos__y__contact * pos__y__contact;
  const float_t t26 = t25 * t22;
  const float_t t27 = vx__body * vx__body;
  const float_t t28 = vy__body * vy__body;
  const float_t t30 = sqrt(t15 + t21 + t24 + t26 + t27 + t28);
  const float_t t32 = 0.1e-3 * t7;
  const float_t t33 = 0.1e-3 * t3;
  const float_t t34 = 0.1e-3 * vx__body;
  const float_t t39 = 2 * t5 * (t10 + t11) * omega__body;
  const float_t t43 = 2 * t1 * (t16 - t17) * omega__body;
  const float_t t45 = sqrt(-t39 + t43 + t24 + t26 + t27 + t28);
  const float_t t48 = t30 * (-t32 - t33 + t34);
  const float_t t49 = 0.1e-7 * t7;
  const float_t t50 = 0.1e-7 * t3;
  const float_t t51 = 0.1e-7 * vx__body;
  const float_t t54 = sqrt(t39 - t43 + t24 + t26 + t27 + t28);
  const float_t t60 = 0.1e-11 * vx__body;
  const float_t t61 = 0.1e-11 * t3;
  const float_t t62 = 0.1e-11 * t7;
  const float_t t66 = sqrt(-t15 - t21 + t24 + t26 + t27 + t28);
  const float_t t68 = tanh(t66 * gamma__5);
  const float_t t75 = t30 * (t32 - t33 + t34);
  const float_t t85 = tanh(t54 * gamma__5);
  const float_t t92 = t30 * (-t32 + t33 + t34);
  const float_t t102 = tanh(t45 * gamma__5);
  const float_t t112 = t45 * (0.1000000000e1 * t7 + 0.1000000000e1 * t3 +
                              0.1000000000e1 * vx__body);
  const float_t t113 = 0.1e-3 * t112;
  const float_t t122 = tanh(t30 * gamma__5);
  const float_t t124 = cos(phi__1);
  const float_t t125 = Omega__1 * Omega__1;
  const float_t t126 = t125 * t124;
  const float_t t127 = cos(phi__2);
  const float_t t128 = Omega__2 * Omega__2;
  const float_t t129 = t128 * t127;
  const float_t t130 = cos(phi__3);
  const float_t t131 = Omega__3 * Omega__3;
  const float_t t132 = t131 * t130;
  const float_t t133 = cos(phi__4);
  const float_t t134 = Omega__4 * Omega__4;
  const float_t t135 = t134 * t133;
  const float_t t136 = t126 + t129 + t132 + t135;
  const float_t t138 = sin(phi__1);
  const float_t t139 = t125 * t138;
  const float_t t141 = sin(phi__2);
  const float_t t142 = t128 * t141;
  const float_t t144 = sin(phi__3);
  const float_t t145 = t131 * t144;
  const float_t t147 = sin(phi__4);
  const float_t t148 = t134 * t147;
  const float_t t150 = 0.1000000000e1 * t139 + 0.1000000000e1 * t142 +
                       0.1000000000e1 * t145 + 0.1000000000e1 * t148;
  const float_t t151 = t1 * t150;
  const float_t t159 = 0.1000000000e1 * t129 + 0.1000000000e1 * t135 +
                       0.1000000000e1 * t126 + 0.1000000000e1 * t132;
  const float_t t160 = t5 * t159;
  const float_t t161 = 0.1e-3 * t160;
  const float_t t162 = 0.1e-3 * t151;
  const float_t t166 = t30 * (t161 - t162);
  const float_t t167 = 0.1e-7 * t160;
  const float_t t168 = 0.1e-7 * t151;
  const float_t t172 = t45 * (t166 + t167 - t168);
  const float_t t174 = t30 * (t167 - t168);
  const float_t t175 = 0.1e-11 * t160;
  const float_t t176 = 0.1e-11 * t151;
  const float_t t189 = t159 * k__l;
  const float_t t192 = t150 * k__l;
  const float_t t196 = 0.2000000000e1 * t10;
  const float_t t197 = 0.2000000000e1 * t11;
  const float_t t198 = -t196 + t197;
  const float_t t201 = 0.2000000000e1 * t16;
  const float_t t202 = 0.2000000000e1 * t17;
  const float_t t203 = t201 + t202;
  const float_t t206 = t23 + t25;
  const float_t t207 = t22 * t206;
  const float_t t209 = sqrt(t1 * omega__body * t203 + t5 * omega__body * t198 +
                            t207 + t27 + t28);
  const float_t t211 = 0.1e1 / (0.1e-3 + t209);
  const float_t t213 = -t196 - t197;
  const float_t t216 = t201 - t202;
  const float_t t220 = sqrt(t1 * omega__body * t216 + t5 * omega__body * t213 +
                            t207 + t27 + t28);
  const float_t t230 = sqrt(-t1 * omega__body * t216 - t5 * omega__body * t213 +
                            t207 + t27 + t28);
  const float_t t241 = sqrt(-t1 * omega__body * t203 - t5 * omega__body * t198 +
                            t207 + t27 + t28);
  const float_t t244 =
      0.1e1 / (0.1e-3 + t241) / (0.1e-3 + t230) / (0.1e-3 + t220);
  const float_t tmp__1 =
      t244 * t211 *
      (t68 *
           (t54 * (t45 * (t30 * (vx__body - t4 - t8) - t32 - t33 + t34) + t48 -
                   t49 - t50 + t51) +
            t45 * (t48 - t49 - t50 + t51) + t30 * (-t49 - t50 + t51) + t60 -
            t61 - t62) *
           gamma__4 +
       t85 *
           (t66 * (t45 * (t30 * (vx__body + t7 - t4) + t32 - t33 + t34) + t75 +
                   t49 - t50 + t51) +
            t45 * (t75 + t49 - t50 + t51) + t30 * (t49 - t50 + t51) + t60 -
            t61 + t62) *
           gamma__4 +
       t102 *
           (t66 * (t54 * (t30 * (vx__body - t8 + t3) - t32 + t33 + t34) + t92 -
                   t49 + t50 + t51) +
            t54 * (t92 - t49 + t50 + t51) + t30 * (-t49 + t50 + t51) + t60 +
            t61 - t62) *
           gamma__4 +
       t122 *
           (t66 * (t54 * (t45 * (t3 + t7 + vx__body) + t32 + t33 + t34) + t113 +
                   t51 + t49 + t50) +
            t54 * (t113 + t51 + t49 + t50) + 0.1e-7 * t112 + t60 + t61 + t62) *
           gamma__4 +
       t66 *
           (t54 * (t45 * (t30 * (t5 * t136 - 0.1e1 * t151) + t161 - t162) +
                   t166 + t167 - t168) +
            t172 + t174 + t175 - t176) *
           k__l +
       t54 * (t172 + t174 + t175 - t176) * k__l +
       t45 * (t174 + t175 - t176) * k__l + t30 * (t175 - t176) * k__l +
       0.1e-15 * t5 * t189 - 0.1e-15 * t1 * t192);
  const float_t t245 = pos__y__contact * t2;
  const float_t t246 = 0.1e1 * t245;
  const float_t t247 = pos__x__contact * t6;
  const float_t t250 = 0.1e-3 * vy__body;
  const float_t t251 = 0.1e-3 * t245;
  const float_t t252 = 0.1e-3 * t247;
  const float_t t256 = t30 * (t250 - t251 + t252);
  const float_t t257 = 0.1e-7 * vy__body;
  const float_t t258 = 0.1e-7 * t245;
  const float_t t259 = 0.1e-7 * t247;
  const float_t t266 = 0.1e-11 * vy__body;
  const float_t t267 = 0.1e-11 * t245;
  const float_t t268 = 0.1e-11 * t247;
  const float_t t280 = t30 * (0.1000000000e1 * vy__body +
                              0.1000000000e1 * t245 + 0.1000000000e1 * t247);
  const float_t t281 = 0.1e-3 * t280;
  const float_t t290 = 0.1e1 * t247;
  const float_t t296 = t30 * (-t251 - t252 + t250);
  const float_t t311 = t45 * (t251 - t252 + t250);
  const float_t t326 = t5 * t150;
  const float_t t328 = t1 * t159;
  const float_t t334 = 0.1000000000e1 * t326 + 0.1000000000e1 * t328;
  const float_t t335 = t30 * t334;
  const float_t t336 = 0.1e-3 * t335;
  const float_t t337 = 0.1e-7 * t326;
  const float_t t338 = 0.1e-7 * t328;
  const float_t t342 = t45 * (t336 + t337 + t338);
  const float_t t343 = 0.1e-7 * t335;
  const float_t t344 = 0.1e-11 * t326;
  const float_t t345 = 0.1e-11 * t328;
  const float_t tmp__2 =
      t244 * t211 *
      (t68 *
           (t54 *
                (t45 * (t30 * (-t246 + t247 + vy__body) + t250 - t251 + t252) +
                 t256 + t257 - t258 + t259) +
            t45 * (t256 + t257 - t258 + t259) + t30 * (t257 - t258 + t259) +
            t266 - t267 + t268) *
           gamma__4 +
       t85 *
           (t66 * (t45 * (t30 * (t247 + t245 + vy__body) + t250 + t251 + t252) +
                   t281 + t257 + t258 + t259) +
            t45 * (t281 + t257 + t258 + t259) + 0.1e-7 * t280 + t266 + t267 +
            t268) *
           gamma__4 +
       t102 *
           (t66 *
                (t54 * (t30 * (-t246 - t290 + vy__body) - t251 - t252 + t250) +
                 t296 + t257 - t258 - t259) +
            t54 * (t296 + t257 - t258 - t259) + t30 * (t257 - t258 - t259) +
            t266 - t268 - t267) *
           gamma__4 +
       t122 *
           (t66 * (t54 * (t45 * (t245 - t290 + vy__body) + t251 - t252 + t250) +
                   t311 + t257 + t258 - t259) +
            t54 * (t311 + t257 + t258 - t259) + t45 * (t257 + t258 - t259) +
            t266 + t267 - t268) *
           gamma__4 +
       t66 *
           (t54 * (t45 * (t30 * (t5 * (t139 + t142 + t145 + t148) + t136 * t1) +
                          0.1e-3 * t326 + 0.1e-3 * t328) +
                   t336 + t337 + t338) +
            t342 + t343 + t344 + t345) *
           k__l +
       t54 * (t342 + t343 + t344 + t345) * k__l +
       t45 * (t343 + t344 + t345) * k__l + 0.1e-11 * t30 * t334 * k__l +
       0.1e-15 * t5 * t192 + 0.1e-15 * t1 * t189);
  const float_t t365 = t5 * t206 * omega__body;
  const float_t t373 =
      t5 * (0.1000000000e1 * t25 + 0.1000000000e1 * t23) * omega__body;
  const float_t t374 = 0.1e-3 * t373;
  const float_t t375 = 0.1e-3 * t11;
  const float_t t376 = 0.1e-3 * t10;
  const float_t t380 = t30 * (t374 - t375 + t376);
  const float_t t381 = 0.1e-7 * t373;
  const float_t t382 = 0.1e-7 * t11;
  const float_t t383 = 0.1e-7 * t10;
  const float_t t390 = 0.1e-11 * t373;
  const float_t t391 = 0.1e-11 * t10;
  const float_t t392 = 0.1e-11 * t11;
  const float_t t398 = 0.1000000000e-3 * t11;
  const float_t t399 = 0.1000000000e-3 * t10;
  const float_t t403 = t30 * (t374 + t398 + t399);
  const float_t t404 = 0.1000000000e-7 * t11;
  const float_t t405 = 0.1000000000e-7 * t10;
  const float_t t412 = 0.1000000000e-11 * t11;
  const float_t t413 = 0.1000000000e-11 * t10;
  const float_t t424 = t30 * (t374 - t398 - t399);
  const float_t t440 = t45 * (t374 + t375 - t376);
  const float_t t450 = t124 * pos__y__turr;
  const float_t t451 = t125 * t450;
  const float_t t453 = t138 * pos__x__turr;
  const float_t t454 = t125 * t453;
  const float_t t455 = t144 * pos__x__turr;
  const float_t t456 = t131 * t455;
  const float_t t458 = t133 * pos__y__turr;
  const float_t t459 = t134 * t458;
  const float_t t460 = t147 * pos__x__turr;
  const float_t t461 = t134 * t460;
  const float_t t463 = t127 * pos__y__turr;
  const float_t t464 = t128 * t463;
  const float_t t465 = t141 * pos__x__turr;
  const float_t t466 = t128 * t465;
  const float_t t467 = t130 * pos__y__turr;
  const float_t t468 = t131 * t467;
  const float_t t472 = 0.1e-3 * t461;
  const float_t t473 = 0.1e-3 * t451;
  const float_t t474 = 0.1e-3 * t454;
  const float_t t475 = 0.1e-3 * t464;
  const float_t t476 = 0.1e-3 * t466;
  const float_t t477 = 0.1e-3 * t468;
  const float_t t478 = 0.1e-3 * t456;
  const float_t t479 = 0.1e-3 * t459;
  const float_t t483 =
      t30 * (-t472 - t473 + t474 + t475 + t476 - t477 - t478 + t479);
  const float_t t484 = 0.1e-7 * t451;
  const float_t t485 = 0.1e-7 * t454;
  const float_t t486 = 0.1e-7 * t464;
  const float_t t487 = 0.1e-7 * t466;
  const float_t t488 = 0.1e-7 * t468;
  const float_t t489 = 0.1e-7 * t456;
  const float_t t490 = 0.1e-7 * t459;
  const float_t t491 = 0.1e-7 * t461;
  const float_t t495 =
      t45 * (t483 - t484 + t485 + t486 + t487 - t488 - t489 + t490 - t491);
  const float_t t497 =
      t30 * (-t484 + t485 + t486 + t487 - t488 - t489 + t490 - t491);
  const float_t t498 = 0.1e-11 * t451;
  const float_t t499 = 0.1e-11 * t454;
  const float_t t500 = 0.1e-11 * t464;
  const float_t t501 = 0.1e-11 * t466;
  const float_t t502 = 0.1e-11 * t468;
  const float_t t503 = 0.1e-11 * t456;
  const float_t t504 = 0.1e-11 * t459;
  const float_t t505 = 0.1e-11 * t461;
  const float_t t506 =
      t54 * (t45 * (t30 * (-0.1e1 * t451 + t454 - 0.1e1 * t456 + t459 -
                           0.1e1 * t461 + t464 + t466 - 0.1e1 * t468) -
                    t472 - t473 + t474 + t475 + t476 - t477 - t478 + t479) +
             t483 - t484 + t485 + t486 + t487 - t488 - t489 + t490 - t491) +
      t495 + t497 - t498 + t499 + t500 + t501 - t502 - t503 + t504 - t505;
  const float_t t518 = t125 * k__l;
  const float_t t523 = t128 * k__l;
  const float_t t528 = t131 * k__l;
  const float_t t533 = t134 * k__l;
  const float_t t538 =
      t68 *
          (t54 *
               (t45 * (t30 * (t365 - 0.1e1 * t11 + t10) + t374 - t375 + t376) +
                t380 + t381 - t382 + t383) +
           t45 * (t380 + t381 - t382 + t383) + t30 * (t381 - t382 + t383) +
           t390 + t391 - t392) *
          gamma__4 +
      t85 *
          (t66 * (t45 * (t30 * (t365 + t11 + t10) + t374 + t398 + t399) + t403 +
                  t381 + t404 + t405) +
           t45 * (t403 + t381 + t404 + t405) + t30 * (t381 + t404 + t405) +
           t390 + t412 + t413) *
          gamma__4 +
      t102 *
          (t66 * (t54 * (t30 * (t365 - 0.1000000000e1 * t11 -
                                0.1000000000e1 * t10) +
                         t374 - t398 - t399) +
                  t424 + t381 - t404 - t405) +
           t54 * (t424 + t381 - t404 - t405) + t30 * (t381 - t404 - t405) +
           t390 - t412 - t413) *
          gamma__4 +
      t122 *
          (t66 *
               (t54 * (t45 * (t365 + t11 - 0.1e1 * t10) + t374 + t375 - t376) +
                t440 + t381 + t382 - t383) +
           t54 * (t440 + t381 + t382 - t383) + t45 * (t381 + t382 - t383) +
           t390 - t391 + t392) *
          gamma__4 +
      t66 * t506 * k__l +
      t54 *
          (t495 + t497 - t498 + t499 + t500 + t501 - t502 - t503 + t504 -
           t505) *
          k__l +
      t45 * (t497 - t498 + t499 + t500 + t501 - t502 - t503 + t504 - t505) *
          k__l +
      t30 * (-t498 + t499 + t500 + t501 - t502 - t503 + t504 - t505) * k__l -
      0.1e-15 * t518 * t450 + 0.1e-15 * t518 * t453 + 0.1e-15 * t523 * t463 +
      0.1e-15 * t523 * t465 - 0.1e-15 * t528 * t467 - 0.1e-15 * t528 * t455 +
      0.1e-15 * t533 * t458 - 0.1e-15 * t533 * t460;
  const float_t tmp__3 = t244 * t211 * t538;

  func(0) = tmp__1;
  func(1) = tmp__2;
  func(2) = tmp__3;

  return func;
}

Matrix overall_force_dx(VectorRef x) {
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
