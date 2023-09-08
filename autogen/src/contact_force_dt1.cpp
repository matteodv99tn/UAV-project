#include <maple_codegen/contact_force_dt1.hpp>
#include <maple_codegen/contact_force_dt1_params.hpp>
#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector contact_force_dt1(VectorRef x, VectorRef u) {
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
  const float_t t5 = cos(theta__body);
  const float_t t8 = vx__body * pos__x__contact;
  const float_t t9 = vy__body * pos__y__contact;
  const float_t t10 = t8 + t9;
  const float_t t12 = sin(theta__body);
  const float_t t15 = omega__body * omega__body;
  const float_t t16 = pos__x__contact * pos__x__contact;
  const float_t t17 = t16 * t15;
  const float_t t18 = pos__y__contact * pos__y__contact;
  const float_t t20 = vx__body * vx__body;
  const float_t t21 = vy__body * vy__body;
  const float_t t23 =
      sqrt(-2 * t5 * (-t1 + t2) * omega__body - 2 * t12 * t10 * omega__body +
           t17 + t18 * t15 + t20 + t21);
  const float_t t24 = 0.1e1 / t23;
  const float_t t26 = J__body * m__body;
  const float_t t27 = pos__y__contact * t8;
  const float_t t28 = 0.2e1 * t27;
  const float_t t29 = t18 * vy__body;
  const float_t t30 = 0.1e1 * t29;
  const float_t t31 = t16 * vy__body;
  const float_t t32 = -t28 - t30 + t31;
  const float_t t33 = t15 * omega__body;
  const float_t t36 = Fy__body * pos__x__contact;
  const float_t t37 = pos__y__contact * t36;
  const float_t t38 = 0.2e1 * t37;
  const float_t t39 = t16 * Fx__body;
  const float_t t44 = m__body * Tz__body;
  const float_t t45 = pos__y__contact * t1;
  const float_t t46 = 0.2e1 * t45;
  const float_t t47 = vx__body * t16;
  const float_t t52 = t5 * t5;
  const float_t t55 = vx__body * t18;
  const float_t t56 = -0.1e1 * t47 + t55 - t46;
  const float_t t58 = t33 * t56 * t26;
  const float_t t59 = Fx__body * pos__x__contact;
  const float_t t60 = pos__y__contact * t59;
  const float_t t61 = 0.2e1 * t60;
  const float_t t62 = t16 * Fy__body;
  const float_t t64 = t18 * Fy__body;
  const float_t t72 = J__body * pos__x__contact;
  const float_t t73 = t16 + t18;
  const float_t t75 = t15 * t15;
  const float_t t78 = vy__body * t2;
  const float_t t80 = t21 * pos__x__contact;
  const float_t t84 = Fx__body * vy__body;
  const float_t t85 = 0.2e1 * t84;
  const float_t t86 = Fy__body * vx__body;
  const float_t t101 = Fx__body * J__body;
  const float_t t106 = t12 * t12;
  const float_t t108 = pos__y__contact * t16;
  const float_t t110 = t18 * pos__y__contact;
  const float_t t115 =
      0.1e1 * t75 * (0.1000000000e1 * t108 + 0.1000000000e1 * t110) * t26;
  const float_t t116 = vy__body * t8;
  const float_t t141 = Fy__body * J__body;
  const float_t t142 = pos__x__contact * pos__y__contact;
  const float_t t143 = t15 * t142;
  const float_t t146 = omega__body * t142;
  const float_t t149 = t21 * Fx__body;
  const float_t t151 = vy__body * t86;
  const float_t t159 = t5 * omega__body * (0.2e1 * t1 - 0.2e1 * t2);
  const float_t t165 = t15 * t73;
  const float_t t167 = sqrt(
      t159 + t12 * omega__body * (-0.2e1 * t8 - 0.2e1 * t9) + t165 + t20 + t21);
  const float_t t169 = t16 * pos__x__contact;
  const float_t t171 = 0.2e1 * t20 * t169;
  const float_t t172 = vx__body * vy__body;
  const float_t t174 = 0.12e2 * t172 * t108;
  const float_t t175 = 0.6e1 * t20;
  const float_t t176 = 0.6e1 * t21;
  const float_t t177 = -t175 + t176;
  const float_t t179 = pos__x__contact * t18 * t177;
  const float_t t182 = 0.4e1 * vy__body * vx__body * t110;
  const float_t t186 = t169 * Fy__body;
  const float_t t187 = vx__body * t186;
  const float_t t188 = 0.2e1 * t187;
  const float_t t189 = Fx__body * vx__body;
  const float_t t191 = Fy__body * vy__body;
  const float_t t193 = 0.6e1 * t189 - 0.6e1 * t191;
  const float_t t195 = t16 * pos__y__contact * t193;
  const float_t t198 = 0.6000000000e1 * t84 + 0.6000000000e1 * t86;
  const float_t t200 = pos__x__contact * t18 * t198;
  const float_t t201 = 0.2e1 * t189;
  const float_t t202 = 0.2e1 * t191;
  const float_t t203 = -t201 + t202;
  const float_t t204 = t110 * t203;
  const float_t t210 = 0.4e1 * vy__body * vx__body * t169;
  const float_t t211 = -t177;
  const float_t t213 = t16 * pos__y__contact * t211;
  const float_t t214 = t18 * pos__x__contact;
  const float_t t216 = 0.12e2 * t172 * t214;
  const float_t t217 = 0.2e1 * t20;
  const float_t t218 = 0.2e1 * t21;
  const float_t t219 = -t217 + t218;
  const float_t t221 = t110 * t219 - t210 + t213 + t216;
  const float_t t223 = t15 * t221 * t44;
  const float_t t226 = t52 * t5;
  const float_t t229 = t16 * pos__y__contact * t177;
  const float_t t230 = -t219;
  const float_t t232 = t110 * t230 + t210 - t216 + t229;
  const float_t t235 = -t203;
  const float_t t236 = t169 * t235;
  const float_t t238 = t16 * pos__y__contact * t198;
  const float_t t239 = -t193;
  const float_t t241 = pos__x__contact * t18 * t239;
  const float_t t244 = -0.2000000000e1 * t84 - 0.2000000000e1 * t86;
  const float_t t250 = t169 * t230 + t174 + t179 - t182;
  const float_t t252 = t15 * t250 * t44;
  const float_t t255 = pos__y__contact * t169;
  const float_t t256 = vx__body * t255;
  const float_t t257 = 0.2e1 * t256;
  const float_t t258 = t110 * pos__x__contact;
  const float_t t259 = vx__body * t258;
  const float_t t260 = 0.2e1 * t259;
  const float_t t261 = t18 * t18;
  const float_t t262 = vy__body * t261;
  const float_t t264 = t75 * omega__body;
  const float_t t267 = pos__y__contact * t186;
  const float_t t268 = 0.2e1 * t267;
  const float_t t269 = t110 * t36;
  const float_t t270 = 0.2e1 * t269;
  const float_t t271 = t261 * Fx__body;
  const float_t t275 = t16 * t16;
  const float_t t276 = t275 * Tz__body;
  const float_t t277 = vx__body * t276;
  const float_t t278 = 0.3e1 * t277;
  const float_t t279 = t169 * Tz__body;
  const float_t t280 = t9 * t279;
  const float_t t281 = 0.6e1 * t280;
  const float_t t283 = vy__body * t20;
  const float_t t285 = 0.5e1 * t283 * t16 * J__body;
  const float_t t286 = t110 * Tz__body;
  const float_t t287 = vy__body * t286;
  const float_t t288 = 0.6e1 * t287;
  const float_t t289 = t21 * vx__body;
  const float_t t290 = 0.2e1 * t289;
  const float_t t291 = t20 * vx__body;
  const float_t t293 = -t290 + 0.6e1 * t291;
  const float_t t298 = t261 * Tz__body;
  const float_t t299 = vx__body * t298;
  const float_t t300 = 0.3e1 * t299;
  const float_t t301 = 0.5e1 * t283;
  const float_t t302 = t21 * vy__body;
  const float_t t303 = t301 + t302;
  const float_t t310 = 0.5e1 * t20 * t39;
  const float_t t311 = vy__body * t189;
  const float_t t313 = t20 * Fy__body;
  const float_t t315 = t21 * Fy__body;
  const float_t t316 = 0.6e1 * t315;
  const float_t t317 = -0.8e1 * t311 - 0.6e1 * t313 - t316;
  const float_t t320 = 0.5e1 * t20;
  const float_t t327 = 0.3e1 * t291;
  const float_t t328 = t289 - t327;
  const float_t t332 = -0.10e2 * t283 - 0.2e1 * t302;
  const float_t t336 = -0.1e1 * t289 + t327;
  const float_t t344 = t169 * J__body;
  const float_t t345 = t75 * m__body;
  const float_t t354 = 0.2e1 * t106 *
                       (0.1000000000e1 * t21 * t345 +
                        0.1000000000e1 * vy__body * t33 * Fx__body) *
                       t344;
  const float_t t355 = vy__body * t258;
  const float_t t356 = 0.2e1 * t355;
  const float_t t357 = vy__body * t255;
  const float_t t358 = 0.2e1 * t357;
  const float_t t359 = vx__body * t275;
  const float_t t360 = vx__body * t261;
  const float_t t365 = t275 * Fy__body;
  const float_t t366 = 0.1e1 * t365;
  const float_t t367 = t261 * Fy__body;
  const float_t t369 = pos__y__contact * t169 * Fx__body;
  const float_t t370 = 0.2e1 * t369;
  const float_t t371 = t110 * t59;
  const float_t t372 = 0.2e1 * t371;
  const float_t t376 = vy__body * t276;
  const float_t t377 = 0.3e1 * t376;
  const float_t t378 = t2 * t279;
  const float_t t379 = 0.6e1 * t378;
  const float_t t380 = J__body * t336;
  const float_t t382 = vx__body * t286;
  const float_t t383 = 0.6e1 * t382;
  const float_t t384 = -t332;
  const float_t t389 = vy__body * t298;
  const float_t t390 = 0.3e1 * t389;
  const float_t t391 = J__body * t328;
  const float_t t399 = -0.4e1 * t311 - 0.3e1 * t313 - 0.3e1 * t315;
  const float_t t401 = 0.10e2 * t20;
  const float_t t402 = t401 + t218;
  const float_t t405 = -t399;
  const float_t t410 = 0.1e1 * t302;
  const float_t t411 = -t301 - t410;
  const float_t t421 = pos__y__contact * t276;
  const float_t t422 = 0.1e1 * t421;
  const float_t t424 = 0.3e1 * t20 * t344;
  const float_t t426 = t172 * J__body * pos__y__contact;
  const float_t t428 = 0.2e1 * t286;
  const float_t t429 = -0.11e2 * t426 - t428;
  const float_t t431 = 0.3e1 * t20;
  const float_t t432 = 0.4e1 * t21;
  const float_t t433 = t431 - t432;
  const float_t t436 = t110 * J__body;
  const float_t t437 = t172 * t436;
  const float_t t439 = t261 * pos__y__contact * Tz__body;
  const float_t t440 = 0.1e1 * t439;
  const float_t t444 = 0.3e1 * t187;
  const float_t t446 = 0.3e1 * t191;
  const float_t t447 = -0.8e1 * t189 + t446;
  const float_t t451 = 0.3e1 * t86;
  const float_t t452 = -0.4e1 * t84 - t451;
  const float_t t455 = -t201 - t446;
  const float_t t460 = t172 * t279;
  const float_t t461 = 0.7e1 * t460;
  const float_t t462 = 0.3e1 * t21;
  const float_t t463 = -t401 + t462;
  const float_t t466 = t18 * Tz__body;
  const float_t t467 = t172 * t466;
  const float_t t468 = 0.5e1 * t467;
  const float_t t470 = 0.1000000000e1 * t21 * t20;
  const float_t t471 = t20 * t20;
  const float_t t473 = t470 + 0.1000000000e1 * t471;
  const float_t t474 = J__body * t473;
  const float_t t478 = 0.4e1 * t20;
  const float_t t479 = -t478 - t462;
  const float_t t480 = t479 * Tz__body;
  const float_t t486 =
      0.1000000000e1 * vy__body * t291 + 0.1000000000e1 * t302 * vx__body;
  const float_t t487 = J__body * t486;
  const float_t t489 = 0.1e1 * pos__y__contact * t487;
  const float_t t493 = t20 * Fx__body;
  const float_t t494 = vy__body * t493;
  const float_t t495 = 0.2e1 * t494;
  const float_t t496 = t21 * t86;
  const float_t t497 = 0.3e1 * t496;
  const float_t t498 = t291 * Fy__body;
  const float_t t499 = t495 + t497 + t498;
  const float_t t501 = t21 * t189;
  const float_t t502 = 0.2e1 * t501;
  const float_t t503 = vy__body * t313;
  const float_t t504 = 0.3e1 * t503;
  const float_t t505 = t302 * Fy__body;
  const float_t t507 = t291 * Fx__body;
  const float_t t508 = 0.4e1 * t507;
  const float_t t509 = -t502 - t504 - 0.1e1 * t505 - t508;
  const float_t t514 = t20 + t21;
  const float_t t535 = t275 * pos__x__contact * Tz__body;
  const float_t t536 = 0.1e1 * t535;
  const float_t t537 = vx__body * J__body;
  const float_t t538 = vy__body * t537;
  const float_t t540 = 0.2e1 * t466;
  const float_t t541 = -0.3e1 * t538 - t540;
  const float_t t543 = -t218 + t431;
  const float_t t546 = 0.1e1 * t298;
  const float_t t547 = t29 * t537;
  const float_t t550 = t20 * t436;
  const float_t t555 = 0.4e1 * t189;
  const float_t t558 = -t85 - t451;
  const float_t t563 = t110 * t86;
  const float_t t568 = 0.1e1 * t21;
  const float_t t574 = pos__y__contact * t16 * Tz__body * t172;
  const float_t t575 = 0.7e1 * t574;
  const float_t t577 = 0.1e1 * t487;
  const float_t t580 = t286 * t172;
  const float_t t581 = 0.3e1 * t580;
  const float_t t582 = t20 * J__body;
  const float_t t583 = pos__y__contact * t514;
  const float_t t590 = -0.1e1 * t498 - t495 - t497;
  const float_t t597 = pos__y__contact * t486;
  const float_t t606 = t18 * t16;
  const float_t t607 = vy__body * t606;
  const float_t t613 = pos__y__contact * t72;
  const float_t t618 = 0.4e1 * t277;
  const float_t t619 = 0.3e1 * t280;
  const float_t t624 = 0.5e1 * vx__body * t466 + 0.3e1 * vy__body * t582;
  const float_t t626 = 0.3e1 * t287;
  const float_t t632 = 0.2e1 * t283 * t18 * J__body;
  const float_t t635 = t33 * gamma__5;
  const float_t t637 = 0.3e1 * t151;
  const float_t t638 = 0.6e1 * t493;
  const float_t t639 = t637 + t638;
  const float_t t647 = t15 * gamma__5;
  const float_t t650 = t290 + 0.4e1 * t291;
  const float_t t654 = 0.3e1 * t289;
  const float_t t661 = J__body * gamma__5;
  const float_t t662 = t514 * vx__body;
  const float_t t663 = t189 + t191;
  const float_t t666 =
      t167 *
          (t52 * (t33 * t32 * t26 + t15 * (-t38 - 0.1e1 * t39) * J__body +
                  omega__body * (t46 + t47) * t44) +
           t5 * (t12 * (t58 + t15 * (t61 - 0.1e1 * t62 + t64) * J__body +
                        omega__body * t32 * t44) +
                 t75 * t73 * m__body * t72 + t15 * (-0.1e1 * t78 + t80) * t26 +
                 omega__body *
                     (pos__x__contact * (-t85 + t86) -
                      0.1e1 * Fy__body * pos__y__contact * vy__body) *
                     J__body +
                 t10 * vy__body * t44) +
           t106 * (omega__body * vx__body * t44 - 0.1e1 * t15 * t101) * t18 +
           t12 * (-t115 -
                  0.1e1 * t15 *
                      (0.1000000000e1 * t116 +
                       0.1000000000e1 * t21 * pos__y__contact) *
                      t26 +
                  omega__body *
                      (-0.1e1 * vy__body * t36 +
                       pos__y__contact * (t85 - 0.1e1 * t86)) *
                      J__body -
                  0.1e1 * t78 * t44 + t80 * t44) +
           t33 * (t27 + 0.2e1 * t29 + t31) * t26 + t143 * t141 -
           0.1e1 * t146 * vy__body * t44 + J__body * (-0.1e1 * t149 + t151)) +
      t226 *
          (t75 * (t171 + t174 + t179 - t182) * t26 +
           t33 * (-t188 + t195 + t200 + t204) * J__body + t223) *
          gamma__5 +
      t52 *
          (t12 * (t75 * t232 * t26 +
                  t33 * (t110 * t244 + t236 + t238 + t241) * J__body + t252) +
           t264 * (t257 + t260 + t262) * t26 +
           t75 * (-t268 - t270 + t271) * J__body +
           t33 *
               (-t278 - t281 - t285 +
                pos__x__contact * (pos__y__contact * J__body * t293 - t288) +
                t300 + t18 * J__body * t303) *
               m__body +
           t15 *
               (-t310 + pos__x__contact * pos__y__contact * t317 +
                t18 * (t21 + t320) * Fx__body) *
               J__body +
           omega__body *
               (pos__x__contact * pos__y__contact * t332 + t16 * t328 +
                t18 * t336) *
               t44) *
          gamma__5 +
      t5 *
          (t354 +
           t12 * (t264 * (t356 + t358 + t359 - 0.1e1 * t360) * t26 +
                  t75 * (-t366 + t367 + t370 + t372) * J__body +
                  t33 *
                      (-t377 + t379 + t16 * t380 +
                       pos__x__contact *
                           (pos__y__contact * J__body * t384 + t383) +
                       t390 + t18 * t391) *
                      m__body +
                  t15 * (t142 * t402 * Fx__body + t16 * t399 + t18 * t405) *
                      J__body +
                  omega__body *
                      (pos__x__contact * pos__y__contact * t293 + t16 * t411 +
                       t18 * t303) *
                      t44) +
           t75 *
               (t214 * J__body * t433 + t16 * t429 - t422 - t424 + t437 -
                t440) *
               m__body +
           t33 *
               (t16 * pos__y__contact * t447 + pos__x__contact * t18 * t452 +
                t110 * t455 + t444) *
               J__body +
           t15 *
               (t461 + t108 * t463 * Tz__body +
                pos__x__contact * (-t468 - 0.1e1 * t474) + t110 * t480 - t489) *
               m__body +
           omega__body * (pos__x__contact * t499 + pos__y__contact * t509) *
               J__body +
           (pos__x__contact * t514 * t172 - 0.1e1 * pos__y__contact * t473) *
               t44) *
          gamma__5 +
      t106 * (m__body * omega__body * vy__body + Fx__body) * (t17 + t21) *
          gamma__5 * t16 * t15 * J__body +
      t12 *
          (t75 *
               (-t536 + t169 * t541 + t108 * J__body * t543 +
                pos__x__contact * (-t546 + t547) + t550) *
               m__body +
           t33 *
               (t169 * (-0.1e1 * t191 - t555) + t16 * pos__y__contact * t558 +
                pos__x__contact * t18 * t455 - 0.1e1 * t563) *
               J__body +
           t15 *
               (t169 * (-t175 - t568) * Tz__body - t575 +
                pos__x__contact * (t18 * t480 - t577) - t581 + t583 * t582) *
               m__body +
           omega__body * (pos__x__contact * t509 + pos__y__contact * t590) *
               J__body -
           0.1e1 *
               (0.1000000000e1 * pos__x__contact * t473 +
                0.1000000000e1 * t597) *
               t44) *
          gamma__5 +
      t264 * gamma__5 * (-0.1e1 * t256 + t607 - 0.1e1 * t259) * t26 +
      t75 * (t60 + t62 + t64) * gamma__5 * t613 +
      t635 *
          (t618 + t619 + t16 * t624 +
           pos__x__contact * (pos__y__contact * t391 + t626) - t632 + t299) *
          m__body +
      t647 *
          (t16 * t639 + pos__x__contact * pos__y__contact * t405 +
           t18 * (t637 + t493)) *
          J__body +
      omega__body * gamma__5 *
          (t16 * t650 + pos__x__contact * pos__y__contact * t303 +
           t18 * (t654 + t291)) *
          t44 +
      t663 * t662 * t661;
  const float_t t668 = tanh(t23 * gamma__5);
  const float_t t671 = pos__x__contact * t18 * t211;
  const float_t t676 = t16 * pos__y__contact * t239;
  const float_t t677 = -t198;
  const float_t t679 = pos__x__contact * t18 * t677;
  const float_t t680 = t110 * t235;
  const float_t t685 = t15 * t232 * t44;
  const float_t t691 = t169 * t203;
  const float_t t693 = t16 * pos__y__contact * t677;
  const float_t t695 = pos__x__contact * t18 * t193;
  const float_t t696 = -t244;
  const float_t t702 = t169 * t219 - t174 + t182 + t671;
  const float_t t704 = t15 * t702 * t44;
  const float_t t707 = 0.1e1 * t262;
  const float_t t711 = 0.1e1 * t271;
  const float_t t715 = -t293;
  const float_t t744 = 0.1e1 * t359;
  const float_t t793 = -t455;
  const float_t t805 = -t479 * Tz__body;
  const float_t t807 = t514 * vy__body;
  const float_t t809 = pos__y__contact * t807 * t537;
  const float_t t814 = t502 + t504 + t505 + t508;
  const float_t t819 = pos__x__contact * t486;
  const float_t t821 = t20 * pos__y__contact;
  const float_t t832 = t33 * m__body;
  const float_t t840 = t275 * Fx__body;
  const float_t t873 = t807 * t537;
  const float_t t902 = t75 * gamma__5;
  const float_t t928 = 0.1e1 * t291;
  const float_t t946 =
      t668 * t666 +
      t226 *
          (t75 * (-t171 - t174 + t671 + t182) * t26 +
           t33 * (t188 + t676 + t679 + t680) * J__body + t685) *
          gamma__5 +
      t52 *
          (t12 * (t75 * t221 * t26 +
                  t33 * (t110 * t696 + t691 + t693 + t695) * J__body + t704) +
           t264 * (-t257 - t260 - t707) * t26 +
           t75 * (t268 + t270 - t711) * J__body +
           t33 *
               (t278 + t281 + t285 +
                pos__x__contact * (pos__y__contact * J__body * t715 + t288) -
                t300 + t18 * J__body * t411) *
               m__body +
           t15 *
               (t310 - pos__x__contact * pos__y__contact * t317 +
                t18 * (-t568 - t320) * Fx__body) *
               J__body +
           omega__body *
               (pos__x__contact * pos__y__contact * t384 + t16 * t336 +
                t18 * t328) *
               t44) *
          gamma__5 +
      t5 *
          (-t354 +
           t12 * (t264 * (-t356 - t358 - t744 + t360) * t26 +
                  t75 * (t365 - 0.1e1 * t367 - t370 - t372) * J__body +
                  t33 *
                      (t377 - t379 + t16 * t391 +
                       pos__x__contact *
                           (pos__y__contact * J__body * t332 - t383) -
                       t390 + t18 * t380) *
                      m__body +
                  t15 * (-t142 * t402 * Fx__body + t16 * t405 + t18 * t399) *
                      J__body +
                  omega__body *
                      (pos__x__contact * pos__y__contact * t715 + t16 * t303 +
                       t18 * t411) *
                      t44) +
           t75 *
               (t421 + t424 - t16 * t429 - t214 * J__body * t433 -
                0.1e1 * t437 + t439) *
               m__body +
           t33 *
               (-t16 * pos__y__contact * t447 - pos__x__contact * t18 * t452 +
                t110 * t793 - t444) *
               J__body +
           t15 *
               (-t461 - t108 * t463 * Tz__body +
                pos__x__contact * (t514 * t582 + t468) + t110 * t805 + t809) *
               m__body +
           omega__body * (pos__x__contact * t590 + pos__y__contact * t814) *
               J__body +
           (-0.1e1 * t819 + t514 * t821) * t44) *
          gamma__5 -
      0.1e1 * t106 *
          (0.1000000000e1 * t264 * t275 * m__body * vy__body +
           0.1000000000e1 * t302 * t16 * t832 +
           0.1000000000e1 * t21 * t16 * t15 * Fx__body +
           0.1000000000e1 * t75 * t840) *
          t661 +
      t12 *
          (t75 *
               (t535 - t169 * t541 - t108 * J__body * t543 +
                pos__x__contact * (t298 - 0.1e1 * t547) - 0.1e1 * t550) *
               m__body +
           t33 *
               (t169 * (t191 + t555) - t16 * pos__y__contact * t558 +
                pos__x__contact * t18 * t793 + t563) *
               J__body +
           t15 *
               (t169 * (t175 + t21) * Tz__body + t575 +
                pos__x__contact * (t18 * t805 + t873) + t581 -
                0.1e1 * pos__y__contact * t474) *
               m__body +
           omega__body * (pos__y__contact * t499 + pos__x__contact * t814) *
               J__body +
           t10 * t662 * t44) *
          gamma__5 +
      t264 * gamma__5 * (t256 - 0.1e1 * t607 + t259) * t26 -
      0.1e1 * t902 *
          (0.1000000000e1 * t18 * t39 + 0.1000000000e1 * t267 +
           0.1000000000e1 * t269) *
          J__body +
      t635 *
          (-t618 - t619 - t16 * t624 +
           pos__x__contact * (pos__y__contact * t380 - t626) + t632 -
           0.1e1 * t299) *
          m__body +
      t647 *
          (-t16 * t639 + pos__x__contact * pos__y__contact * t399 +
           t18 * (-t637 - 0.1e1 * t493)) *
          J__body +
      omega__body * gamma__5 *
          (-t16 * t650 + pos__x__contact * pos__y__contact * t411 +
           t18 * (-t654 - t928)) *
          t44 +
      gamma__5 * J__body *
          (-0.1000000000e1 * t471 * Fx__body - 0.1000000000e1 * t21 * t493 -
           0.1000000000e1 * vy__body * t498 - 0.1000000000e1 * t302 * t86);
  const float_t t952 =
      t12 * omega__body * (-0.2000000000e1 * t8 - 0.2000000000e1 * t9);
  const float_t t953 = t159 + t952 + t165 + t20 + t21;
  const float_t t959 = t5 * omega__body * (0.2e-3 * t1 - 0.2e-3 * t2);
  const float_t t964 =
      t12 * omega__body * (-0.2000000000e-3 * t8 - 0.2000000000e-3 * t9);
  const float_t t968 = t15 * (0.1000000000e-3 * t16 + 0.1000000000e-3 * t18);
  const float_t t969 = 0.1e-3 * t20;
  const float_t t970 = 0.1e-3 * t21;
  const float_t t973 = 0.1e1 / m__body;
  const float_t t975 = 0.1e1 / J__body;
  const float_t tmp__1 = -t975 * t973 /
                         (t167 * t953 + t959 + t964 + t968 + t969 + t970) *
                         t946 * gamma__4 * t24;
  const float_t t990 = t18 * Fx__body;
  const float_t t1005 = 0.2e1 * t86;
  const float_t t1006 = -t1005 + t84;
  const float_t t1061 = 0.2e1 * t110 * t21;
  const float_t t1066 = vy__body * t110 * Fx__body;
  const float_t t1067 = 0.2e1 * t1066;
  const float_t t1088 = 0.5e1 * t289;
  const float_t t1089 = t291 + t1088;
  const float_t t1093 = 0.2e1 * t283;
  const float_t t1094 = 0.6e1 * t302 - t1093;
  const float_t t1099 = t21 * J__body;
  const float_t t1100 = t55 * t1099;
  const float_t t1101 = 0.5e1 * t1100;
  const float_t t1105 = 0.1e1 * t20;
  const float_t t1106 = 0.5e1 * t21;
  const float_t t1112 = t638 + 0.6e1 * t149 + 0.8e1 * t151;
  const float_t t1116 = 0.5e1 * t18 * t315;
  const float_t t1120 = 0.3e1 * t302;
  const float_t t1121 = t283 - t1120;
  const float_t t1125 = 0.2e1 * t291 + 0.10e2 * t289;
  const float_t t1129 = -0.1e1 * t283 + t1120;
  const float_t t1142 = 0.2e1 * vx__body * t33 * Fy__body - 0.2e1 * t20 * t345;
  const float_t t1145 = t275 * vy__body;
  const float_t t1152 = J__body * t1129;
  const float_t t1154 = -t1125;
  const float_t t1159 = J__body * t1121;
  const float_t t1167 = 0.4e1 * t151 + 0.3e1 * t149 + 0.3e1 * t493;
  const float_t t1169 = 0.10e2 * t21;
  const float_t t1170 = t217 + t1169;
  const float_t t1173 = -t1167;
  const float_t t1181 = -t1088 - t928;
  const float_t t1191 = t478 - t462;
  const float_t t1194 = 0.11e2 * t547;
  const float_t t1198 = 0.3e1 * t21 * t436;
  const float_t t1202 = 0.3e1 * t189;
  const float_t t1203 = -t1202 - t202;
  const float_t t1205 = 0.3e1 * t84;
  const float_t t1207 = -t1205 - 0.4e1 * t86;
  const float_t t1211 = t1202 - 0.8e1 * t191;
  const float_t t1214 = 0.3e1 * t1066;
  const float_t t1218 = -t432 - t431;
  const float_t t1219 = t1218 * Tz__body;
  const float_t t1221 = 0.5e1 * t574;
  const float_t t1222 = t431 - t1169;
  const float_t t1227 = 0.7e1 * t580;
  const float_t t1233 = 0.4e1 * t505;
  const float_t t1234 = 0.3e1 * t501;
  const float_t t1235 = 0.2e1 * t503;
  const float_t t1236 = -0.1e1 * t507 - t1233 - t1234 - t1235;
  const float_t t1238 = t302 * Fx__body;
  const float_t t1239 = 0.3e1 * t494;
  const float_t t1240 = 0.2e1 * t496;
  const float_t t1241 = t1238 + t1239 + t1240;
  const float_t t1246 = t21 * t21;
  const float_t t1248 = t470 + 0.1000000000e1 * t1246;
  const float_t t1259 = t20 * t18 * t15 * Fy__body;
  const float_t t1262 = t291 * t18 * t832;
  const float_t t1265 = t264 * t261 * vx__body * m__body;
  const float_t t1266 = t75 * t367;
  const float_t t1271 = t169 * t1099;
  const float_t t1274 = -t217 + t462;
  const float_t t1277 = 0.3e1 * t437;
  const float_t t1282 = Fx__body * t169 * vy__body;
  const float_t t1283 = -t1203;
  const float_t t1286 = t1205 + t1005;
  const float_t t1289 = 0.4e1 * t191;
  const float_t t1295 = 0.3e1 * t460;
  const float_t t1297 = -t1218 * Tz__body;
  const float_t t1299 = 0.7e1 * t467;
  const float_t t1310 = t1233 + t507 + t1234 + t1235;
  const float_t t1322 = vx__body * t606;
  const float_t t1336 = 0.3e1 * t378;
  const float_t t1341 = -0.5e1 * vy__body * t466 - 0.2e1 * vx__body * t1099;
  const float_t t1343 = 0.3e1 * t382;
  const float_t t1347 = 0.3e1 * t1100;
  const float_t t1348 = 0.4e1 * t389;
  const float_t t1352 = 0.3e1 * t311;
  const float_t t1358 = -t1352 - t316;
  const float_t t1363 = 0.3e1 * t283;
  const float_t t1369 = -t1093 - 0.4e1 * t302;
  const float_t t1386 =
      t23 * (t52 * (t58 + t15 * (t64 + t61) * J__body +
                    omega__body * (-t28 - t30) * t44) +
             t5 * (t12 * (t33 * (-0.1e1 * t31 + t29 + t28) * t26 +
                          t15 * (t38 + t39 - 0.1e1 * t990) * J__body +
                          omega__body * t56 * t44) -
                   t115 + t15 * (t116 - 0.1e1 * t821) * t26 +
                   omega__body *
                       (-0.1e1 * vx__body * t59 + pos__y__contact * t1006) *
                       J__body +
                   t10 * vx__body * t44) +
             t106 * (-0.1e1 * omega__body * vy__body * t44 + t15 * t141) * t16 +
             t12 * (-0.1e1 * t75 *
                        (0.1000000000e1 * t214 + 0.1000000000e1 * t169) * t26 -
                    0.1e1 * t15 *
                        (0.1000000000e1 * t78 +
                         0.1000000000e1 * pos__x__contact * t20) *
                        t26 +
                    omega__body *
                        (Fx__body * pos__y__contact * vx__body +
                         pos__x__contact * t1006) *
                        J__body -
                    0.1e1 * t821 * t44 + t116 * t44) +
             t33 * (t55 + t45 + 0.2e1 * t47) * t26 - 0.1e1 * t143 * t101 +
             t146 * vx__body * Tz__body * m__body +
             J__body * (-0.1e1 * t311 + t313)) +
      t226 *
          (t75 * (t210 + t229 - t216 - t1061) * t26 +
           t33 * (t236 + t238 + t241 - t1067) * J__body + t252) *
          gamma__5 +
      t52 *
          (t12 * (t75 * t702 * t26 +
                  t33 * (t169 * t696 + t676 + t679 + t680) * J__body + t685) +
           t264 * (t356 + t359 + t358) * t26 +
           t75 * (t370 + t372 - t366) * J__body +
           t33 *
               (-t377 + t379 + t16 * J__body * t1089 +
                pos__x__contact * (pos__y__contact * J__body * t1094 + t383) -
                t1101 + t390) *
               m__body +
           t15 *
               (t16 * (-t1105 - t1106) * Fy__body +
                pos__x__contact * pos__y__contact * t1112 + t1116) *
               J__body +
           omega__body *
               (pos__x__contact * pos__y__contact * t1125 + t16 * t1121 +
                t18 * t1129) *
               t44) *
          gamma__5 +
      t5 *
          (t106 * t1142 * t436 +
           t12 * (t264 * (-t257 - t260 + t1145 - t707) * t26 +
                  t75 * (t840 + t268 + t270 - t711) * J__body +
                  t33 *
                      (t278 + t281 + t16 * t1152 +
                       pos__x__contact *
                           (pos__y__contact * J__body * t1154 + t288) -
                       t300 + t18 * t1159) *
                      m__body +
                  t15 * (t142 * t1170 * Fy__body + t16 * t1167 + t18 * t1173) *
                      J__body +
                  omega__body *
                      (pos__x__contact * pos__y__contact * t1094 + t16 * t1089 +
                       t18 * t1181) *
                      t44) +
           t75 *
               (-t536 + t169 * (-t540 - 0.1e1 * t538) + t108 * J__body * t1191 +
                pos__x__contact * (-t546 + t1194) + t1198) *
               m__body +
           t33 *
               (t16 * pos__y__contact * t1207 + pos__x__contact * t18 * t1211 +
                t169 * t1203 + t1214) *
               J__body +
           t15 *
               (t169 * t1219 - t1221 +
                pos__x__contact * (t18 * t1222 * Tz__body + t873) + t1227 +
                t583 * t1099) *
               m__body +
           omega__body * (pos__x__contact * t1236 + pos__y__contact * t1241) *
               J__body +
           (-0.1e1 * pos__x__contact * t1248 + t807 * t2) * t44) *
          gamma__5 +
      t106 * (-0.1e1 * t1259 + t1262 + t1265 - 0.1e1 * t1266) * t661 +
      t12 *
          (t75 *
               (t421 + t1271 + t16 * (t426 + t428) + t214 * J__body * t1274 -
                t1277 + t439) *
               m__body +
           t33 *
               (t1282 + t16 * pos__y__contact * t1283 +
                pos__x__contact * t18 * t1286 + t110 * (t189 + t1289)) *
               J__body +
           t15 *
               (t1295 + t108 * t1297 +
                pos__x__contact * (t514 * t1099 + t1299) +
                t110 * (t20 + t176) * Tz__body - t489) *
               m__body +
           omega__body * (pos__x__contact * t1241 + pos__y__contact * t1310) *
               J__body +
           t10 * t807 * t44) *
          gamma__5 +
      t264 * gamma__5 * (-0.1e1 * t355 - 0.1e1 * t357 + t1322) * t26 -
      0.1e1 * t902 *
          (0.1000000000e1 * t18 * t62 + 0.1000000000e1 * t369 +
           0.1000000000e1 * t371) *
          J__body +
      t635 *
          (-0.1e1 * t376 - t1336 + t16 * t1341 +
           pos__x__contact * (pos__y__contact * t1159 - t1343) + t1347 -
           t1348) *
          m__body +
      t647 *
          (t16 * (-t1352 - 0.1e1 * t315) +
           pos__x__contact * pos__y__contact * t1173 + t18 * t1358) *
          J__body +
      omega__body * gamma__5 *
          (t16 * (-t1363 - t410) + pos__x__contact * pos__y__contact * t1181 +
           t18 * t1369) *
          t44 +
      gamma__5 * J__body *
          (-0.1000000000e1 * vy__body * t507 - 0.1000000000e1 * t302 * t189 -
           0.1000000000e1 * t21 * t313 - 0.1000000000e1 * t1246 * Fy__body);
  const float_t t1413 = -t1094;
  const float_t t1503 = J__body * t1248;
  const float_t t1511 = -0.1e1 * t1238 - t1239 - t1240;
  const float_t t1613 =
      t668 * t1386 +
      t226 *
          (t75 * (-t210 + t213 + t216 + t1061) * t26 +
           t33 * (t691 + t693 + t695 + t1067) * J__body + t704) *
          gamma__5 +
      t52 *
          (t12 * (t75 * t250 * t26 +
                  t33 * (t169 * t244 + t195 + t200 + t204) * J__body + t223) +
           t264 * (-t356 - t744 - t358) * t26 +
           t75 * (-t370 - t372 + t365) * J__body +
           t33 *
               (t377 - t379 + t16 * J__body * t1181 +
                pos__x__contact * (pos__y__contact * J__body * t1413 - t383) +
                t1101 - t390) *
               m__body +
           t15 *
               (t16 * (t20 + t1106) * Fy__body -
                pos__x__contact * pos__y__contact * t1112 - t1116) *
               J__body +
           omega__body *
               (pos__x__contact * pos__y__contact * t1154 + t18 * t1121 +
                t16 * t1129) *
               t44) *
          gamma__5 +
      t5 *
          (-t106 * t1142 * t436 +
           t12 * (t264 * (t257 + t260 - 0.1e1 * t1145 + t262) * t26 +
                  t75 * (-0.1e1 * t840 - t268 - t270 + t271) * J__body +
                  t33 *
                      (-t278 - t281 + t16 * t1159 +
                       pos__x__contact *
                           (pos__y__contact * J__body * t1125 - t288) +
                       t300 + t18 * t1152) *
                      m__body +
                  t15 * (-t142 * t1170 * Fy__body + t18 * t1167 + t16 * t1173) *
                      J__body +
                  omega__body *
                      (pos__x__contact * pos__y__contact * t1413 + t18 * t1089 +
                       t16 * t1181) *
                      t44) +
           t75 *
               (t535 + t169 * (t540 + t538) - t108 * J__body * t1191 +
                pos__x__contact * (t298 - t1194) - t1198) *
               m__body +
           t33 *
               (-t16 * pos__y__contact * t1207 - pos__x__contact * t18 * t1211 +
                t169 * t1283 - t1214) *
               J__body +
           t15 *
               (t169 * t1297 + t1221 +
                pos__x__contact * (-t18 * t1222 * Tz__body - t577) - t1227 -
                0.1e1 * pos__y__contact * t1503) *
               m__body +
           omega__body * (pos__x__contact * t1310 + pos__y__contact * t1511) *
               J__body +
           (pos__x__contact * t514 * t21 - 0.1e1 * t597) * t44) *
          gamma__5 +
      t106 * (t1259 - 0.1e1 * t1262 - 0.1e1 * t1265 + t1266) * t661 +
      t12 *
          (t75 *
               (-t422 - 0.1e1 * t1271 + t16 * (-0.1e1 * t426 - t428) -
                t214 * J__body * t1274 + t1277 - t440) *
               m__body +
           t33 *
               (-0.1e1 * t1282 + t16 * pos__y__contact * t1203 -
                pos__x__contact * t18 * t1286 +
                t110 * (-0.1e1 * t189 - t1289)) *
               J__body +
           t15 *
               (-t1295 + t108 * t1219 +
                pos__x__contact * (-t1299 - 0.1e1 * t1503) +
                t110 * (-t1105 - t176) * Tz__body + t809) *
               m__body +
           omega__body * (pos__y__contact * t1236 + pos__x__contact * t1511) *
               J__body -
           0.1e1 *
               (0.1000000000e1 * t819 +
                0.1000000000e1 * pos__y__contact * t1248) *
               t44) *
          gamma__5 +
      t264 * gamma__5 * (t355 + t357 - 0.1e1 * t1322) * t26 +
      t75 * (t39 + t990 + t37) * gamma__5 * t613 +
      t635 *
          (t376 + t1336 - t16 * t1341 +
           pos__x__contact * (pos__y__contact * t1152 + t1343) - t1347 +
           t1348) *
          m__body +
      t647 *
          (t16 * (t1352 + t315) + pos__x__contact * pos__y__contact * t1167 -
           t18 * t1358) *
          J__body +
      omega__body * gamma__5 *
          (t16 * (t302 + t1363) + pos__x__contact * pos__y__contact * t1089 -
           t18 * t1369) *
          t44 +
      t663 * t807 * t661;
  const float_t t1622 =
      sqrt(t5 * omega__body * (0.2000000000e1 * t1 - 0.2000000000e1 * t2) +
           t952 + t165 + t20 + t21);
  const float_t tmp__2 = t975 * t973 /
                         (t1622 * t953 + t959 + t964 + t968 + t969 + t970) *
                         gamma__4 * t1613 * t24;
  const float_t t1630 = sqrt(t73);
  const float_t tmp__3 = -t1630 * gamma__5 * (-1 + t668) * gamma__4;

  func(0) = tmp__1;
  func(1) = tmp__2;
  func(2) = tmp__3;

  return func;
}

Matrix contact_force_dt1_dx(VectorRef x, VectorRef u) {
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

Matrix contact_force_dt1_du(VectorRef x, VectorRef u) {
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
