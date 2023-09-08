#include <maple_codegen/contact_force_dt3.hpp>
#include <maple_codegen/contact_force_dt3_params.hpp>
#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector contact_force_dt3(VectorRef x, VectorRef u) {
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
      sqrt(-2 * t5 * t3 * omega__body + 2 * t12 * (t8 - t9) * omega__body +
           t17 + t18 * t15 + t20 + t21);
  const float_t t25 = 0.1e1 / t23 * gamma__4;
  const float_t t26 = J__body * m__body;
  const float_t t27 = t16 * vy__body;
  const float_t t28 = t18 * vy__body;
  const float_t t29 = 0.1e1 * t28;
  const float_t t30 = pos__y__contact * t8;
  const float_t t31 = 0.2e1 * t30;
  const float_t t32 = t27 - t29 + t31;
  const float_t t33 = t15 * omega__body;
  const float_t t36 = t16 * Fx__body;
  const float_t t38 = Fy__body * pos__x__contact;
  const float_t t40 = 0.2e1 * pos__y__contact * t38;
  const float_t t44 = m__body * Tz__body;
  const float_t t45 = vx__body * t16;
  const float_t t46 = pos__y__contact * t1;
  const float_t t47 = 0.2e1 * t46;
  const float_t t52 = t5 * t5;
  const float_t t55 = vx__body * t18;
  const float_t t56 = -0.1e1 * t45 + t47 + t55;
  const float_t t58 = t33 * t56 * t26;
  const float_t t59 = t16 * Fy__body;
  const float_t t61 = t18 * Fy__body;
  const float_t t62 = Fx__body * pos__x__contact;
  const float_t t64 = 0.2e1 * pos__y__contact * t62;
  const float_t t72 = t18 * pos__x__contact;
  const float_t t74 = t16 * pos__x__contact;
  const float_t t77 = t15 * t15;
  const float_t t81 = t21 * pos__x__contact;
  const float_t t83 = vy__body * t2;
  const float_t t89 = Fx__body * vy__body;
  const float_t t90 = 0.2e1 * t89;
  const float_t t91 = Fy__body * vx__body;
  const float_t t93 = t90 - 0.1e1 * t91;
  const float_t t101 = vy__body * t8;
  const float_t t103 = 0.1e1 * t101 * t44;
  const float_t t104 = t21 * pos__y__contact;
  const float_t t110 = Fx__body * J__body;
  const float_t t115 = t12 * t12;
  const float_t t117 = pos__y__contact * t16;
  const float_t t119 = t18 * pos__y__contact;
  const float_t t124 =
      0.1e1 * t77 * (0.1000000000e1 * t117 + 0.1000000000e1 * t119) * t26;
  const float_t t134 = t83 * t44;
  const float_t t145 = Fy__body * J__body;
  const float_t t146 = pos__x__contact * pos__y__contact;
  const float_t t147 = t15 * t146;
  const float_t t151 = omega__body * t146;
  const float_t t153 = t21 * Fx__body;
  const float_t t155 = vy__body * t91;
  const float_t t161 = 0.2e1 * t20 * t74;
  const float_t t162 = vx__body * vy__body;
  const float_t t164 = 0.12e2 * t162 * t117;
  const float_t t165 = 0.6e1 * t20;
  const float_t t166 = 0.6e1 * t21;
  const float_t t167 = t165 - t166;
  const float_t t169 = pos__x__contact * t18 * t167;
  const float_t t172 = 0.4e1 * vy__body * vx__body * t119;
  const float_t t176 = t74 * Fy__body;
  const float_t t177 = vx__body * t176;
  const float_t t178 = 0.2e1 * t177;
  const float_t t179 = Fx__body * vx__body;
  const float_t t181 = Fy__body * vy__body;
  const float_t t183 = 0.6e1 * t179 - 0.6e1 * t181;
  const float_t t185 = t16 * pos__y__contact * t183;
  const float_t t188 = -0.6000000000e1 * t89 - 0.6000000000e1 * t91;
  const float_t t190 = pos__x__contact * t18 * t188;
  const float_t t191 = 0.2e1 * t179;
  const float_t t192 = 0.2e1 * t181;
  const float_t t193 = -t191 + t192;
  const float_t t194 = t119 * t193;
  const float_t t200 = 0.4e1 * vy__body * vx__body * t74;
  const float_t t202 = t16 * pos__y__contact * t167;
  const float_t t204 = 0.12e2 * t162 * t72;
  const float_t t205 = 0.2e1 * t20;
  const float_t t206 = 0.2e1 * t21;
  const float_t t207 = -t205 + t206;
  const float_t t209 = t119 * t207 + t200 + t202 - t204;
  const float_t t211 = t15 * t209 * t44;
  const float_t t214 = t52 * t5;
  const float_t t216 = -t167;
  const float_t t218 = t16 * pos__y__contact * t216;
  const float_t t219 = -t207;
  const float_t t221 = t119 * t219 - t200 + t204 + t218;
  const float_t t224 = t74 * t193;
  const float_t t225 = -t188;
  const float_t t227 = t16 * pos__y__contact * t225;
  const float_t t229 = pos__x__contact * t18 * t183;
  const float_t t232 = -0.2000000000e1 * t89 - 0.2000000000e1 * t91;
  const float_t t238 = t74 * t207 + t164 + t169 - t172;
  const float_t t240 = t15 * t238 * t44;
  const float_t t243 = t18 * t18;
  const float_t t244 = vy__body * t243;
  const float_t t245 = pos__y__contact * t74;
  const float_t t246 = vx__body * t245;
  const float_t t247 = 0.2e1 * t246;
  const float_t t248 = t119 * pos__x__contact;
  const float_t t249 = vx__body * t248;
  const float_t t250 = 0.2e1 * t249;
  const float_t t252 = t77 * omega__body;
  const float_t t255 = t243 * Fx__body;
  const float_t t256 = pos__y__contact * t176;
  const float_t t257 = 0.2e1 * t256;
  const float_t t258 = t119 * t38;
  const float_t t259 = 0.2e1 * t258;
  const float_t t263 = t16 * t16;
  const float_t t264 = t263 * Tz__body;
  const float_t t265 = vx__body * t264;
  const float_t t266 = 0.3e1 * t265;
  const float_t t267 = t74 * Tz__body;
  const float_t t268 = t9 * t267;
  const float_t t269 = 0.6e1 * t268;
  const float_t t271 = vy__body * t20;
  const float_t t273 = 0.5e1 * t271 * t16 * J__body;
  const float_t t274 = t119 * Tz__body;
  const float_t t275 = vy__body * t274;
  const float_t t276 = 0.6e1 * t275;
  const float_t t277 = t21 * vx__body;
  const float_t t278 = 0.2e1 * t277;
  const float_t t279 = t20 * vx__body;
  const float_t t281 = t278 - 0.6e1 * t279;
  const float_t t286 = t243 * Tz__body;
  const float_t t287 = vx__body * t286;
  const float_t t288 = 0.3e1 * t287;
  const float_t t289 = 0.5e1 * t271;
  const float_t t290 = t21 * vy__body;
  const float_t t291 = t289 + t290;
  const float_t t298 = 0.5e1 * t20 * t36;
  const float_t t299 = vy__body * t179;
  const float_t t301 = t20 * Fy__body;
  const float_t t303 = t21 * Fy__body;
  const float_t t304 = 0.6e1 * t303;
  const float_t t305 = 0.8e1 * t299 + 0.6e1 * t301 + t304;
  const float_t t308 = 0.5e1 * t20;
  const float_t t315 = 0.3e1 * t279;
  const float_t t316 = t277 - t315;
  const float_t t320 = 0.10e2 * t271 + 0.2e1 * t290;
  const float_t t324 = -0.1e1 * t277 + t315;
  const float_t t332 = t74 * J__body;
  const float_t t333 = t77 * m__body;
  const float_t t342 = 0.2e1 * t115 *
                       (0.1000000000e1 * t21 * t333 +
                        0.1000000000e1 * vy__body * t33 * Fx__body) *
                       t332;
  const float_t t343 = vy__body * t248;
  const float_t t344 = 0.2e1 * t343;
  const float_t t345 = vx__body * t263;
  const float_t t346 = vx__body * t243;
  const float_t t348 = vy__body * t245;
  const float_t t349 = 0.2e1 * t348;
  const float_t t353 = t243 * Fy__body;
  const float_t t355 = pos__y__contact * t74 * Fx__body;
  const float_t t356 = 0.2e1 * t355;
  const float_t t357 = t119 * t62;
  const float_t t358 = 0.2e1 * t357;
  const float_t t359 = t263 * Fy__body;
  const float_t t360 = 0.1e1 * t359;
  const float_t t364 = vy__body * t264;
  const float_t t365 = 0.3e1 * t364;
  const float_t t366 = t2 * t267;
  const float_t t367 = 0.6e1 * t366;
  const float_t t368 = J__body * t324;
  const float_t t370 = vx__body * t274;
  const float_t t371 = 0.6e1 * t370;
  const float_t t372 = -t320;
  const float_t t377 = vy__body * t286;
  const float_t t378 = 0.3e1 * t377;
  const float_t t379 = J__body * t316;
  const float_t t387 = -0.4e1 * t299 - 0.3e1 * t301 - 0.3e1 * t303;
  const float_t t389 = 0.10e2 * t20;
  const float_t t390 = -t389 - t206;
  const float_t t393 = -t387;
  const float_t t398 = 0.1e1 * t290;
  const float_t t399 = -t289 - t398;
  const float_t t409 = pos__y__contact * t264;
  const float_t t410 = 0.1e1 * t409;
  const float_t t412 = 0.3e1 * t20 * t332;
  const float_t t414 = t162 * J__body * pos__y__contact;
  const float_t t416 = 0.2e1 * t274;
  const float_t t417 = -0.11e2 * t414 - t416;
  const float_t t419 = 0.3e1 * t20;
  const float_t t420 = 0.4e1 * t21;
  const float_t t421 = -t419 + t420;
  const float_t t424 = t119 * J__body;
  const float_t t425 = t162 * t424;
  const float_t t427 = t243 * pos__y__contact * Tz__body;
  const float_t t428 = 0.1e1 * t427;
  const float_t t432 = 0.3e1 * t177;
  const float_t t434 = 0.3e1 * t181;
  const float_t t435 = -0.8e1 * t179 + t434;
  const float_t t439 = 0.3e1 * t91;
  const float_t t440 = 0.4e1 * t89 + t439;
  const float_t t443 = -t191 - t434;
  const float_t t448 = t162 * t267;
  const float_t t449 = 0.7e1 * t448;
  const float_t t450 = 0.3e1 * t21;
  const float_t t451 = -t389 + t450;
  const float_t t454 = t18 * Tz__body;
  const float_t t455 = t162 * t454;
  const float_t t456 = 0.5e1 * t455;
  const float_t t457 = t20 * J__body;
  const float_t t458 = t20 + t21;
  const float_t t462 = 0.4e1 * t20;
  const float_t t463 = -t462 - t450;
  const float_t t464 = t463 * Tz__body;
  const float_t t470 =
      0.1000000000e1 * vy__body * t279 + 0.1000000000e1 * t290 * vx__body;
  const float_t t471 = J__body * t470;
  const float_t t473 = 0.1e1 * pos__y__contact * t471;
  const float_t t477 = t279 * Fy__body;
  const float_t t479 = t20 * Fx__body;
  const float_t t480 = vy__body * t479;
  const float_t t481 = 0.2e1 * t480;
  const float_t t482 = t21 * t91;
  const float_t t483 = 0.3e1 * t482;
  const float_t t484 = -0.1e1 * t477 - t481 - t483;
  const float_t t486 = t21 * t179;
  const float_t t487 = 0.2e1 * t486;
  const float_t t488 = vy__body * t301;
  const float_t t489 = 0.3e1 * t488;
  const float_t t490 = t290 * Fy__body;
  const float_t t492 = t279 * Fx__body;
  const float_t t493 = 0.4e1 * t492;
  const float_t t494 = -t487 - t489 - 0.1e1 * t490 - t493;
  const float_t t499 = pos__x__contact * t470;
  const float_t t502 = 0.1000000000e1 * t21 * t20;
  const float_t t503 = t20 * t20;
  const float_t t505 = t502 + 0.1000000000e1 * t503;
  const float_t t525 = t263 * pos__x__contact * Tz__body;
  const float_t t526 = vx__body * J__body;
  const float_t t527 = vy__body * t526;
  const float_t t529 = 0.2e1 * t454;
  const float_t t530 = 0.3e1 * t527 + t529;
  const float_t t532 = -t206 + t419;
  const float_t t535 = t28 * t526;
  const float_t t539 = t20 * t424;
  const float_t t543 = 0.4e1 * t179;
  const float_t t546 = -t90 - t439;
  const float_t t549 = -t443;
  const float_t t552 = t119 * t91;
  const float_t t562 = pos__y__contact * t16 * Tz__body * t162;
  const float_t t563 = 0.7e1 * t562;
  const float_t t565 = -t463 * Tz__body;
  const float_t t567 = t458 * vy__body;
  const float_t t568 = t567 * t526;
  const float_t t571 = t274 * t162;
  const float_t t572 = 0.3e1 * t571;
  const float_t t573 = pos__y__contact * t458;
  const float_t t578 = t487 + t489 + t490 + t493;
  const float_t t586 = pos__y__contact * t470;
  const float_t t593 = pos__x__contact * J__body;
  const float_t t594 = pos__y__contact * t593;
  const float_t t595 = m__body * gamma__5;
  const float_t t600 = t18 * t36;
  const float_t t605 = t77 * gamma__5;
  const float_t t607 = 0.4e1 * t265;
  const float_t t608 = 0.3e1 * t268;
  const float_t t613 = 0.5e1 * vx__body * t454 + 0.3e1 * vy__body * t457;
  const float_t t615 = 0.3e1 * t275;
  const float_t t621 = 0.2e1 * t271 * t18 * J__body;
  const float_t t624 = t33 * gamma__5;
  const float_t t626 = 0.3e1 * t155;
  const float_t t627 = 0.6e1 * t479;
  const float_t t628 = t626 + t627;
  const float_t t636 = t15 * gamma__5;
  const float_t t639 = t278 + 0.4e1 * t279;
  const float_t t643 = 0.3e1 * t277;
  const float_t t650 = J__body * gamma__5;
  const float_t t651 = t458 * vx__body;
  const float_t t652 = t179 + t181;
  const float_t t655 =
      t23 *
          (t52 * (t33 * t32 * t26 + t15 * (-0.1e1 * t36 + t40) * J__body +
                  omega__body * (t45 - t47) * t44) +
           t5 * (t12 * (t58 + t15 * (-0.1e1 * t59 + t61 - t64) * J__body +
                        omega__body * t32 * t44) -
                 0.1e1 * t77 * (0.1000000000e1 * t72 + 0.1000000000e1 * t74) *
                     t26 -
                 0.1e1 * t15 * (0.1000000000e1 * t81 + 0.1000000000e1 * t83) *
                     t26 +
                 omega__body *
                     (pos__x__contact * t93 -
                      0.1e1 * Fy__body * pos__y__contact * vy__body) *
                     J__body -
                 t103 + t104 * t44) +
           t115 * (omega__body * vx__body * t44 - 0.1e1 * t15 * t110) * t18 +
           t12 * (-t124 + t15 * (-0.1e1 * t104 + t101) * t26 +
                  omega__body * (vy__body * t38 + pos__y__contact * t93) *
                      J__body -
                  0.1e1 * t134 - 0.1e1 * t81 * t44) +
           t33 * (0.2e1 * t28 + t27 - 0.1e1 * t30) * t26 - 0.1e1 * t147 * t145 +
           t151 * vy__body * t44 + J__body * (-0.1e1 * t153 + t155)) +
      t214 *
          (t77 * (-t161 + t164 + t169 - t172) * t26 +
           t33 * (t178 + t185 + t190 + t194) * J__body + t211) *
          gamma__5 +
      t52 *
          (t12 * (t77 * t221 * t26 +
                  t33 * (t119 * t232 + t224 + t227 + t229) * J__body + t240) +
           t252 * (t244 - t247 - t250) * t26 +
           t77 * (t255 + t257 + t259) * J__body +
           t33 *
               (-t266 + t269 - t273 +
                pos__x__contact * (pos__y__contact * J__body * t281 + t276) +
                t288 + t18 * J__body * t291) *
               m__body +
           t15 *
               (-t298 + pos__x__contact * pos__y__contact * t305 +
                t18 * (t21 + t308) * Fx__body) *
               J__body +
           omega__body *
               (pos__x__contact * pos__y__contact * t320 + t16 * t316 +
                t18 * t324) *
               t44) *
          gamma__5 +
      t5 *
          (-t342 +
           t12 * (t252 * (-t344 + t345 - 0.1e1 * t346 - t349) * t26 +
                  t77 * (t353 - t356 - t358 - t360) * J__body +
                  t33 *
                      (-t365 - t367 + t16 * t368 +
                       pos__x__contact *
                           (pos__y__contact * J__body * t372 - t371) +
                       t378 + t18 * t379) *
                      m__body +
                  t15 * (t146 * t390 * Fx__body + t16 * t387 + t18 * t393) *
                      J__body +
                  omega__body *
                      (pos__x__contact * pos__y__contact * t281 + t16 * t399 +
                       t18 * t291) *
                      t44) +
           t77 *
               (t72 * J__body * t421 + t16 * t417 - t410 + t412 + t425 - t428) *
               m__body +
           t33 *
               (t16 * pos__y__contact * t435 + pos__x__contact * t18 * t440 +
                t119 * t443 - t432) *
               J__body +
           t15 *
               (-t449 + t117 * t451 * Tz__body +
                pos__x__contact * (t458 * t457 + t456) + t119 * t464 - t473) *
               m__body +
           omega__body * (pos__x__contact * t484 + pos__y__contact * t494) *
               J__body -
           0.1e1 *
               (0.1000000000e1 * t499 +
                0.1000000000e1 * pos__y__contact * t505) *
               t44) *
          gamma__5 +
      t115 * (m__body * omega__body * vy__body + Fx__body) * (t17 + t21) *
          gamma__5 * t16 * t15 * J__body +
      t12 *
          (t77 *
               (t525 + t74 * t530 + t117 * J__body * t532 +
                pos__x__contact * (t286 - 0.1e1 * t535) + t539) *
               m__body +
           t33 *
               (t74 * (t181 + t543) + t16 * pos__y__contact * t546 +
                pos__x__contact * t18 * t549 - 0.1e1 * t552) *
               J__body +
           t15 *
               (t74 * (t165 + t21) * Tz__body - t563 +
                pos__x__contact * (t18 * t565 + t568) - t572 + t573 * t457) *
               m__body +
           omega__body * (pos__y__contact * t484 + pos__x__contact * t578) *
               J__body +
           (pos__x__contact * t458 * t20 - 0.1e1 * t586) * t44) *
          gamma__5 +
      t252 * (t45 + t46 + t55) * t595 * t594 +
      t605 * (t600 - 0.1e1 * t256 - 0.1e1 * t258) * J__body +
      t624 *
          (t607 - t608 + t16 * t613 +
           pos__x__contact * (pos__y__contact * t368 - t615) - t621 + t287) *
          m__body +
      t636 *
          (t16 * t628 + pos__x__contact * pos__y__contact * t387 +
           t18 * (t626 + t479)) *
          J__body +
      omega__body * gamma__5 *
          (t16 * t639 + pos__x__contact * pos__y__contact * t399 +
           t18 * (t643 + t279)) *
          t44 +
      t652 * t651 * t650;
  const float_t t657 = tanh(t23 * gamma__5);
  const float_t t660 = pos__x__contact * t18 * t216;
  const float_t t664 = -t183;
  const float_t t666 = t16 * pos__y__contact * t664;
  const float_t t668 = pos__x__contact * t18 * t225;
  const float_t t669 = -t193;
  const float_t t670 = t119 * t669;
  const float_t t675 = t15 * t221 * t44;
  const float_t t681 = t74 * t669;
  const float_t t683 = t16 * pos__y__contact * t188;
  const float_t t685 = pos__x__contact * t18 * t664;
  const float_t t686 = -t232;
  const float_t t692 = t74 * t219 - t164 + t172 + t660;
  const float_t t694 = t15 * t692 * t44;
  const float_t t697 = 0.1e1 * t244;
  const float_t t701 = 0.1e1 * t255;
  const float_t t705 = -t281;
  const float_t t718 = 0.1e1 * t21;
  const float_t t735 = 0.1e1 * t345;
  const float_t t791 = J__body * t505;
  const float_t t797 = pos__y__contact * t567 * t526;
  const float_t t801 = t481 + t483 + t477;
  const float_t t816 = t33 * m__body;
  const float_t t824 = t263 * Fx__body;
  const float_t t831 = 0.1e1 * t525;
  const float_t t837 = 0.1e1 * t286;
  const float_t t859 = 0.1e1 * t471;
  const float_t t881 = t18 * t16;
  const float_t t917 = 0.1e1 * t279;
  const float_t t935 =
      t657 * t655 +
      t214 *
          (t77 * (t161 - t164 + t660 + t172) * t26 +
           t33 * (-t178 + t666 + t668 + t670) * J__body + t675) *
          gamma__5 +
      t52 *
          (t12 * (t77 * t209 * t26 +
                  t33 * (t119 * t686 + t681 + t683 + t685) * J__body + t694) +
           t252 * (-t697 + t247 + t250) * t26 +
           t77 * (-t701 - t257 - t259) * J__body +
           t33 *
               (t266 - t269 + t273 +
                pos__x__contact * (pos__y__contact * J__body * t705 - t276) -
                t288 + t18 * J__body * t399) *
               m__body +
           t15 *
               (t298 - pos__x__contact * pos__y__contact * t305 +
                t18 * (-t718 - t308) * Fx__body) *
               J__body +
           omega__body *
               (pos__x__contact * pos__y__contact * t372 + t16 * t324 +
                t18 * t316) *
               t44) *
          gamma__5 +
      t5 *
          (t342 +
           t12 * (t252 * (t344 - t735 + t346 + t349) * t26 +
                  t77 * (-0.1e1 * t353 + t356 + t358 + t359) * J__body +
                  t33 *
                      (t365 + t367 + t16 * t379 +
                       pos__x__contact *
                           (pos__y__contact * J__body * t320 + t371) -
                       t378 + t18 * t368) *
                      m__body +
                  t15 * (-t146 * t390 * Fx__body + t16 * t393 + t18 * t387) *
                      J__body +
                  omega__body *
                      (pos__x__contact * pos__y__contact * t705 + t16 * t291 +
                       t18 * t399) *
                      t44) +
           t77 *
               (t409 - t412 - t16 * t417 - t72 * J__body * t421 - 0.1e1 * t425 +
                t427) *
               m__body +
           t33 *
               (-t16 * pos__y__contact * t435 - pos__x__contact * t18 * t440 +
                t119 * t549 + t432) *
               J__body +
           t15 *
               (t449 - t117 * t451 * Tz__body +
                pos__x__contact * (-t456 - 0.1e1 * t791) + t119 * t565 + t797) *
               m__body +
           omega__body * (pos__y__contact * t578 + pos__x__contact * t801) *
               J__body +
           t3 * t651 * t44) *
          gamma__5 -
      0.1e1 * t115 *
          (0.1000000000e1 * t252 * t263 * m__body * vy__body +
           0.1000000000e1 * t290 * t16 * t816 +
           0.1000000000e1 * t21 * t16 * t15 * Fx__body +
           0.1000000000e1 * t77 * t824) *
          t650 +
      t12 *
          (t77 *
               (-t831 - t74 * t530 - t117 * J__body * t532 +
                pos__x__contact * (-t837 + t535) - 0.1e1 * t539) *
               m__body +
           t33 *
               (t74 * (-0.1e1 * t181 - t543) - t16 * pos__y__contact * t546 +
                pos__x__contact * t18 * t443 + t552) *
               J__body +
           t15 *
               (t74 * (-t165 - t718) * Tz__body + t563 +
                pos__x__contact * (t18 * t464 - t859) + t572 -
                0.1e1 * pos__y__contact * t791) *
               m__body +
           omega__body * (pos__x__contact * t494 + pos__y__contact * t801) *
               J__body +
           (-0.1e1 * pos__x__contact * t505 + t567 * t2) * t44) *
          gamma__5 -
      0.1e1 * t252 * gamma__5 *
          (0.1000000000e1 * t246 + 0.1000000000e1 * vy__body * t881 +
           0.1000000000e1 * t249) *
          t26 +
      t605 * (-0.1e1 * t600 + t256 + t258) * J__body +
      t624 *
          (-t607 + t608 - t16 * t613 +
           pos__x__contact * (pos__y__contact * t379 + t615) + t621 -
           0.1e1 * t287) *
          m__body +
      t636 *
          (-t16 * t628 + pos__x__contact * pos__y__contact * t393 +
           t18 * (-t626 - 0.1e1 * t479)) *
          J__body +
      omega__body * gamma__5 *
          (-t16 * t639 + pos__x__contact * pos__y__contact * t291 +
           t18 * (-t643 - t917)) *
          t44 +
      gamma__5 * J__body *
          (-0.1000000000e1 * t503 * Fx__body - 0.1000000000e1 * t21 * t479 -
           0.1000000000e1 * vy__body * t477 - 0.1000000000e1 * t290 * t91);
  const float_t t941 =
      t5 * omega__body * (-0.2000000000e1 * t1 - 0.2000000000e1 * t2);
  const float_t t947 = t16 + t18;
  const float_t t948 = t15 * t947;
  const float_t t956 = sqrt(
      t941 + t12 * omega__body * (0.2000000000e1 * t8 - 0.2000000000e1 * t9) +
      t948 + t20 + t21);
  const float_t t979 =
      0.1e1 / J__body / m__body /
      (t956 * (t941 + t12 * omega__body * (0.2e1 * t8 - 0.2e1 * t9) + t948 +
               t20 + t21) +
       t5 * omega__body * (-0.2000000000e-3 * t1 - 0.2000000000e-3 * t2) +
       t12 * omega__body * (0.2e-3 * t8 - 0.2e-3 * t9) +
       t15 * (0.1000000000e-3 * t16 + 0.1000000000e-3 * t18) + 0.1e-3 * t20 +
       0.1e-3 * t21);
  const float_t tmp__1 = -t979 * t935 * t25;
  const float_t t1003 = pos__y__contact * t20;
  const float_t t1010 = 0.2e1 * t91;
  const float_t t1016 = pos__x__contact * t20;
  const float_t t1063 = 0.2e1 * t119 * t21;
  const float_t t1068 = vy__body * t119 * Fx__body;
  const float_t t1069 = 0.2e1 * t1068;
  const float_t t1090 = 0.5e1 * t277;
  const float_t t1091 = t279 + t1090;
  const float_t t1095 = 0.2e1 * t271;
  const float_t t1096 = -0.6e1 * t290 + t1095;
  const float_t t1101 = t21 * J__body;
  const float_t t1102 = t55 * t1101;
  const float_t t1103 = 0.5e1 * t1102;
  const float_t t1107 = 0.1e1 * t20;
  const float_t t1108 = 0.5e1 * t21;
  const float_t t1114 = -t627 - 0.6e1 * t153 - 0.8e1 * t155;
  const float_t t1118 = 0.5e1 * t18 * t303;
  const float_t t1122 = 0.3e1 * t290;
  const float_t t1123 = t271 - t1122;
  const float_t t1127 = -0.10e2 * t277 - 0.2e1 * t279;
  const float_t t1131 = -0.1e1 * t271 + t1122;
  const float_t t1144 = 0.2e1 * vx__body * t33 * Fy__body - 0.2e1 * t20 * t333;
  const float_t t1147 = t263 * vy__body;
  const float_t t1154 = J__body * t1131;
  const float_t t1156 = -t1127;
  const float_t t1161 = J__body * t1123;
  const float_t t1169 = 0.4e1 * t155 + 0.3e1 * t153 + 0.3e1 * t479;
  const float_t t1171 = 0.10e2 * t21;
  const float_t t1172 = -t205 - t1171;
  const float_t t1175 = -t1169;
  const float_t t1183 = -t1090 - t917;
  const float_t t1192 = t462 - t450;
  const float_t t1195 = 0.11e2 * t535;
  const float_t t1199 = 0.3e1 * t21 * t424;
  const float_t t1203 = 0.3e1 * t179;
  const float_t t1204 = t1203 + t192;
  const float_t t1206 = 0.3e1 * t89;
  const float_t t1208 = -t1206 - 0.4e1 * t91;
  const float_t t1212 = -t1203 + 0.8e1 * t181;
  const float_t t1215 = 0.3e1 * t1068;
  const float_t t1219 = t419 + t420;
  const float_t t1220 = t1219 * Tz__body;
  const float_t t1222 = 0.5e1 * t562;
  const float_t t1223 = -t419 + t1171;
  const float_t t1228 = 0.7e1 * t571;
  const float_t t1233 = 0.4e1 * t490;
  const float_t t1234 = 0.3e1 * t486;
  const float_t t1235 = 0.2e1 * t488;
  const float_t t1236 = t1233 + t492 + t1234 + t1235;
  const float_t t1238 = t290 * Fx__body;
  const float_t t1239 = 0.3e1 * t480;
  const float_t t1240 = 0.2e1 * t482;
  const float_t t1241 = t1238 + t1239 + t1240;
  const float_t t1253 = t20 * t18 * t15 * Fy__body;
  const float_t t1256 = t279 * t18 * t816;
  const float_t t1259 = t252 * t243 * vx__body * m__body;
  const float_t t1260 = t77 * t353;
  const float_t t1265 = t74 * t1101;
  const float_t t1269 = t205 - t450;
  const float_t t1272 = 0.3e1 * t425;
  const float_t t1277 = Fx__body * t74 * vy__body;
  const float_t t1281 = -t1206 - t1010;
  const float_t t1284 = 0.4e1 * t181;
  const float_t t1290 = 0.3e1 * t448;
  const float_t t1292 = 0.7e1 * t455;
  const float_t t1293 = t21 * t21;
  const float_t t1295 = t502 + 0.1000000000e1 * t1293;
  const float_t t1296 = J__body * t1295;
  const float_t t1307 = -0.1e1 * t1238 - t1239 - t1240;
  const float_t t1324 = t18 * t59;
  const float_t t1330 = 0.3e1 * t366;
  const float_t t1335 = -0.5e1 * vy__body * t454 - 0.2e1 * vx__body * t1101;
  const float_t t1337 = 0.3e1 * t370;
  const float_t t1341 = 0.3e1 * t1102;
  const float_t t1342 = 0.4e1 * t377;
  const float_t t1346 = 0.3e1 * t299;
  const float_t t1352 = -t1346 - t304;
  const float_t t1357 = 0.3e1 * t271;
  const float_t t1363 = -t1095 - 0.4e1 * t290;
  const float_t t1380 =
      t23 *
          (t52 * (t58 + t15 * (t61 - t64) * J__body +
                  omega__body * (t31 - t29) * t44) +
           t5 * (t12 * (t33 * (-t31 + t28 - 0.1e1 * t27) * t26 +
                        t15 * (-t40 + t36 - 0.1e1 * t18 * Fx__body) * J__body +
                        omega__body * t56 * t44) -
                 t124 -
                 0.1e1 * t15 *
                     (0.1000000000e1 * t101 + 0.1000000000e1 * t1003) * t26 +
                 omega__body *
                     (vx__body * t62 + pos__y__contact * (-t1010 + t89)) *
                     J__body -
                 0.1e1 * t1016 * t44 + t134) +
           t115 * (-0.1e1 * omega__body * vy__body * t44 + t15 * t145) * t16 +
           t12 * (t77 * t947 * m__body * t593 +
                  t15 * (-0.1e1 * t83 + t1016) * t26 +
                  omega__body *
                      (pos__x__contact * (-0.1e1 * t89 + t1010) +
                       Fx__body * pos__y__contact * vx__body) *
                      J__body -
                  0.1e1 * t1003 * t44 - t103) +
           t33 * (0.2e1 * t45 - 0.1e1 * t46 + t55) * t26 + t147 * t110 -
           0.1e1 * t151 * vx__body * Tz__body * m__body +
           J__body * (-0.1e1 * t299 + t301)) +
      t214 *
          (t77 * (-t200 + t218 + t204 - t1063) * t26 +
           t33 * (t224 + t227 + t229 - t1069) * J__body + t240) *
          gamma__5 +
      t52 *
          (t12 * (t77 * t692 * t26 +
                  t33 * (t74 * t232 + t666 + t668 + t670) * J__body + t675) +
           t252 * (-t349 - t344 + t345) * t26 +
           t77 * (-t356 - t358 - t360) * J__body +
           t33 *
               (-t365 - t367 + t16 * J__body * t1091 +
                pos__x__contact * (pos__y__contact * J__body * t1096 - t371) -
                t1103 + t378) *
               m__body +
           t15 *
               (t16 * (-t1107 - t1108) * Fy__body +
                pos__x__contact * pos__y__contact * t1114 + t1118) *
               J__body +
           omega__body *
               (pos__x__contact * pos__y__contact * t1127 + t16 * t1123 +
                t18 * t1131) *
               t44) *
          gamma__5 +
      t5 *
          (t115 * t1144 * t424 +
           t12 * (t252 * (t1147 - t697 + t247 + t250) * t26 +
                  t77 * (-t701 + t824 - t257 - t259) * J__body +
                  t33 *
                      (t266 - t269 + t16 * t1154 +
                       pos__x__contact *
                           (pos__y__contact * J__body * t1156 - t276) -
                       t288 + t18 * t1161) *
                      m__body +
                  t15 * (t146 * t1172 * Fy__body + t16 * t1169 + t18 * t1175) *
                      J__body +
                  omega__body *
                      (pos__x__contact * pos__y__contact * t1096 + t16 * t1091 +
                       t18 * t1183) *
                      t44) +
           t77 *
               (t525 + t74 * (t529 + t527) + t117 * J__body * t1192 +
                pos__x__contact * (t286 - t1195) + t1199) *
               m__body +
           t33 *
               (t16 * pos__y__contact * t1208 + pos__x__contact * t18 * t1212 +
                t74 * t1204 + t1215) *
               J__body +
           t15 *
               (t74 * t1220 - t1222 +
                pos__x__contact * (t18 * t1223 * Tz__body - t859) + t1228 +
                t573 * t1101) *
               m__body +
           omega__body * (pos__x__contact * t1236 + pos__y__contact * t1241) *
               J__body +
           t3 * t567 * t44) *
          gamma__5 +
      t115 * (-0.1e1 * t1253 + t1256 + t1259 - 0.1e1 * t1260) * t650 +
      t12 *
          (t77 *
               (t409 - 0.1e1 * t1265 + t16 * (t414 + t416) +
                t72 * J__body * t1269 - t1272 + t427) *
               m__body +
           t33 *
               (-0.1e1 * t1277 + t16 * pos__y__contact * t1204 +
                pos__x__contact * t18 * t1281 + t119 * (t179 + t1284)) *
               J__body +
           t15 *
               (-t1290 + t117 * t1220 +
                pos__x__contact * (-t1292 - 0.1e1 * t1296) +
                t119 * (t20 + t166) * Tz__body - t473) *
               m__body +
           omega__body * (pos__y__contact * t1236 + pos__x__contact * t1307) *
               J__body +
           (-0.1e1 * t499 + t458 * t104) * t44) *
          gamma__5 +
      t252 * (t27 + t30 + t28) * t595 * t594 +
      t605 * (-0.1e1 * t1324 + t355 + t357) * J__body +
      t624 *
          (-0.1e1 * t364 + t1330 + t16 * t1335 +
           pos__x__contact * (pos__y__contact * t1154 + t1337) + t1341 -
           t1342) *
          m__body +
      t636 *
          (t16 * (-t1346 - 0.1e1 * t303) +
           pos__x__contact * pos__y__contact * t1169 + t18 * t1352) *
          J__body +
      omega__body * gamma__5 *
          (t16 * (-t1357 - t398) + pos__x__contact * pos__y__contact * t1091 +
           t18 * t1363) *
          t44 +
      gamma__5 * J__body *
          (-0.1000000000e1 * vy__body * t492 - 0.1000000000e1 * t290 * t179 -
           0.1000000000e1 * t21 * t301 - 0.1000000000e1 * t1293 * Fy__body);
  const float_t t1407 = -t1096;
  const float_t t1482 = -t1204;
  const float_t t1494 = -t1219 * Tz__body;
  const float_t t1507 = -0.1e1 * t492 - t1233 - t1234 - t1235;
  const float_t t1614 =
      t657 * t1380 +
      t214 *
          (t77 * (t200 + t202 - t204 + t1063) * t26 +
           t33 * (t681 + t683 + t685 + t1069) * J__body + t694) *
          gamma__5 +
      t52 *
          (t12 * (t77 * t238 * t26 +
                  t33 * (t74 * t686 + t185 + t190 + t194) * J__body + t211) +
           t252 * (t349 + t344 - t735) * t26 +
           t77 * (t356 + t358 + t359) * J__body +
           t33 *
               (t365 + t367 + t16 * J__body * t1183 +
                pos__x__contact * (pos__y__contact * J__body * t1407 + t371) +
                t1103 - t378) *
               m__body +
           t15 *
               (t16 * (t20 + t1108) * Fy__body -
                pos__x__contact * pos__y__contact * t1114 - t1118) *
               J__body +
           omega__body *
               (pos__x__contact * pos__y__contact * t1156 + t18 * t1123 +
                t16 * t1131) *
               t44) *
          gamma__5 +
      t5 *
          (-t115 * t1144 * t424 +
           t12 * (t252 * (-0.1e1 * t1147 + t244 - t247 - t250) * t26 +
                  t77 * (t255 - 0.1e1 * t824 + t257 + t259) * J__body +
                  t33 *
                      (-t266 + t269 + t16 * t1161 +
                       pos__x__contact *
                           (pos__y__contact * J__body * t1127 + t276) +
                       t288 + t18 * t1154) *
                      m__body +
                  t15 * (-t146 * t1172 * Fy__body + t18 * t1169 + t16 * t1175) *
                      J__body +
                  omega__body *
                      (pos__x__contact * pos__y__contact * t1407 + t18 * t1091 +
                       t16 * t1183) *
                      t44) +
           t77 *
               (-t831 + t74 * (-t529 - 0.1e1 * t527) - t117 * J__body * t1192 +
                pos__x__contact * (-t837 + t1195) - t1199) *
               m__body +
           t33 *
               (-t16 * pos__y__contact * t1208 - pos__x__contact * t18 * t1212 +
                t74 * t1482 - t1215) *
               J__body +
           t15 *
               (t74 * t1494 + t1222 +
                pos__x__contact * (-t18 * t1223 * Tz__body + t568) - t1228 -
                0.1e1 * pos__y__contact * t1296) *
               m__body +
           omega__body * (pos__y__contact * t1307 + pos__x__contact * t1507) *
               J__body -
           0.1e1 *
               (0.1000000000e1 * pos__x__contact * t1295 +
                0.1000000000e1 * t586) *
               t44) *
          gamma__5 +
      t115 * (t1253 - 0.1e1 * t1256 - 0.1e1 * t1259 + t1260) * t650 +
      t12 *
          (t77 *
               (-t410 + t1265 + t16 * (-0.1e1 * t414 - t416) -
                t72 * J__body * t1269 + t1272 - t428) *
               m__body +
           t33 *
               (t1277 + t16 * pos__y__contact * t1482 -
                pos__x__contact * t18 * t1281 +
                t119 * (-0.1e1 * t179 - t1284)) *
               J__body +
           t15 *
               (t1290 + t117 * t1494 +
                pos__x__contact * (t458 * t1101 + t1292) +
                t119 * (-t1107 - t166) * Tz__body + t797) *
               m__body +
           omega__body * (pos__x__contact * t1241 + pos__y__contact * t1507) *
               J__body +
           (pos__x__contact * t458 * t162 - 0.1e1 * pos__y__contact * t1295) *
               t44) *
          gamma__5 -
      0.1e1 * t252 * gamma__5 *
          (0.1000000000e1 * t348 + 0.1000000000e1 * vx__body * t881 +
           0.1000000000e1 * t343) *
          t26 +
      t605 * (t1324 - 0.1e1 * t355 - 0.1e1 * t357) * J__body +
      t624 *
          (t364 - t1330 - t16 * t1335 +
           pos__x__contact * (pos__y__contact * t1161 - t1337) - t1341 +
           t1342) *
          m__body +
      t636 *
          (t16 * (t1346 + t303) + pos__x__contact * pos__y__contact * t1175 -
           t18 * t1352) *
          J__body +
      omega__body * gamma__5 *
          (t16 * (t290 + t1357) + pos__x__contact * pos__y__contact * t1183 -
           t18 * t1363) *
          t44 +
      t652 * t567 * t650;
  const float_t tmp__2 = t979 * t1614 * t25;
  const float_t t1618 = sqrt(t947);
  const float_t tmp__3 = -t1618 * gamma__5 * (-1 + t657) * gamma__4;

  func(0) = tmp__1;
  func(1) = tmp__2;
  func(2) = tmp__3;

  return func;
}

Matrix contact_force_dt3_dx(VectorRef x, VectorRef u) {
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

Matrix contact_force_dt3_du(VectorRef x, VectorRef u) {
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
