#include <maple_codegen/contact_force_dt2.hpp>
#include <maple_codegen/contact_force_dt2_params.hpp>
#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector contact_force_dt2(VectorRef x, VectorRef u) {
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

  Vector func = Vector::Zero(3);

  const float_t t1 = vy__body * pos__x__contact;
  const float_t t2 = vx__body * pos__y__contact;
  const float_t t3 = t1 + t2;
  const float_t t5 = cos(theta__body);
  const float_t t8 = vx__body * pos__x__contact;
  const float_t t9 = vy__body * pos__y__contact;
  const float_t t12 = sin(theta__body);
  const float_t t15 = omega__body * omega__body;
  const float_t t16 = pos__x__contact * pos__x__contact;
  const float_t t17 = t16 * t15;
  const float_t t18 = pos__y__contact * pos__y__contact;
  const float_t t20 = vx__body * vx__body;
  const float_t t21 = vy__body * vy__body;
  const float_t t23 =
      sqrt(2 * t5 * t3 * omega__body - 2 * t12 * (t8 - t9) * omega__body + t17 +
           t18 * t15 + t20 + t21);
  const float_t t24 = 0.1e1 / t23;
  const float_t t25 = J__body * m__body;
  const float_t t26 = t16 * vy__body;
  const float_t t27 = t18 * vy__body;
  const float_t t28 = 0.1e1 * t27;
  const float_t t29 = pos__y__contact * t8;
  const float_t t30 = 0.2e1 * t29;
  const float_t t31 = t26 - t28 + t30;
  const float_t t32 = t15 * omega__body;
  const float_t t35 = t16 * Fx__body;
  const float_t t37 = Fy__body * pos__x__contact;
  const float_t t39 = 0.2e1 * pos__y__contact * t37;
  const float_t t43 = m__body * Tz__body;
  const float_t t44 = vx__body * t16;
  const float_t t45 = pos__y__contact * t1;
  const float_t t46 = 0.2e1 * t45;
  const float_t t51 = t5 * t5;
  const float_t t54 = vx__body * t18;
  const float_t t55 = -0.1e1 * t44 + t46 + t54;
  const float_t t57 = t32 * t55 * t25;
  const float_t t58 = t16 * Fy__body;
  const float_t t60 = t18 * Fy__body;
  const float_t t61 = Fx__body * pos__x__contact;
  const float_t t63 = 0.2e1 * pos__y__contact * t61;
  const float_t t71 = J__body * pos__x__contact;
  const float_t t72 = t16 + t18;
  const float_t t74 = t15 * t15;
  const float_t t75 = t74 * t72 * m__body;
  const float_t t77 = vy__body * m__body;
  const float_t t81 = Fx__body * vy__body;
  const float_t t82 = 0.2e1 * t81;
  const float_t t83 = Fy__body * vx__body;
  const float_t t84 = -t82 + t83;
  const float_t t91 = t21 * pos__y__contact;
  const float_t t94 = vy__body * t8;
  const float_t t100 = Fx__body * J__body;
  const float_t t105 = t12 * t12;
  const float_t t107 = J__body * pos__y__contact;
  const float_t t108 = t75 * t107;
  const float_t t128 = Fy__body * J__body;
  const float_t t129 = pos__x__contact * pos__y__contact;
  const float_t t130 = t15 * t129;
  const float_t t134 = omega__body * t129;
  const float_t t136 = t21 * Fx__body;
  const float_t t138 = vy__body * t83;
  const float_t t143 = t16 * pos__x__contact;
  const float_t t145 = 0.2e1 * t20 * t143;
  const float_t t146 = pos__y__contact * t16;
  const float_t t147 = vx__body * vy__body;
  const float_t t149 = 0.12e2 * t147 * t146;
  const float_t t150 = 0.6e1 * t20;
  const float_t t151 = 0.6e1 * t21;
  const float_t t152 = -t150 + t151;
  const float_t t154 = pos__x__contact * t18 * t152;
  const float_t t155 = t18 * pos__y__contact;
  const float_t t158 = 0.4e1 * vy__body * vx__body * t155;
  const float_t t162 = t143 * Fy__body;
  const float_t t163 = vx__body * t162;
  const float_t t164 = 0.2e1 * t163;
  const float_t t165 = Fx__body * vx__body;
  const float_t t167 = Fy__body * vy__body;
  const float_t t169 = -0.6e1 * t165 + 0.6e1 * t167;
  const float_t t171 = t16 * pos__y__contact * t169;
  const float_t t174 = 0.6000000000e1 * t81 + 0.6000000000e1 * t83;
  const float_t t176 = pos__x__contact * t18 * t174;
  const float_t t177 = 0.2e1 * t167;
  const float_t t178 = 0.2e1 * t165;
  const float_t t179 = -t177 + t178;
  const float_t t180 = t155 * t179;
  const float_t t186 = 0.4e1 * vy__body * vx__body * t143;
  const float_t t188 = t16 * pos__y__contact * t152;
  const float_t t189 = t18 * pos__x__contact;
  const float_t t191 = 0.12e2 * t147 * t189;
  const float_t t192 = 0.2e1 * t21;
  const float_t t193 = 0.2e1 * t20;
  const float_t t194 = -t192 + t193;
  const float_t t196 = t155 * t194 - t186 + t188 + t191;
  const float_t t198 = t15 * t196 * t43;
  const float_t t201 = t51 * t5;
  const float_t t203 = -t152;
  const float_t t205 = t16 * pos__y__contact * t203;
  const float_t t206 = -t194;
  const float_t t208 = t155 * t206 + t186 - t191 + t205;
  const float_t t211 = t143 * t179;
  const float_t t212 = -t174;
  const float_t t214 = t16 * pos__y__contact * t212;
  const float_t t216 = pos__x__contact * t18 * t169;
  const float_t t219 = 0.2000000000e1 * t81 + 0.2000000000e1 * t83;
  const float_t t225 = t143 * t194 - t149 + t154 + t158;
  const float_t t227 = t15 * t225 * t43;
  const float_t t230 = t18 * t18;
  const float_t t231 = vy__body * t230;
  const float_t t232 = pos__y__contact * t143;
  const float_t t233 = vx__body * t232;
  const float_t t234 = 0.2e1 * t233;
  const float_t t235 = t155 * pos__x__contact;
  const float_t t236 = vx__body * t235;
  const float_t t237 = 0.2e1 * t236;
  const float_t t239 = t74 * omega__body;
  const float_t t242 = t230 * Fx__body;
  const float_t t243 = pos__y__contact * t162;
  const float_t t244 = 0.2e1 * t243;
  const float_t t245 = t155 * t37;
  const float_t t246 = 0.2e1 * t245;
  const float_t t250 = t16 * t16;
  const float_t t251 = t250 * Tz__body;
  const float_t t252 = vx__body * t251;
  const float_t t253 = 0.3e1 * t252;
  const float_t t254 = t143 * Tz__body;
  const float_t t255 = t9 * t254;
  const float_t t256 = 0.6e1 * t255;
  const float_t t258 = vy__body * t20;
  const float_t t260 = 0.5e1 * t258 * t16 * J__body;
  const float_t t261 = t155 * Tz__body;
  const float_t t262 = vy__body * t261;
  const float_t t263 = 0.6e1 * t262;
  const float_t t264 = t21 * vx__body;
  const float_t t265 = 0.2e1 * t264;
  const float_t t266 = t20 * vx__body;
  const float_t t268 = t265 - 0.6e1 * t266;
  const float_t t273 = t230 * Tz__body;
  const float_t t274 = vx__body * t273;
  const float_t t275 = 0.3e1 * t274;
  const float_t t276 = 0.5e1 * t258;
  const float_t t277 = t21 * vy__body;
  const float_t t278 = t276 + t277;
  const float_t t285 = 0.5e1 * t20 * t35;
  const float_t t286 = vy__body * t165;
  const float_t t288 = t20 * Fy__body;
  const float_t t290 = t21 * Fy__body;
  const float_t t291 = 0.6e1 * t290;
  const float_t t292 = 0.8e1 * t286 + 0.6e1 * t288 + t291;
  const float_t t295 = 0.5e1 * t20;
  const float_t t302 = 0.3e1 * t266;
  const float_t t303 = t264 - t302;
  const float_t t307 = 0.10e2 * t258 + 0.2e1 * t277;
  const float_t t311 = -0.1e1 * t264 + t302;
  const float_t t319 = t143 * J__body;
  const float_t t320 = t74 * m__body;
  const float_t t329 = 0.2e1 * t105 *
                       (0.1000000000e1 * t21 * t320 +
                        0.1000000000e1 * vy__body * t32 * Fx__body) *
                       t319;
  const float_t t330 = vy__body * t235;
  const float_t t331 = 0.2e1 * t330;
  const float_t t332 = vx__body * t250;
  const float_t t333 = vx__body * t230;
  const float_t t335 = vy__body * t232;
  const float_t t336 = 0.2e1 * t335;
  const float_t t340 = t230 * Fy__body;
  const float_t t342 = pos__y__contact * t143 * Fx__body;
  const float_t t343 = 0.2e1 * t342;
  const float_t t344 = t155 * t61;
  const float_t t345 = 0.2e1 * t344;
  const float_t t346 = t250 * Fy__body;
  const float_t t347 = 0.1e1 * t346;
  const float_t t351 = vy__body * t251;
  const float_t t352 = 0.3e1 * t351;
  const float_t t353 = t2 * t254;
  const float_t t354 = 0.6e1 * t353;
  const float_t t355 = J__body * t311;
  const float_t t357 = vx__body * t261;
  const float_t t358 = 0.6e1 * t357;
  const float_t t359 = -t307;
  const float_t t364 = vy__body * t273;
  const float_t t365 = 0.3e1 * t364;
  const float_t t366 = J__body * t303;
  const float_t t374 = -0.4e1 * t286 - 0.3e1 * t288 - 0.3e1 * t290;
  const float_t t376 = 0.10e2 * t20;
  const float_t t377 = -t376 - t192;
  const float_t t380 = -t374;
  const float_t t385 = 0.1e1 * t277;
  const float_t t386 = -t276 - t385;
  const float_t t396 = pos__y__contact * t251;
  const float_t t398 = 0.3e1 * t20 * t319;
  const float_t t399 = t147 * t107;
  const float_t t401 = 0.2e1 * t261;
  const float_t t402 = 0.11e2 * t399 + t401;
  const float_t t404 = 0.3e1 * t20;
  const float_t t405 = 0.4e1 * t21;
  const float_t t406 = t404 - t405;
  const float_t t409 = t155 * J__body;
  const float_t t410 = t147 * t409;
  const float_t t413 = t230 * pos__y__contact * Tz__body;
  const float_t t417 = 0.3e1 * t163;
  const float_t t419 = 0.3e1 * t167;
  const float_t t420 = 0.8e1 * t165 - t419;
  const float_t t424 = 0.3e1 * t83;
  const float_t t425 = -0.4e1 * t81 - t424;
  const float_t t428 = t178 + t419;
  const float_t t433 = t147 * t254;
  const float_t t434 = 0.7e1 * t433;
  const float_t t435 = 0.3e1 * t21;
  const float_t t436 = t376 - t435;
  const float_t t439 = t18 * Tz__body;
  const float_t t440 = t147 * t439;
  const float_t t441 = 0.5e1 * t440;
  const float_t t443 = 0.1000000000e1 * t21 * t20;
  const float_t t444 = t20 * t20;
  const float_t t446 = t443 + 0.1000000000e1 * t444;
  const float_t t447 = J__body * t446;
  const float_t t451 = 0.4e1 * t20;
  const float_t t452 = t451 + t435;
  const float_t t453 = t452 * Tz__body;
  const float_t t455 = J__body * vx__body;
  const float_t t456 = t20 + t21;
  const float_t t457 = t456 * vy__body;
  const float_t t459 = pos__y__contact * t457 * t455;
  const float_t t463 = t20 * Fx__body;
  const float_t t464 = vy__body * t463;
  const float_t t465 = 0.2e1 * t464;
  const float_t t466 = t21 * t83;
  const float_t t467 = 0.3e1 * t466;
  const float_t t468 = t266 * Fy__body;
  const float_t t469 = t465 + t467 + t468;
  const float_t t471 = t21 * t165;
  const float_t t472 = 0.2e1 * t471;
  const float_t t473 = vy__body * t288;
  const float_t t474 = 0.3e1 * t473;
  const float_t t475 = t277 * Fy__body;
  const float_t t476 = t266 * Fx__body;
  const float_t t477 = 0.4e1 * t476;
  const float_t t478 = t472 + t474 + t475 + t477;
  const float_t t483 = t456 * vx__body;
  const float_t t500 = t250 * pos__x__contact * Tz__body;
  const float_t t501 = 0.1e1 * t500;
  const float_t t502 = vy__body * t455;
  const float_t t504 = 0.2e1 * t439;
  const float_t t505 = -0.3e1 * t502 - t504;
  const float_t t507 = t192 - t404;
  const float_t t510 = 0.1e1 * t273;
  const float_t t511 = t27 * t455;
  const float_t t514 = t20 * t409;
  const float_t t520 = 0.4e1 * t165;
  const float_t t523 = t82 + t424;
  const float_t t526 = -t428;
  const float_t t529 = t155 * t83;
  const float_t t533 = 0.1e1 * t21;
  const float_t t539 = pos__y__contact * t16 * Tz__body * t147;
  const float_t t540 = 0.7e1 * t539;
  const float_t t542 = -t452 * Tz__body;
  const float_t t548 =
      0.1000000000e1 * vy__body * t266 + 0.1000000000e1 * t277 * vx__body;
  const float_t t549 = J__body * t548;
  const float_t t550 = 0.1e1 * t549;
  const float_t t553 = t261 * t147;
  const float_t t554 = 0.3e1 * t553;
  const float_t t561 = -t472 - t474 - 0.1e1 * t475 - t477;
  const float_t t575 = pos__y__contact * t71;
  const float_t t576 = m__body * gamma__5;
  const float_t t581 = t18 * t35;
  const float_t t586 = t74 * gamma__5;
  const float_t t588 = 0.4e1 * t252;
  const float_t t589 = 0.3e1 * t255;
  const float_t t592 = t20 * J__body;
  const float_t t595 = 0.5e1 * vx__body * t439 + 0.3e1 * vy__body * t592;
  const float_t t597 = 0.3e1 * t262;
  const float_t t603 = 0.2e1 * t258 * t18 * J__body;
  const float_t t606 = t32 * gamma__5;
  const float_t t608 = 0.3e1 * t138;
  const float_t t609 = 0.6e1 * t463;
  const float_t t610 = t608 + t609;
  const float_t t618 = t15 * gamma__5;
  const float_t t621 = t265 + 0.4e1 * t266;
  const float_t t625 = 0.3e1 * t264;
  const float_t t632 = J__body * gamma__5;
  const float_t t633 = t165 + t167;
  const float_t t636 =
      t23 *
          (t51 * (t32 * t31 * t25 + t15 * (-0.1e1 * t35 + t39) * J__body +
                  omega__body * (t44 - t46) * t43) +
           t5 * (t12 * (t57 + t15 * (-0.1e1 * t58 + t60 - t63) * J__body +
                        omega__body * t31 * t43) +
                 t75 * t71 + t15 * t3 * J__body * t77 +
                 omega__body *
                     (Fy__body * pos__y__contact * vy__body +
                      pos__x__contact * t84) *
                     J__body -
                 0.1e1 * t91 * t43 + t94 * t43) +
           t105 * (omega__body * vx__body * t43 - 0.1e1 * t15 * t100) * t18 +
           t12 * (t108 + t15 * (t91 - 0.1e1 * t94) * t25 +
                  omega__body *
                      (-0.1e1 * vy__body * t37 + pos__y__contact * t84) *
                      J__body +
                  t3 * vy__body * t43) +
           t32 * (0.2e1 * t27 + t26 - 0.1e1 * t29) * t25 - 0.1e1 * t130 * t128 +
           t134 * vy__body * t43 + J__body * (-0.1e1 * t136 + t138)) +
      t201 *
          (t74 * (t145 - t149 + t154 + t158) * t25 +
           t32 * (-t164 + t171 + t176 + t180) * J__body + t198) *
          gamma__5 +
      t51 *
          (t12 * (t74 * t208 * t25 +
                  t32 * (t155 * t219 + t211 + t214 + t216) * J__body + t227) +
           t239 * (t231 - t234 - t237) * t25 +
           t74 * (t242 + t244 + t246) * J__body +
           t32 *
               (-t253 + t256 - t260 +
                pos__x__contact * (pos__y__contact * J__body * t268 + t263) +
                t275 + t18 * J__body * t278) *
               m__body +
           t15 *
               (-t285 + pos__x__contact * pos__y__contact * t292 +
                t18 * (t21 + t295) * Fx__body) *
               J__body +
           omega__body *
               (pos__x__contact * pos__y__contact * t307 + t16 * t303 +
                t18 * t311) *
               t43) *
          gamma__5 +
      t5 *
          (t329 +
           t12 * (t239 * (-t331 + t332 - 0.1e1 * t333 - t336) * t25 +
                  t74 * (t340 - t343 - t345 - t347) * J__body +
                  t32 *
                      (-t352 - t354 + t16 * t355 +
                       pos__x__contact *
                           (pos__y__contact * J__body * t359 - t358) +
                       t365 + t18 * t366) *
                      m__body +
                  t15 * (t129 * t377 * Fx__body + t16 * t374 + t18 * t380) *
                      J__body +
                  omega__body *
                      (pos__x__contact * pos__y__contact * t268 + t16 * t386 +
                       t18 * t278) *
                      t43) +
           t74 *
               (t396 - t398 + t16 * t402 + t189 * J__body * t406 -
                0.1e1 * t410 + t413) *
               m__body +
           t32 *
               (t16 * pos__y__contact * t420 + pos__x__contact * t18 * t425 +
                t155 * t428 + t417) *
               J__body +
           t15 *
               (t434 + t146 * t436 * Tz__body +
                pos__x__contact * (-t441 - 0.1e1 * t447) + t155 * t453 + t459) *
               m__body +
           omega__body * (pos__x__contact * t469 + pos__y__contact * t478) *
               J__body +
           t3 * t483 * t43) *
          gamma__5 +
      t105 * (m__body * omega__body * vy__body + Fx__body) * (t17 + t21) *
          gamma__5 * t16 * t15 * J__body +
      t12 *
          (t74 *
               (-t501 + t143 * t505 + t146 * J__body * t507 +
                pos__x__contact * (-t510 + t511) - 0.1e1 * t514) *
               m__body +
           t32 *
               (t143 * (-0.1e1 * t167 - t520) + t16 * pos__y__contact * t523 +
                pos__x__contact * t18 * t526 + t529) *
               J__body +
           t15 *
               (t143 * (-t150 - t533) * Tz__body + t540 +
                pos__x__contact * (t18 * t542 - t550) + t554 -
                0.1e1 * pos__y__contact * t447) *
               m__body +
           omega__body * (pos__y__contact * t469 + pos__x__contact * t561) *
               J__body +
           (-0.1e1 * pos__x__contact * t446 + t457 * t2) * t43) *
          gamma__5 +
      t239 * (t44 + t45 + t54) * t576 * t575 +
      t586 * (t581 - 0.1e1 * t243 - 0.1e1 * t245) * J__body +
      t606 *
          (t588 - t589 + t16 * t595 +
           pos__x__contact * (pos__y__contact * t355 - t597) - t603 + t274) *
          m__body +
      t618 *
          (t16 * t610 + pos__x__contact * pos__y__contact * t374 +
           t18 * (t608 + t463)) *
          J__body +
      omega__body * gamma__5 *
          (t16 * t621 + pos__x__contact * pos__y__contact * t386 +
           t18 * (t625 + t266)) *
          t43 +
      t633 * t483 * t632;
  const float_t t638 = tanh(t23 * gamma__5);
  const float_t t641 = pos__x__contact * t18 * t203;
  const float_t t645 = -t169;
  const float_t t647 = t16 * pos__y__contact * t645;
  const float_t t649 = pos__x__contact * t18 * t212;
  const float_t t650 = -t179;
  const float_t t651 = t155 * t650;
  const float_t t656 = t15 * t208 * t43;
  const float_t t662 = t143 * t650;
  const float_t t664 = t16 * pos__y__contact * t174;
  const float_t t666 = pos__x__contact * t18 * t645;
  const float_t t667 = -t219;
  const float_t t673 = t143 * t206 + t149 - t158 + t641;
  const float_t t675 = t15 * t673 * t43;
  const float_t t678 = 0.1e1 * t231;
  const float_t t682 = 0.1e1 * t242;
  const float_t t686 = -t268;
  const float_t t715 = 0.1e1 * t332;
  const float_t t749 = 0.1e1 * t396;
  const float_t t755 = 0.1e1 * t413;
  const float_t t777 = 0.1e1 * pos__y__contact * t549;
  const float_t t782 = -0.1e1 * t468 - t465 - t467;
  const float_t t788 = pos__x__contact * t548;
  const float_t t801 = t32 * m__body;
  const float_t t809 = t250 * Fx__body;
  const float_t t842 = t457 * t455;
  const float_t t845 = pos__y__contact * t456;
  const float_t t857 = pos__y__contact * t548;
  const float_t t865 = t18 * t16;
  const float_t t901 = 0.1e1 * t266;
  const float_t t919 =
      t638 * t636 +
      t201 *
          (t74 * (-t145 + t149 + t641 - t158) * t25 +
           t32 * (t164 + t647 + t649 + t651) * J__body + t656) *
          gamma__5 +
      t51 *
          (t12 * (t74 * t196 * t25 +
                  t32 * (t155 * t667 + t662 + t664 + t666) * J__body + t675) +
           t239 * (-t678 + t234 + t237) * t25 +
           t74 * (-t682 - t244 - t246) * J__body +
           t32 *
               (t253 - t256 + t260 +
                pos__x__contact * (pos__y__contact * J__body * t686 - t263) -
                t275 + t18 * J__body * t386) *
               m__body +
           t15 *
               (t285 - pos__x__contact * pos__y__contact * t292 +
                t18 * (-t533 - t295) * Fx__body) *
               J__body +
           omega__body *
               (pos__x__contact * pos__y__contact * t359 + t16 * t311 +
                t18 * t303) *
               t43) *
          gamma__5 +
      t5 *
          (-t329 +
           t12 * (t239 * (t331 - t715 + t333 + t336) * t25 +
                  t74 * (-0.1e1 * t340 + t343 + t345 + t346) * J__body +
                  t32 *
                      (t352 + t354 + t16 * t366 +
                       pos__x__contact *
                           (pos__y__contact * J__body * t307 + t358) -
                       t365 + t18 * t355) *
                      m__body +
                  t15 * (-t129 * t377 * Fx__body + t16 * t380 + t18 * t374) *
                      J__body +
                  omega__body *
                      (pos__x__contact * pos__y__contact * t686 + t16 * t278 +
                       t18 * t386) *
                      t43) +
           t74 *
               (-t189 * J__body * t406 - t16 * t402 + t398 + t410 - t749 -
                t755) *
               m__body +
           t32 *
               (-t16 * pos__y__contact * t420 - pos__x__contact * t18 * t425 +
                t155 * t526 - t417) *
               J__body +
           t15 *
               (-t434 - t146 * t436 * Tz__body +
                pos__x__contact * (t456 * t592 + t441) + t155 * t542 - t777) *
               m__body +
           omega__body * (pos__y__contact * t561 + pos__x__contact * t782) *
               J__body -
           0.1e1 *
               (0.1000000000e1 * t788 +
                0.1000000000e1 * pos__y__contact * t446) *
               t43) *
          gamma__5 -
      0.1e1 * t105 *
          (0.1000000000e1 * t239 * t250 * t77 +
           0.1000000000e1 * t277 * t16 * t801 +
           0.1000000000e1 * t21 * t16 * t15 * Fx__body +
           0.1000000000e1 * t74 * t809) *
          t632 +
      t12 *
          (t74 *
               (t500 - t143 * t505 - t146 * J__body * t507 +
                pos__x__contact * (t273 - 0.1e1 * t511) + t514) *
               m__body +
           t32 *
               (t143 * (t167 + t520) - t16 * pos__y__contact * t523 +
                pos__x__contact * t18 * t428 - 0.1e1 * t529) *
               J__body +
           t15 *
               (t143 * (t150 + t21) * Tz__body - t540 +
                pos__x__contact * (t18 * t453 + t842) - t554 + t845 * t592) *
               m__body +
           omega__body * (pos__x__contact * t478 + pos__y__contact * t782) *
               J__body +
           (pos__x__contact * t456 * t20 - 0.1e1 * t857) * t43) *
          gamma__5 -
      0.1e1 * t239 * gamma__5 *
          (0.1000000000e1 * t233 + 0.1000000000e1 * vy__body * t865 +
           0.1000000000e1 * t236) *
          t25 +
      t586 * (-0.1e1 * t581 + t243 + t245) * J__body +
      t606 *
          (-t588 + t589 - t16 * t595 +
           pos__x__contact * (pos__y__contact * t366 + t597) + t603 -
           0.1e1 * t274) *
          m__body +
      t618 *
          (-t16 * t610 + pos__x__contact * pos__y__contact * t380 +
           t18 * (-t608 - 0.1e1 * t463)) *
          J__body +
      omega__body * gamma__5 *
          (-t16 * t621 + pos__x__contact * pos__y__contact * t278 +
           t18 * (-t625 - t901)) *
          t43 +
      gamma__5 * J__body *
          (-0.1000000000e1 * t444 * Fx__body - 0.1000000000e1 * t21 * t463 -
           0.1000000000e1 * vy__body * t468 - 0.1000000000e1 * t277 * t83);
  const float_t t926 =
      t5 * omega__body * (0.2000000000e1 * t1 + 0.2000000000e1 * t2);
  const float_t t932 = t15 * t72;
  const float_t t940 = sqrt(
      t926 + t12 * omega__body * (-0.2000000000e1 * t8 + 0.2000000000e1 * t9) +
      t932 + t20 + t21);
  const float_t t963 =
      0.1e1 / J__body / m__body /
      (t940 * (t926 + t12 * omega__body * (-0.2e1 * t8 + 0.2e1 * t9) + t932 +
               t20 + t21) +
       t5 * omega__body * (0.2000000000e-3 * t1 + 0.2000000000e-3 * t2) +
       t12 * omega__body * (-0.2e-3 * t8 + 0.2e-3 * t9) +
       t15 * (0.1000000000e-3 * t16 + 0.1000000000e-3 * t18) + 0.1e-3 * t20 +
       0.1e-3 * t21);
  const float_t tmp__1 = -t963 * gamma__4 * t919 * t24;
  const float_t t992 = 0.2e1 * t83;
  const float_t t998 = pos__x__contact * t20;
  const float_t t1000 = vy__body * t2;
  const float_t t1030 = vx__body * Tz__body;
  const float_t t1050 = 0.2e1 * t155 * t21;
  const float_t t1055 = vy__body * t155 * Fx__body;
  const float_t t1056 = 0.2e1 * t1055;
  const float_t t1077 = 0.5e1 * t264;
  const float_t t1078 = t266 + t1077;
  const float_t t1082 = 0.2e1 * t258;
  const float_t t1083 = -0.6e1 * t277 + t1082;
  const float_t t1088 = t21 * J__body;
  const float_t t1089 = t54 * t1088;
  const float_t t1090 = 0.5e1 * t1089;
  const float_t t1094 = 0.1e1 * t20;
  const float_t t1095 = 0.5e1 * t21;
  const float_t t1101 = -t609 - 0.6e1 * t136 - 0.8e1 * t138;
  const float_t t1105 = 0.5e1 * t18 * t290;
  const float_t t1109 = 0.3e1 * t277;
  const float_t t1110 = t258 - t1109;
  const float_t t1114 = -0.10e2 * t264 - 0.2e1 * t266;
  const float_t t1118 = -0.1e1 * t258 + t1109;
  const float_t t1131 = -0.2e1 * vx__body * t32 * Fy__body + 0.2e1 * t20 * t320;
  const float_t t1134 = t250 * vy__body;
  const float_t t1141 = J__body * t1118;
  const float_t t1143 = -t1114;
  const float_t t1148 = J__body * t1110;
  const float_t t1156 = 0.4e1 * t138 + 0.3e1 * t136 + 0.3e1 * t463;
  const float_t t1158 = 0.10e2 * t21;
  const float_t t1159 = -t193 - t1158;
  const float_t t1162 = -t1156;
  const float_t t1170 = -t1077 - t901;
  const float_t t1180 = -t451 + t435;
  const float_t t1183 = 0.11e2 * t511;
  const float_t t1187 = 0.3e1 * t21 * t409;
  const float_t t1191 = 0.3e1 * t165;
  const float_t t1192 = -t1191 - t177;
  const float_t t1194 = 0.3e1 * t81;
  const float_t t1196 = t1194 + 0.4e1 * t83;
  const float_t t1200 = t1191 - 0.8e1 * t167;
  const float_t t1203 = 0.3e1 * t1055;
  const float_t t1207 = -t405 - t404;
  const float_t t1208 = t1207 * Tz__body;
  const float_t t1210 = 0.5e1 * t539;
  const float_t t1211 = t404 - t1158;
  const float_t t1216 = 0.7e1 * t553;
  const float_t t1217 = t21 * t21;
  const float_t t1219 = t443 + 0.1000000000e1 * t1217;
  const float_t t1220 = J__body * t1219;
  const float_t t1227 = 0.4e1 * t475;
  const float_t t1228 = 0.3e1 * t471;
  const float_t t1229 = 0.2e1 * t473;
  const float_t t1230 = -0.1e1 * t476 - t1227 - t1228 - t1229;
  const float_t t1232 = t277 * Fx__body;
  const float_t t1234 = 0.3e1 * t464;
  const float_t t1235 = 0.2e1 * t466;
  const float_t t1236 = -0.1e1 * t1232 - t1234 - t1235;
  const float_t t1252 = t20 * t18 * t15 * Fy__body;
  const float_t t1255 = t266 * t18 * t801;
  const float_t t1258 = t239 * t230 * vx__body * m__body;
  const float_t t1259 = t74 * t340;
  const float_t t1264 = t143 * t1088;
  const float_t t1268 = -t193 + t435;
  const float_t t1271 = 0.3e1 * t410;
  const float_t t1276 = Fx__body * t143 * vy__body;
  const float_t t1279 = t1194 + t992;
  const float_t t1283 = 0.4e1 * t167;
  const float_t t1289 = 0.3e1 * t433;
  const float_t t1291 = 0.7e1 * t440;
  const float_t t1301 = t1232 + t1234 + t1235;
  const float_t t1320 = t18 * t58;
  const float_t t1326 = 0.3e1 * t353;
  const float_t t1331 = -0.5e1 * vy__body * t439 - 0.2e1 * vx__body * t1088;
  const float_t t1333 = 0.3e1 * t357;
  const float_t t1337 = 0.3e1 * t1089;
  const float_t t1338 = 0.4e1 * t364;
  const float_t t1342 = 0.3e1 * t286;
  const float_t t1348 = -t1342 - t291;
  const float_t t1353 = 0.3e1 * t258;
  const float_t t1359 = -t1082 - 0.4e1 * t277;
  const float_t t1376 =
      t23 *
          (t51 * (t57 + t15 * (t60 - t63) * J__body +
                  omega__body * (t30 - t28) * t43) +
           t5 * (t12 * (t32 * (-t30 + t27 - 0.1e1 * t26) * t25 +
                        t15 * (-t39 + t35 - 0.1e1 * t18 * Fx__body) * J__body +
                        omega__body * t55 * t43) +
                 t108 + t15 * t3 * vx__body * t25 +
                 omega__body *
                     (-0.1e1 * vx__body * t61 +
                      pos__y__contact * (-0.1e1 * t81 + t992)) *
                     J__body +
                 t998 * t43 - 0.1e1 * t1000 * t43) +
           t105 * (-0.1e1 * omega__body * vy__body * t43 + t15 * t128) * t16 +
           t12 * (-0.1e1 * t74 *
                      (0.1000000000e1 * t189 + 0.1000000000e1 * t143) * t25 +
                  t15 * (t1000 - 0.1e1 * t998) * t25 +
                  omega__body *
                      (pos__x__contact * (-t992 + t81) -
                       0.1e1 * Fx__body * pos__y__contact * vx__body) *
                      J__body +
                  t3 * m__body * t1030) +
           t32 * (0.2e1 * t44 - 0.1e1 * t45 + t54) * t25 + t130 * t100 -
           0.1e1 * t134 * m__body * t1030 + J__body * (-0.1e1 * t286 + t288)) +
      t201 *
          (t74 * (t186 + t205 - t191 + t1050) * t25 +
           t32 * (t211 + t214 + t216 + t1056) * J__body + t227) *
          gamma__5 +
      t51 *
          (t12 * (t74 * t673 * t25 +
                  t32 * (t143 * t219 + t647 + t649 + t651) * J__body + t656) +
           t239 * (-t336 - t331 + t332) * t25 +
           t74 * (-t343 - t345 - t347) * J__body +
           t32 *
               (-t352 - t354 + t16 * J__body * t1078 +
                pos__x__contact * (pos__y__contact * J__body * t1083 - t358) -
                t1090 + t365) *
               m__body +
           t15 *
               (t16 * (-t1094 - t1095) * Fy__body +
                pos__x__contact * pos__y__contact * t1101 + t1105) *
               J__body +
           omega__body *
               (pos__x__contact * pos__y__contact * t1114 + t16 * t1110 +
                t18 * t1118) *
               t43) *
          gamma__5 +
      t5 *
          (t105 * t1131 * t409 +
           t12 * (t239 * (t1134 - t678 + t234 + t237) * t25 +
                  t74 * (-t682 + t809 - t244 - t246) * J__body +
                  t32 *
                      (t253 - t256 + t16 * t1141 +
                       pos__x__contact *
                           (pos__y__contact * J__body * t1143 - t263) -
                       t275 + t18 * t1148) *
                      m__body +
                  t15 * (t129 * t1159 * Fy__body + t16 * t1156 + t18 * t1162) *
                      J__body +
                  omega__body *
                      (pos__x__contact * pos__y__contact * t1083 + t16 * t1078 +
                       t18 * t1170) *
                      t43) +
           t74 *
               (-t501 + t143 * (-t504 - 0.1e1 * t502) + t146 * J__body * t1180 +
                pos__x__contact * (-t510 + t1183) - t1187) *
               m__body +
           t32 *
               (t16 * pos__y__contact * t1196 + pos__x__contact * t18 * t1200 +
                t143 * t1192 - t1203) *
               J__body +
           t15 *
               (t143 * t1208 + t1210 +
                pos__x__contact * (t18 * t1211 * Tz__body + t842) - t1216 -
                0.1e1 * pos__y__contact * t1220) *
               m__body +
           omega__body * (pos__x__contact * t1230 + pos__y__contact * t1236) *
               J__body -
           0.1e1 *
               (0.1000000000e1 * pos__x__contact * t1219 +
                0.1000000000e1 * t857) *
               t43) *
          gamma__5 +
      t105 * (-0.1e1 * t1252 + t1255 + t1258 - 0.1e1 * t1259) * t632 +
      t12 *
          (t74 *
               (-t749 + t1264 + t16 * (-0.1e1 * t399 - t401) +
                t189 * J__body * t1268 + t1271 - t755) *
               m__body +
           t32 *
               (t1276 + t16 * pos__y__contact * t1192 +
                pos__x__contact * t18 * t1279 +
                t155 * (-0.1e1 * t165 - t1283)) *
               J__body +
           t15 *
               (t1289 + t146 * t1208 +
                pos__x__contact * (t456 * t1088 + t1291) +
                t155 * (-t1094 - t151) * Tz__body + t459) *
               m__body +
           omega__body * (pos__y__contact * t1230 + pos__x__contact * t1301) *
               J__body +
           (pos__x__contact * t456 * t147 - 0.1e1 * pos__y__contact * t1219) *
               t43) *
          gamma__5 +
      t239 * (t26 + t29 + t27) * t576 * t575 +
      t586 * (-0.1e1 * t1320 + t342 + t344) * J__body +
      t606 *
          (-0.1e1 * t351 + t1326 + t16 * t1331 +
           pos__x__contact * (pos__y__contact * t1141 + t1333) + t1337 -
           t1338) *
          m__body +
      t618 *
          (t16 * (-t1342 - 0.1e1 * t290) +
           pos__x__contact * pos__y__contact * t1156 + t18 * t1348) *
          J__body +
      omega__body * gamma__5 *
          (t16 * (-t1353 - t385) + pos__x__contact * pos__y__contact * t1078 +
           t18 * t1359) *
          t43 +
      gamma__5 * J__body *
          (-0.1000000000e1 * vy__body * t476 - 0.1000000000e1 * t277 * t165 -
           0.1000000000e1 * t21 * t288 - 0.1000000000e1 * t1217 * Fy__body);
  const float_t t1403 = -t1083;
  const float_t t1477 = -t1192;
  const float_t t1489 = -t1207 * Tz__body;
  const float_t t1500 = t1227 + t476 + t1228 + t1229;
  const float_t t1601 =
      t638 * t1376 +
      t201 *
          (t74 * (-t186 + t188 + t191 - t1050) * t25 +
           t32 * (t662 + t664 + t666 - t1056) * J__body + t675) *
          gamma__5 +
      t51 *
          (t12 * (t74 * t225 * t25 +
                  t32 * (t143 * t667 + t171 + t176 + t180) * J__body + t198) +
           t239 * (t336 + t331 - t715) * t25 +
           t74 * (t343 + t345 + t346) * J__body +
           t32 *
               (t352 + t354 + t16 * J__body * t1170 +
                pos__x__contact * (pos__y__contact * J__body * t1403 + t358) +
                t1090 - t365) *
               m__body +
           t15 *
               (t16 * (t20 + t1095) * Fy__body -
                pos__x__contact * pos__y__contact * t1101 - t1105) *
               J__body +
           omega__body *
               (pos__x__contact * pos__y__contact * t1143 + t18 * t1110 +
                t16 * t1118) *
               t43) *
          gamma__5 +
      t5 *
          (-t105 * t1131 * t409 +
           t12 * (t239 * (-0.1e1 * t1134 + t231 - t234 - t237) * t25 +
                  t74 * (t242 - 0.1e1 * t809 + t244 + t246) * J__body +
                  t32 *
                      (-t253 + t256 + t16 * t1148 +
                       pos__x__contact *
                           (pos__y__contact * J__body * t1114 + t263) +
                       t275 + t18 * t1141) *
                      m__body +
                  t15 * (-t129 * t1159 * Fy__body + t18 * t1156 + t16 * t1162) *
                      J__body +
                  omega__body *
                      (pos__x__contact * pos__y__contact * t1403 + t18 * t1078 +
                       t16 * t1170) *
                      t43) +
           t74 *
               (t500 + t143 * (t504 + t502) - t146 * J__body * t1180 +
                pos__x__contact * (t273 - t1183) + t1187) *
               m__body +
           t32 *
               (-t16 * pos__y__contact * t1196 - pos__x__contact * t18 * t1200 +
                t143 * t1477 + t1203) *
               J__body +
           t15 *
               (t143 * t1489 - t1210 +
                pos__x__contact * (-t18 * t1211 * Tz__body - t550) + t1216 +
                t845 * t1088) *
               m__body +
           omega__body * (pos__y__contact * t1301 + pos__x__contact * t1500) *
               J__body +
           t3 * t457 * t43) *
          gamma__5 +
      t105 * (t1252 - 0.1e1 * t1255 - 0.1e1 * t1258 + t1259) * t632 +
      t12 *
          (t74 *
               (t396 - 0.1e1 * t1264 + t16 * (t399 + t401) -
                t189 * J__body * t1268 - t1271 + t413) *
               m__body +
           t32 *
               (-0.1e1 * t1276 + t16 * pos__y__contact * t1477 -
                pos__x__contact * t18 * t1279 + t155 * (t165 + t1283)) *
               J__body +
           t15 *
               (-t1289 + t146 * t1489 +
                pos__x__contact * (-t1291 - 0.1e1 * t1220) +
                t155 * (t20 + t151) * Tz__body - t777) *
               m__body +
           omega__body * (pos__x__contact * t1236 + pos__y__contact * t1500) *
               J__body +
           (-0.1e1 * t788 + t456 * t91) * t43) *
          gamma__5 -
      0.1e1 * t239 * gamma__5 *
          (0.1000000000e1 * t335 + 0.1000000000e1 * vx__body * t865 +
           0.1000000000e1 * t330) *
          t25 +
      t586 * (t1320 - 0.1e1 * t342 - 0.1e1 * t344) * J__body +
      t606 *
          (t351 - t1326 - t16 * t1331 +
           pos__x__contact * (pos__y__contact * t1148 - t1333) - t1337 +
           t1338) *
          m__body +
      t618 *
          (t16 * (t1342 + t290) + pos__x__contact * pos__y__contact * t1162 -
           t18 * t1348) *
          J__body +
      omega__body * gamma__5 *
          (t16 * (t277 + t1353) + pos__x__contact * pos__y__contact * t1170 -
           t18 * t1359) *
          t43 +
      t633 * t457 * t632;
  const float_t tmp__2 = t963 * gamma__4 * t1601 * t24;
  const float_t t1606 = sqrt(t72);
  const float_t tmp__3 = -t1606 * gamma__5 * (-1 + t638) * gamma__4;

  func(0) = tmp__1;
  func(1) = tmp__2;
  func(2) = tmp__3;

  return func;
}

Matrix contact_force_dt2_dx(VectorRef x, VectorRef u) {
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

  Vector func_dx = Vector::Zero(1);

  return func_dx;
}

Matrix contact_force_dt2_du(VectorRef x, VectorRef u) {
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

  Vector func_du = Vector::Zero(1);

  return func_du;
}
