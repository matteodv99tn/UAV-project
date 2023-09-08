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

  const float_t t1 = cos(theta__body);
  const float_t t2 = t1 * omega__body;
  const float_t t3 = pos__y__contact * t2;
  const float_t t4 = 0.1e1 * t3;
  const float_t t5 = sin(theta__body);
  const float_t t6 = t5 * omega__body;
  const float_t t7 = pos__x__contact * t6;
  const float_t t9 = vy__body * pos__x__contact;
  const float_t t10 = vx__body * pos__y__contact;
  const float_t t14 = 2 * t1 * (-t9 + t10) * omega__body;
  const float_t t15 = vx__body * pos__x__contact;
  const float_t t16 = vy__body * pos__y__contact;
  const float_t t20 = 2 * t5 * (t15 + t16) * omega__body;
  const float_t t21 = omega__body * omega__body;
  const float_t t22 = pos__x__contact * pos__x__contact;
  const float_t t23 = t22 * t21;
  const float_t t24 = pos__y__contact * pos__y__contact;
  const float_t t25 = t24 * t21;
  const float_t t26 = vx__body * vx__body;
  const float_t t27 = vy__body * vy__body;
  const float_t t29 = sqrt(t14 + t20 + t23 + t25 + t26 + t27);
  const float_t t31 = 0.1e-3 * t3;
  const float_t t32 = 0.1e-3 * t7;
  const float_t t33 = 0.1e-3 * vx__body;
  const float_t t38 = 2 * t1 * (t9 + t10) * omega__body;
  const float_t t42 = 2 * t5 * (t15 - t16) * omega__body;
  const float_t t44 = sqrt(t38 - t42 + t23 + t25 + t26 + t27);
  const float_t t47 = t29 * (-t31 + t32 + t33);
  const float_t t48 = 0.1e-7 * t3;
  const float_t t49 = 0.1e-7 * t7;
  const float_t t50 = 0.1e-7 * vx__body;
  const float_t t53 = sqrt(-t14 - t20 + t23 + t25 + t26 + t27);
  const float_t t59 = 0.1e-11 * vx__body;
  const float_t t60 = 0.1e-11 * t3;
  const float_t t61 = 0.1e-11 * t7;
  const float_t t65 = sqrt(-t38 + t42 + t23 + t25 + t26 + t27);
  const float_t t67 = tanh(t65 * gamma__5);
  const float_t t69 = 0.1e1 * t7;
  const float_t t75 = t29 * (-t31 - t32 + t33);
  const float_t t85 = tanh(t53 * gamma__5);
  const float_t t92 = t29 * (t31 - t32 + t33);
  const float_t t102 = tanh(t44 * gamma__5);
  const float_t t112 = t44 * (0.1000000000e1 * t3 + 0.1000000000e1 * t7 +
                              0.1000000000e1 * vx__body);
  const float_t t113 = 0.1e-3 * t112;
  const float_t t122 = tanh(t29 * gamma__5);
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
  const float_t t138 = sin(phi__4);
  const float_t t139 = t134 * t138;
  const float_t t141 = sin(phi__2);
  const float_t t142 = t128 * t141;
  const float_t t144 = sin(phi__3);
  const float_t t145 = t131 * t144;
  const float_t t147 = sin(phi__1);
  const float_t t148 = t125 * t147;
  const float_t t150 = 0.1000000000e1 * t139 + 0.1000000000e1 * t142 +
                       0.1000000000e1 * t145 + 0.1000000000e1 * t148;
  const float_t t151 = t5 * t150;
  const float_t t159 = 0.1000000000e1 * t126 + 0.1000000000e1 * t129 +
                       0.1000000000e1 * t132 + 0.1000000000e1 * t135;
  const float_t t160 = t1 * t159;
  const float_t t161 = 0.1e-3 * t160;
  const float_t t162 = 0.1e-3 * t151;
  const float_t t166 = t29 * (t161 - t162);
  const float_t t167 = 0.1e-7 * t160;
  const float_t t168 = 0.1e-7 * t151;
  const float_t t172 = t44 * (t166 + t167 - t168);
  const float_t t174 = t29 * (t167 - t168);
  const float_t t175 = 0.1e-11 * t160;
  const float_t t176 = 0.1e-11 * t151;
  const float_t t189 = t159 * k__l;
  const float_t t192 = t150 * k__l;
  const float_t t196 = 0.2000000000e1 * t9;
  const float_t t197 = 0.2000000000e1 * t10;
  const float_t t198 = -t196 + t197;
  const float_t t201 = 0.2000000000e1 * t15;
  const float_t t202 = 0.2000000000e1 * t16;
  const float_t t203 = t201 + t202;
  const float_t t206 = t22 + t24;
  const float_t t207 = t21 * t206;
  const float_t t209 = sqrt(t1 * omega__body * t198 + t5 * omega__body * t203 +
                            t207 + t26 + t27);
  const float_t t211 = 0.1e1 / (0.1e-3 + t209);
  const float_t t213 = -t196 - t197;
  const float_t t216 = t201 - t202;
  const float_t t220 = sqrt(t1 * omega__body * t213 + t5 * omega__body * t216 +
                            t207 + t26 + t27);
  const float_t t230 = sqrt(-t1 * omega__body * t213 - t5 * omega__body * t216 +
                            t207 + t26 + t27);
  const float_t t241 = sqrt(-t1 * omega__body * t198 - t5 * omega__body * t203 +
                            t207 + t26 + t27);
  const float_t t244 =
      0.1e1 / (0.1e-3 + t241) / (0.1e-3 + t230) / (0.1e-3 + t220);
  const float_t tmp__1 =
      t244 * t211 *
      (t67 *
           (t53 * (t44 * (t29 * (-t4 + t7 + vx__body) - t31 + t32 + t33) + t47 -
                   t48 + t49 + t50) +
            t44 * (t47 - t48 + t49 + t50) + t29 * (-t48 + t49 + t50) + t59 -
            t60 + t61) *
           gamma__4 +
       t85 *
           (t65 * (t44 * (t29 * (vx__body - t4 - t69) - t31 - t32 + t33) + t75 -
                   t48 - t49 + t50) +
            t44 * (t75 - t48 - t49 + t50) + t29 * (-t48 - t49 + t50) + t59 -
            t60 - t61) *
           gamma__4 +
       t102 *
           (t65 * (t53 * (t29 * (-t69 + t3 + vx__body) + t31 - t32 + t33) +
                   t92 + t48 - t49 + t50) +
            t53 * (t92 + t48 - t49 + t50) + t29 * (t48 - t49 + t50) + t59 +
            t60 - t61) *
           gamma__4 +
       t122 *
           (t65 * (t53 * (t44 * (t7 + t3 + vx__body) + t31 + t32 + t33) + t113 +
                   t48 + t49 + t50) +
            t53 * (t113 + t48 + t49 + t50) + 0.1e-7 * t112 + t59 + t60 + t61) *
           gamma__4 +
       t65 *
           (t53 * (t44 * (t29 * (t1 * t136 - 0.1e1 * t151) + t161 - t162) +
                   t166 + t167 - t168) +
            t172 + t174 + t175 - t176) *
           k__l +
       t53 * (t172 + t174 + t175 - t176) * k__l +
       t44 * (t174 + t175 - t176) * k__l + t29 * (t175 - t176) * k__l +
       0.1e-15 * t1 * t189 - 0.1e-15 * t5 * t192);
  const float_t t245 = pos__y__contact * t6;
  const float_t t246 = 0.1e1 * t245;
  const float_t t247 = pos__x__contact * t2;
  const float_t t248 = 0.1e1 * t247;
  const float_t t251 = 0.1e-3 * t245;
  const float_t t252 = 0.1e-3 * t247;
  const float_t t253 = 0.1e-3 * vy__body;
  const float_t t257 = t29 * (-t251 - t252 + t253);
  const float_t t258 = 0.1e-7 * t245;
  const float_t t259 = 0.1e-7 * t247;
  const float_t t260 = 0.1e-7 * vy__body;
  const float_t t267 = 0.1e-11 * vy__body;
  const float_t t268 = 0.1e-11 * t245;
  const float_t t269 = 0.1e-11 * t247;
  const float_t t278 = t29 * (t253 - t251 + t252);
  const float_t t296 = t29 * (0.1000000000e1 * t245 + 0.1000000000e1 * t247 +
                              0.1000000000e1 * vy__body);
  const float_t t297 = 0.1e-3 * t296;
  const float_t t311 = t44 * (t251 - t252 + t253);
  const float_t t326 = t1 * t150;
  const float_t t328 = t5 * t159;
  const float_t t334 = 0.1000000000e1 * t326 + 0.1000000000e1 * t328;
  const float_t t335 = t29 * t334;
  const float_t t336 = 0.1e-3 * t335;
  const float_t t337 = 0.1e-7 * t326;
  const float_t t338 = 0.1e-7 * t328;
  const float_t t342 = t44 * (t336 + t337 + t338);
  const float_t t343 = 0.1e-7 * t335;
  const float_t t344 = 0.1e-11 * t326;
  const float_t t345 = 0.1e-11 * t328;
  const float_t tmp__2 =
      t244 * t211 *
      (t67 *
           (t53 * (t44 * (t29 * (vy__body - t246 - t248) - t251 - t252 + t253) +
                   t257 - t258 - t259 + t260) +
            t44 * (t257 - t258 - t259 + t260) + t29 * (-t258 - t259 + t260) +
            t267 - t268 - t269) *
           gamma__4 +
       t85 *
           (t65 *
                (t44 * (t29 * (-t246 + vy__body + t247) + t253 - t251 + t252) +
                 t278 - t258 + t259 + t260) +
            t44 * (t278 - t258 + t259 + t260) + t29 * (-t258 + t259 + t260) +
            t267 - t268 + t269) *
           gamma__4 +
       t102 *
           (t65 * (t53 * (t29 * (t247 + t245 + vy__body) + t251 + t252 + t253) +
                   t297 + t258 + t259 + t260) +
            t53 * (t297 + t258 + t259 + t260) + 0.1e-7 * t296 + t267 + t268 +
            t269) *
           gamma__4 +
       t122 *
           (t65 * (t53 * (t44 * (vy__body - t248 + t245) + t251 - t252 + t253) +
                   t311 - t259 + t258 + t260) +
            t53 * (t311 - t259 + t258 + t260) + t44 * (-t259 + t258 + t260) +
            t267 + t268 - t269) *
           gamma__4 +
       t65 *
           (t53 * (t44 * (t29 * (t1 * (t148 + t142 + t145 + t139) + t136 * t5) +
                          0.1e-3 * t326 + 0.1e-3 * t328) +
                   t336 + t337 + t338) +
            t342 + t343 + t344 + t345) *
           k__l +
       t53 * (t342 + t343 + t344 + t345) * k__l +
       t44 * (t343 + t344 + t345) * k__l + 0.1e-11 * t29 * t334 * k__l +
       0.1e-15 * t1 * t192 + 0.1e-15 * t5 * t189);
  const float_t t365 = t1 * t206 * omega__body;
  const float_t t374 =
      t1 * (0.1000000000e1 * t24 + 0.1000000000e1 * t22) * omega__body;
  const float_t t375 = 0.1e-3 * t374;
  const float_t t376 = 0.1000000000e-3 * t10;
  const float_t t377 = 0.1000000000e-3 * t9;
  const float_t t381 = t29 * (t375 - t376 - t377);
  const float_t t382 = 0.1e-7 * t374;
  const float_t t383 = 0.1000000000e-7 * t10;
  const float_t t384 = 0.1000000000e-7 * t9;
  const float_t t391 = 0.1e-11 * t374;
  const float_t t392 = 0.1000000000e-11 * t10;
  const float_t t393 = 0.1000000000e-11 * t9;
  const float_t t400 = 0.1e-3 * t10;
  const float_t t401 = 0.1e-3 * t9;
  const float_t t405 = t29 * (t375 - t400 + t401);
  const float_t t406 = 0.1e-7 * t10;
  const float_t t407 = 0.1e-7 * t9;
  const float_t t414 = 0.1e-11 * t10;
  const float_t t415 = 0.1e-11 * t9;
  const float_t t424 = t29 * (t375 + t376 + t377);
  const float_t t440 = t44 * (t375 + t400 - t401);
  const float_t t450 = t133 * pos__y__turr;
  const float_t t451 = t134 * t450;
  const float_t t452 = t138 * pos__x__turr;
  const float_t t453 = t134 * t452;
  const float_t t455 = t127 * pos__y__turr;
  const float_t t456 = t128 * t455;
  const float_t t457 = t124 * pos__y__turr;
  const float_t t458 = t125 * t457;
  const float_t t460 = t147 * pos__x__turr;
  const float_t t461 = t125 * t460;
  const float_t t462 = t141 * pos__x__turr;
  const float_t t463 = t128 * t462;
  const float_t t464 = t130 * pos__y__turr;
  const float_t t465 = t131 * t464;
  const float_t t467 = t144 * pos__x__turr;
  const float_t t468 = t131 * t467;
  const float_t t472 = 0.1e-3 * t456;
  const float_t t473 = 0.1e-3 * t463;
  const float_t t474 = 0.1e-3 * t465;
  const float_t t475 = 0.1e-3 * t468;
  const float_t t476 = 0.1e-3 * t451;
  const float_t t477 = 0.1e-3 * t453;
  const float_t t478 = 0.1e-3 * t458;
  const float_t t479 = 0.1e-3 * t461;
  const float_t t483 =
      t29 * (t472 + t473 - t474 - t475 + t476 - t477 - t478 + t479);
  const float_t t484 = 0.1e-7 * t458;
  const float_t t485 = 0.1e-7 * t461;
  const float_t t486 = 0.1e-7 * t456;
  const float_t t487 = 0.1e-7 * t463;
  const float_t t488 = 0.1e-7 * t465;
  const float_t t489 = 0.1e-7 * t468;
  const float_t t490 = 0.1e-7 * t451;
  const float_t t491 = 0.1e-7 * t453;
  const float_t t495 =
      t44 * (t483 - t484 + t485 + t486 + t487 - t488 - t489 + t490 - t491);
  const float_t t497 =
      t29 * (-t484 + t485 + t486 + t487 - t488 - t489 + t490 - t491);
  const float_t t498 = 0.1e-11 * t458;
  const float_t t499 = 0.1e-11 * t461;
  const float_t t500 = 0.1e-11 * t456;
  const float_t t501 = 0.1e-11 * t463;
  const float_t t502 = 0.1e-11 * t465;
  const float_t t503 = 0.1e-11 * t468;
  const float_t t504 = 0.1e-11 * t451;
  const float_t t505 = 0.1e-11 * t453;
  const float_t t506 =
      t53 * (t44 * (t29 * (t451 - 0.1e1 * t453 + t456 - 0.1e1 * t458 + t461 +
                           t463 - 0.1e1 * t465 - 0.1e1 * t468) +
                    t472 + t473 - t474 - t475 + t476 - t477 - t478 + t479) +
             t483 - t484 + t485 + t486 + t487 - t488 - t489 + t490 - t491) +
      t495 + t497 - t498 + t499 + t500 + t501 - t502 - t503 + t504 - t505;
  const float_t t518 = t125 * k__l;
  const float_t t523 = t128 * k__l;
  const float_t t528 = t131 * k__l;
  const float_t t533 = t134 * k__l;
  const float_t t538 =
      t67 *
          (t53 * (t44 * (t29 * (t365 - 0.1000000000e1 * t10 -
                                0.1000000000e1 * t9) +
                         t375 - t376 - t377) +
                  t381 + t382 - t383 - t384) +
           t44 * (t381 + t382 - t383 - t384) + t29 * (t382 - t383 - t384) +
           t391 - t392 - t393) *
          gamma__4 +
      t85 *
          (t65 * (t44 * (t29 * (t365 - 0.1e1 * t10 + t9) + t375 - t400 + t401) +
                  t405 + t382 - t406 + t407) +
           t44 * (t405 + t382 - t406 + t407) + t29 * (t382 - t406 + t407) +
           t391 - t414 + t415) *
          gamma__4 +
      t102 *
          (t65 * (t53 * (t29 * (t365 + t10 + t9) + t375 + t376 + t377) + t424 +
                  t382 + t383 + t384) +
           t53 * (t424 + t382 + t383 + t384) + t29 * (t382 + t383 + t384) +
           t391 + t392 + t393) *
          gamma__4 +
      t122 *
          (t65 * (t53 * (t44 * (t365 + t10 - 0.1e1 * t9) + t375 + t400 - t401) +
                  t440 + t382 + t406 - t407) +
           t53 * (t440 + t382 + t406 - t407) + t44 * (t382 + t406 - t407) +
           t391 + t414 - t415) *
          gamma__4 +
      t65 * t506 * k__l +
      t53 *
          (t495 + t497 - t498 + t499 + t500 + t501 - t502 - t503 + t504 -
           t505) *
          k__l +
      t44 * (t497 - t498 + t499 + t500 + t501 - t502 - t503 + t504 - t505) *
          k__l +
      t29 * (-t498 + t499 + t500 + t501 - t502 - t503 + t504 - t505) * k__l -
      0.1e-15 * t518 * t457 + 0.1e-15 * t518 * t460 + 0.1e-15 * t523 * t455 +
      0.1e-15 * t523 * t462 - 0.1e-15 * t528 * t464 - 0.1e-15 * t528 * t467 +
      0.1e-15 * t533 * t450 - 0.1e-15 * t533 * t452;
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
