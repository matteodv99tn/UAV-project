#include <maple_codegen/contact_force_dt4.hpp>
#include <maple_codegen/contact_force_dt4_params.hpp>
#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector contact_force_dt4(VectorRef x, VectorRef u) {
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
      sqrt(2 * t5 * (-t1 + t2) * omega__body + 2 * t12 * t10 * omega__body +
           t17 + t18 * t15 + t20 + t21);
  const float_t t25 = gamma__4 / t23;
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
  const float_t t72 = t18 * pos__x__contact;
  const float_t t74 = t16 * pos__x__contact;
  const float_t t77 = t15 * t15;
  const float_t t81 = t21 * pos__x__contact;
  const float_t t83 = vy__body * t2;
  const float_t t87 = Fx__body * vy__body;
  const float_t t88 = 0.2e1 * t87;
  const float_t t89 = Fy__body * vx__body;
  const float_t t101 = vy__body * t8;
  const float_t t103 = 0.1e1 * t101 * t44;
  const float_t t108 = Fx__body * J__body;
  const float_t t113 = t12 * t12;
  const float_t t115 = J__body * pos__y__contact;
  const float_t t116 = t16 + t18;
  const float_t t118 = t77 * t116 * m__body;
  const float_t t119 = t118 * t115;
  const float_t t120 = vy__body * m__body;
  const float_t t132 = t83 * t44;
  const float_t t139 = Fy__body * J__body;
  const float_t t140 = pos__x__contact * pos__y__contact;
  const float_t t141 = t15 * t140;
  const float_t t144 = omega__body * t140;
  const float_t t147 = t21 * Fx__body;
  const float_t t149 = vy__body * t89;
  const float_t t155 = 0.2e1 * t20 * t74;
  const float_t t156 = pos__y__contact * t16;
  const float_t t157 = vx__body * vy__body;
  const float_t t159 = 0.12e2 * t157 * t156;
  const float_t t160 = 0.6e1 * t20;
  const float_t t161 = 0.6e1 * t21;
  const float_t t162 = t160 - t161;
  const float_t t164 = pos__x__contact * t18 * t162;
  const float_t t165 = t18 * pos__y__contact;
  const float_t t168 = 0.4e1 * vy__body * vx__body * t165;
  const float_t t172 = t74 * Fy__body;
  const float_t t173 = vx__body * t172;
  const float_t t174 = 0.2e1 * t173;
  const float_t t175 = Fx__body * vx__body;
  const float_t t177 = Fy__body * vy__body;
  const float_t t179 = -0.6e1 * t175 + 0.6e1 * t177;
  const float_t t181 = t16 * pos__y__contact * t179;
  const float_t t184 = -0.6000000000e1 * t87 - 0.6000000000e1 * t89;
  const float_t t186 = pos__x__contact * t18 * t184;
  const float_t t187 = 0.2e1 * t177;
  const float_t t188 = 0.2e1 * t175;
  const float_t t189 = -t187 + t188;
  const float_t t190 = t165 * t189;
  const float_t t196 = 0.4e1 * vy__body * vx__body * t74;
  const float_t t197 = -t162;
  const float_t t199 = t16 * pos__y__contact * t197;
  const float_t t201 = 0.12e2 * t157 * t72;
  const float_t t202 = 0.2e1 * t21;
  const float_t t203 = 0.2e1 * t20;
  const float_t t204 = -t202 + t203;
  const float_t t206 = t165 * t204 + t196 + t199 - t201;
  const float_t t208 = t15 * t206 * t44;
  const float_t t211 = t52 * t5;
  const float_t t214 = t16 * pos__y__contact * t162;
  const float_t t215 = -t204;
  const float_t t217 = t165 * t215 - t196 + t201 + t214;
  const float_t t220 = -t189;
  const float_t t221 = t74 * t220;
  const float_t t223 = t16 * pos__y__contact * t184;
  const float_t t224 = -t179;
  const float_t t226 = pos__x__contact * t18 * t224;
  const float_t t229 = 0.2000000000e1 * t87 + 0.2000000000e1 * t89;
  const float_t t235 = t74 * t215 - t159 + t164 + t168;
  const float_t t237 = t15 * t235 * t44;
  const float_t t240 = pos__y__contact * t74;
  const float_t t241 = vx__body * t240;
  const float_t t242 = 0.2e1 * t241;
  const float_t t243 = t165 * pos__x__contact;
  const float_t t244 = vx__body * t243;
  const float_t t245 = 0.2e1 * t244;
  const float_t t246 = t18 * t18;
  const float_t t247 = vy__body * t246;
  const float_t t249 = t77 * omega__body;
  const float_t t252 = pos__y__contact * t172;
  const float_t t253 = 0.2e1 * t252;
  const float_t t254 = t165 * t36;
  const float_t t255 = 0.2e1 * t254;
  const float_t t256 = t246 * Fx__body;
  const float_t t260 = t16 * t16;
  const float_t t261 = t260 * Tz__body;
  const float_t t262 = vx__body * t261;
  const float_t t263 = 0.3e1 * t262;
  const float_t t264 = t74 * Tz__body;
  const float_t t265 = t9 * t264;
  const float_t t266 = 0.6e1 * t265;
  const float_t t268 = vy__body * t20;
  const float_t t270 = 0.5e1 * t268 * t16 * J__body;
  const float_t t271 = t165 * Tz__body;
  const float_t t272 = vy__body * t271;
  const float_t t273 = 0.6e1 * t272;
  const float_t t274 = t21 * vx__body;
  const float_t t275 = 0.2e1 * t274;
  const float_t t276 = t20 * vx__body;
  const float_t t278 = -t275 + 0.6e1 * t276;
  const float_t t283 = t246 * Tz__body;
  const float_t t284 = vx__body * t283;
  const float_t t285 = 0.3e1 * t284;
  const float_t t286 = 0.5e1 * t268;
  const float_t t287 = t21 * vy__body;
  const float_t t288 = t286 + t287;
  const float_t t295 = 0.5e1 * t20 * t39;
  const float_t t296 = vy__body * t175;
  const float_t t298 = t20 * Fy__body;
  const float_t t300 = t21 * Fy__body;
  const float_t t301 = 0.6e1 * t300;
  const float_t t302 = -0.8e1 * t296 - 0.6e1 * t298 - t301;
  const float_t t305 = 0.5e1 * t20;
  const float_t t312 = 0.3e1 * t276;
  const float_t t313 = t274 - t312;
  const float_t t317 = -0.10e2 * t268 - 0.2e1 * t287;
  const float_t t321 = -0.1e1 * t274 + t312;
  const float_t t329 = t74 * J__body;
  const float_t t330 = t77 * m__body;
  const float_t t339 = 0.2e1 * t113 *
                       (0.1000000000e1 * t21 * t330 +
                        0.1000000000e1 * vy__body * t33 * Fx__body) *
                       t329;
  const float_t t340 = vy__body * t243;
  const float_t t341 = 0.2e1 * t340;
  const float_t t342 = vy__body * t240;
  const float_t t343 = 0.2e1 * t342;
  const float_t t344 = vx__body * t260;
  const float_t t345 = vx__body * t246;
  const float_t t350 = t260 * Fy__body;
  const float_t t351 = 0.1e1 * t350;
  const float_t t352 = t246 * Fy__body;
  const float_t t354 = pos__y__contact * t74 * Fx__body;
  const float_t t355 = 0.2e1 * t354;
  const float_t t356 = t165 * t59;
  const float_t t357 = 0.2e1 * t356;
  const float_t t361 = vy__body * t261;
  const float_t t362 = 0.3e1 * t361;
  const float_t t363 = t2 * t264;
  const float_t t364 = 0.6e1 * t363;
  const float_t t365 = J__body * t321;
  const float_t t367 = vx__body * t271;
  const float_t t368 = 0.6e1 * t367;
  const float_t t369 = -t317;
  const float_t t374 = vy__body * t283;
  const float_t t375 = 0.3e1 * t374;
  const float_t t376 = J__body * t313;
  const float_t t384 = -0.4e1 * t296 - 0.3e1 * t298 - 0.3e1 * t300;
  const float_t t386 = 0.10e2 * t20;
  const float_t t387 = t386 + t202;
  const float_t t390 = -t384;
  const float_t t395 = 0.1e1 * t287;
  const float_t t396 = -t286 - t395;
  const float_t t406 = pos__y__contact * t261;
  const float_t t408 = 0.3e1 * t20 * t329;
  const float_t t409 = t157 * t115;
  const float_t t411 = 0.2e1 * t271;
  const float_t t412 = 0.11e2 * t409 + t411;
  const float_t t414 = 0.3e1 * t20;
  const float_t t415 = 0.4e1 * t21;
  const float_t t416 = -t414 + t415;
  const float_t t419 = t165 * J__body;
  const float_t t420 = t157 * t419;
  const float_t t423 = t246 * pos__y__contact * Tz__body;
  const float_t t427 = 0.3e1 * t173;
  const float_t t429 = 0.3e1 * t177;
  const float_t t430 = 0.8e1 * t175 - t429;
  const float_t t434 = 0.3e1 * t89;
  const float_t t435 = 0.4e1 * t87 + t434;
  const float_t t438 = t188 + t429;
  const float_t t443 = t157 * t264;
  const float_t t444 = 0.7e1 * t443;
  const float_t t445 = 0.3e1 * t21;
  const float_t t446 = t386 - t445;
  const float_t t449 = t18 * Tz__body;
  const float_t t450 = t157 * t449;
  const float_t t451 = 0.5e1 * t450;
  const float_t t452 = t20 * J__body;
  const float_t t453 = t20 + t21;
  const float_t t457 = 0.4e1 * t20;
  const float_t t458 = t457 + t445;
  const float_t t459 = t458 * Tz__body;
  const float_t t461 = J__body * vx__body;
  const float_t t462 = t453 * vy__body;
  const float_t t464 = pos__y__contact * t462 * t461;
  const float_t t468 = t276 * Fy__body;
  const float_t t470 = t20 * Fx__body;
  const float_t t471 = vy__body * t470;
  const float_t t472 = 0.2e1 * t471;
  const float_t t473 = t21 * t89;
  const float_t t474 = 0.3e1 * t473;
  const float_t t475 = -0.1e1 * t468 - t472 - t474;
  const float_t t477 = t21 * t175;
  const float_t t478 = 0.2e1 * t477;
  const float_t t479 = vy__body * t298;
  const float_t t480 = 0.3e1 * t479;
  const float_t t481 = t287 * Fy__body;
  const float_t t482 = t276 * Fx__body;
  const float_t t483 = 0.4e1 * t482;
  const float_t t484 = t478 + t480 + t481 + t483;
  const float_t t493 =
      0.1000000000e1 * vy__body * t276 + 0.1000000000e1 * t287 * vx__body;
  const float_t t494 = pos__x__contact * t493;
  const float_t t496 = t20 * pos__y__contact;
  const float_t t514 = t260 * pos__x__contact * Tz__body;
  const float_t t515 = vy__body * t461;
  const float_t t517 = 0.2e1 * t449;
  const float_t t518 = 0.3e1 * t515 + t517;
  const float_t t520 = t202 - t414;
  const float_t t523 = t29 * t461;
  const float_t t527 = t20 * t419;
  const float_t t532 = 0.4e1 * t175;
  const float_t t535 = t88 + t434;
  const float_t t540 = t165 * t89;
  const float_t t549 = pos__y__contact * t16 * Tz__body * t157;
  const float_t t550 = 0.7e1 * t549;
  const float_t t552 = t462 * t461;
  const float_t t555 = t271 * t157;
  const float_t t556 = 0.3e1 * t555;
  const float_t t558 = 0.1000000000e1 * t21 * t20;
  const float_t t559 = t20 * t20;
  const float_t t561 = t558 + 0.1000000000e1 * t559;
  const float_t t562 = J__body * t561;
  const float_t t569 = t472 + t474 + t468;
  const float_t t574 = t453 * vx__body;
  const float_t t581 = t18 * t16;
  const float_t t582 = vy__body * t581;
  const float_t t588 = pos__x__contact * J__body;
  const float_t t589 = pos__y__contact * t588;
  const float_t t594 = 0.4e1 * t262;
  const float_t t595 = 0.3e1 * t265;
  const float_t t600 = 0.5e1 * vx__body * t449 + 0.3e1 * vy__body * t452;
  const float_t t602 = 0.3e1 * t272;
  const float_t t608 = 0.2e1 * t268 * t18 * J__body;
  const float_t t611 = t33 * gamma__5;
  const float_t t613 = 0.3e1 * t149;
  const float_t t614 = 0.6e1 * t470;
  const float_t t615 = t613 + t614;
  const float_t t623 = t15 * gamma__5;
  const float_t t626 = t275 + 0.4e1 * t276;
  const float_t t630 = 0.3e1 * t274;
  const float_t t637 = J__body * gamma__5;
  const float_t t638 = t175 + t177;
  const float_t t641 =
      t23 * (t52 * (t33 * t32 * t26 + t15 * (-t38 - 0.1e1 * t39) * J__body +
                    omega__body * (t46 + t47) * t44) +
             t5 * (t12 * (t58 + t15 * (t61 - 0.1e1 * t62 + t64) * J__body +
                          omega__body * t32 * t44) -
                   0.1e1 * t77 * (0.1000000000e1 * t72 + 0.1000000000e1 * t74) *
                       t26 +
                   t15 * (-0.1e1 * t81 + t83) * t26 +
                   omega__body *
                       (pos__x__contact * (t88 - 0.1e1 * t89) +
                        Fy__body * pos__y__contact * vy__body) *
                       J__body -
                   0.1e1 * t21 * pos__y__contact * t44 - t103) +
             t113 * (omega__body * vx__body * t44 - 0.1e1 * t15 * t108) * t18 +
             t12 * (t119 + t15 * t10 * J__body * t120 +
                    omega__body *
                        (vy__body * t36 + pos__y__contact * (-t88 + t89)) *
                        J__body -
                    0.1e1 * t81 * t44 + t132) +
             t33 * (t27 + 0.2e1 * t29 + t31) * t26 + t141 * t139 -
             0.1e1 * t144 * vy__body * t44 + J__body * (-0.1e1 * t147 + t149)) +
      t211 *
          (t77 * (-t155 - t159 + t164 + t168) * t26 +
           t33 * (t174 + t181 + t186 + t190) * J__body + t208) *
          gamma__5 +
      t52 *
          (t12 * (t77 * t217 * t26 +
                  t33 * (t165 * t229 + t221 + t223 + t226) * J__body + t237) +
           t249 * (t242 + t245 + t247) * t26 +
           t77 * (-t253 - t255 + t256) * J__body +
           t33 *
               (-t263 - t266 - t270 +
                pos__x__contact * (pos__y__contact * J__body * t278 - t273) +
                t285 + t18 * J__body * t288) *
               m__body +
           t15 *
               (-t295 + pos__x__contact * pos__y__contact * t302 +
                t18 * (t21 + t305) * Fx__body) *
               J__body +
           omega__body *
               (pos__x__contact * pos__y__contact * t317 + t16 * t313 +
                t18 * t321) *
               t44) *
          gamma__5 +
      t5 *
          (-t339 +
           t12 * (t249 * (t341 + t343 + t344 - 0.1e1 * t345) * t26 +
                  t77 * (-t351 + t352 + t355 + t357) * J__body +
                  t33 *
                      (-t362 + t364 + t16 * t365 +
                       pos__x__contact *
                           (pos__y__contact * J__body * t369 + t368) +
                       t375 + t18 * t376) *
                      m__body +
                  t15 * (t140 * t387 * Fx__body + t16 * t384 + t18 * t390) *
                      J__body +
                  omega__body *
                      (pos__x__contact * pos__y__contact * t278 + t16 * t396 +
                       t18 * t288) *
                      t44) +
           t77 *
               (t406 + t408 + t16 * t412 + t72 * J__body * t416 - 0.1e1 * t420 +
                t423) *
               m__body +
           t33 *
               (t16 * pos__y__contact * t430 + pos__x__contact * t18 * t435 +
                t165 * t438 - t427) *
               J__body +
           t15 *
               (-t444 + t156 * t446 * Tz__body +
                pos__x__contact * (t453 * t452 + t451) + t165 * t459 + t464) *
               m__body +
           omega__body * (pos__x__contact * t475 + pos__y__contact * t484) *
               J__body +
           (-0.1e1 * t494 + t453 * t496) * t44) *
          gamma__5 +
      t113 * (m__body * omega__body * vy__body + Fx__body) * (t17 + t21) *
          gamma__5 * t16 * t15 * J__body +
      t12 *
          (t77 *
               (t514 + t74 * t518 + t156 * J__body * t520 +
                pos__x__contact * (t283 - 0.1e1 * t523) - 0.1e1 * t527) *
               m__body +
           t33 *
               (t74 * (t177 + t532) + t16 * pos__y__contact * t535 +
                pos__x__contact * t18 * t438 + t540) *
               J__body +
           t15 *
               (t74 * (t160 + t21) * Tz__body + t550 +
                pos__x__contact * (t18 * t459 + t552) + t556 -
                0.1e1 * pos__y__contact * t562) *
               m__body +
           omega__body * (pos__x__contact * t484 + pos__y__contact * t569) *
               J__body +
           t10 * t574 * t44) *
          gamma__5 +
      t249 * gamma__5 * (-0.1e1 * t241 + t582 - 0.1e1 * t244) * t26 +
      t77 * (t60 + t62 + t64) * gamma__5 * t589 +
      t611 *
          (t594 + t595 + t16 * t600 +
           pos__x__contact * (pos__y__contact * t376 + t602) - t608 + t284) *
          m__body +
      t623 *
          (t16 * t615 + pos__x__contact * pos__y__contact * t390 +
           t18 * (t613 + t470)) *
          J__body +
      omega__body * gamma__5 *
          (t16 * t626 + pos__x__contact * pos__y__contact * t288 +
           t18 * (t630 + t276)) *
          t44 +
      t638 * t574 * t637;
  const float_t t643 = tanh(t23 * gamma__5);
  const float_t t646 = pos__x__contact * t18 * t197;
  const float_t t651 = t16 * pos__y__contact * t224;
  const float_t t652 = -t184;
  const float_t t654 = pos__x__contact * t18 * t652;
  const float_t t655 = t165 * t220;
  const float_t t660 = t15 * t217 * t44;
  const float_t t666 = t74 * t189;
  const float_t t668 = t16 * pos__y__contact * t652;
  const float_t t670 = pos__x__contact * t18 * t179;
  const float_t t671 = -t229;
  const float_t t677 = t74 * t204 + t159 - t168 + t646;
  const float_t t679 = t15 * t677 * t44;
  const float_t t682 = 0.1e1 * t247;
  const float_t t686 = 0.1e1 * t256;
  const float_t t690 = -t278;
  const float_t t703 = 0.1e1 * t21;
  const float_t t720 = 0.1e1 * t344;
  const float_t t754 = 0.1e1 * t406;
  const float_t t760 = 0.1e1 * t423;
  const float_t t770 = -t438;
  const float_t t782 = -t458 * Tz__body;
  const float_t t784 = J__body * t493;
  const float_t t786 = 0.1e1 * pos__y__contact * t784;
  const float_t t792 = -t478 - t480 - 0.1e1 * t481 - t483;
  const float_t t809 = t33 * m__body;
  const float_t t817 = t260 * Fx__body;
  const float_t t824 = 0.1e1 * t514;
  const float_t t830 = 0.1e1 * t283;
  const float_t t852 = 0.1e1 * t784;
  const float_t t855 = pos__y__contact * t453;
  const float_t t867 = pos__y__contact * t493;
  const float_t t886 = t77 * gamma__5;
  const float_t t912 = 0.1e1 * t276;
  const float_t t930 =
      t643 * t641 +
      t211 *
          (t77 * (t155 + t159 + t646 - t168) * t26 +
           t33 * (-t174 + t651 + t654 + t655) * J__body + t660) *
          gamma__5 +
      t52 *
          (t12 * (t77 * t206 * t26 +
                  t33 * (t165 * t671 + t666 + t668 + t670) * J__body + t679) +
           t249 * (-t242 - t245 - t682) * t26 +
           t77 * (t253 + t255 - t686) * J__body +
           t33 *
               (t263 + t266 + t270 +
                pos__x__contact * (pos__y__contact * J__body * t690 + t273) -
                t285 + t18 * J__body * t396) *
               m__body +
           t15 *
               (t295 - pos__x__contact * pos__y__contact * t302 +
                t18 * (-t703 - t305) * Fx__body) *
               J__body +
           omega__body *
               (pos__x__contact * pos__y__contact * t369 + t16 * t321 +
                t18 * t313) *
               t44) *
          gamma__5 +
      t5 *
          (t339 +
           t12 * (t249 * (-t341 - t343 - t720 + t345) * t26 +
                  t77 * (t350 - 0.1e1 * t352 - t355 - t357) * J__body +
                  t33 *
                      (t362 - t364 + t16 * t376 +
                       pos__x__contact *
                           (pos__y__contact * J__body * t317 - t368) -
                       t375 + t18 * t365) *
                      m__body +
                  t15 * (-t140 * t387 * Fx__body + t16 * t390 + t18 * t384) *
                      J__body +
                  omega__body *
                      (pos__x__contact * pos__y__contact * t690 + t16 * t288 +
                       t18 * t396) *
                      t44) +
           t77 *
               (-t72 * J__body * t416 - t16 * t412 - t408 + t420 - t754 -
                t760) *
               m__body +
           t33 *
               (-t16 * pos__y__contact * t430 - pos__x__contact * t18 * t435 +
                t165 * t770 + t427) *
               J__body +
           t15 *
               (t444 - t156 * t446 * Tz__body +
                pos__x__contact * (-t451 - 0.1e1 * t562) + t165 * t782 - t786) *
               m__body +
           omega__body * (pos__x__contact * t569 + pos__y__contact * t792) *
               J__body +
           (pos__x__contact * t453 * t157 - 0.1e1 * pos__y__contact * t561) *
               t44) *
          gamma__5 -
      0.1e1 * t113 *
          (0.1000000000e1 * t249 * t260 * t120 +
           0.1000000000e1 * t287 * t16 * t809 +
           0.1000000000e1 * t21 * t16 * t15 * Fx__body +
           0.1000000000e1 * t77 * t817) *
          t637 +
      t12 *
          (t77 *
               (-t824 - t74 * t518 - t156 * J__body * t520 +
                pos__x__contact * (-t830 + t523) + t527) *
               m__body +
           t33 *
               (t74 * (-0.1e1 * t177 - t532) - t16 * pos__y__contact * t535 +
                pos__x__contact * t18 * t770 - 0.1e1 * t540) *
               J__body +
           t15 *
               (t74 * (-t160 - t703) * Tz__body - t550 +
                pos__x__contact * (t18 * t782 - t852) - t556 + t855 * t452) *
               m__body +
           omega__body * (pos__y__contact * t475 + pos__x__contact * t792) *
               J__body -
           0.1e1 *
               (0.1000000000e1 * pos__x__contact * t561 +
                0.1000000000e1 * t867) *
               t44) *
          gamma__5 +
      t249 * gamma__5 * (t241 - 0.1e1 * t582 + t244) * t26 -
      0.1e1 * t886 *
          (0.1000000000e1 * t18 * t39 + 0.1000000000e1 * t252 +
           0.1000000000e1 * t254) *
          J__body +
      t611 *
          (-t594 - t595 - t16 * t600 +
           pos__x__contact * (pos__y__contact * t365 - t602) + t608 -
           0.1e1 * t284) *
          m__body +
      t623 *
          (-t16 * t615 + pos__x__contact * pos__y__contact * t384 +
           t18 * (-t613 - 0.1e1 * t470)) *
          J__body +
      omega__body * gamma__5 *
          (-t16 * t626 + pos__x__contact * pos__y__contact * t396 +
           t18 * (-t630 - t912)) *
          t44 +
      gamma__5 * J__body *
          (-0.1000000000e1 * t559 * Fx__body - 0.1000000000e1 * t21 * t470 -
           0.1000000000e1 * vy__body * t468 - 0.1000000000e1 * t287 * t89);
  const float_t t942 =
      t12 * omega__body * (0.2000000000e1 * t8 + 0.2000000000e1 * t9);
  const float_t t943 = t15 * t116;
  const float_t t951 =
      sqrt(t5 * omega__body * (-0.2000000000e1 * t1 + 0.2000000000e1 * t2) +
           t942 + t943 + t20 + t21);
  const float_t t973 =
      0.1e1 / J__body /
      (t951 * (t5 * omega__body * (-0.2e1 * t1 + 0.2e1 * t2) + t942 + t943 +
               t20 + t21) +
       t5 * omega__body * (-0.2e-3 * t1 + 0.2e-3 * t2) +
       t12 * omega__body * (0.2000000000e-3 * t8 + 0.2000000000e-3 * t9) +
       t15 * (0.1000000000e-3 * t16 + 0.1000000000e-3 * t18) + 0.1e-3 * t20 +
       0.1e-3 * t21) /
      m__body;
  const float_t tmp__1 = -t973 * t930 * t25;
  const float_t t987 = t18 * Fx__body;
  const float_t t1002 = 0.2e1 * t89;
  const float_t t1003 = -0.1e1 * t87 + t1002;
  const float_t t1050 = 0.2e1 * t165 * t21;
  const float_t t1055 = vy__body * t165 * Fx__body;
  const float_t t1056 = 0.2e1 * t1055;
  const float_t t1077 = 0.5e1 * t274;
  const float_t t1078 = t276 + t1077;
  const float_t t1082 = 0.2e1 * t268;
  const float_t t1083 = 0.6e1 * t287 - t1082;
  const float_t t1088 = t21 * J__body;
  const float_t t1089 = t55 * t1088;
  const float_t t1090 = 0.5e1 * t1089;
  const float_t t1094 = 0.1e1 * t20;
  const float_t t1095 = 0.5e1 * t21;
  const float_t t1101 = t614 + 0.6e1 * t147 + 0.8e1 * t149;
  const float_t t1105 = 0.5e1 * t18 * t300;
  const float_t t1109 = 0.3e1 * t287;
  const float_t t1110 = t268 - t1109;
  const float_t t1114 = 0.2e1 * t276 + 0.10e2 * t274;
  const float_t t1118 = -0.1e1 * t268 + t1109;
  const float_t t1131 = -0.2e1 * vx__body * t33 * Fy__body + 0.2e1 * t20 * t330;
  const float_t t1134 = t260 * vy__body;
  const float_t t1141 = J__body * t1118;
  const float_t t1143 = -t1114;
  const float_t t1148 = J__body * t1110;
  const float_t t1156 = 0.4e1 * t149 + 0.3e1 * t147 + 0.3e1 * t470;
  const float_t t1158 = 0.10e2 * t21;
  const float_t t1159 = t203 + t1158;
  const float_t t1162 = -t1156;
  const float_t t1170 = -t1077 - t912;
  const float_t t1179 = -t457 + t445;
  const float_t t1182 = 0.11e2 * t523;
  const float_t t1186 = 0.3e1 * t21 * t419;
  const float_t t1190 = 0.3e1 * t175;
  const float_t t1191 = t1190 + t187;
  const float_t t1193 = 0.3e1 * t87;
  const float_t t1195 = t1193 + 0.4e1 * t89;
  const float_t t1199 = -t1190 + 0.8e1 * t177;
  const float_t t1202 = 0.3e1 * t1055;
  const float_t t1206 = t414 + t415;
  const float_t t1207 = t1206 * Tz__body;
  const float_t t1209 = 0.5e1 * t549;
  const float_t t1210 = -t414 + t1158;
  const float_t t1215 = 0.7e1 * t555;
  const float_t t1216 = t21 * t21;
  const float_t t1218 = t558 + 0.1000000000e1 * t1216;
  const float_t t1219 = J__body * t1218;
  const float_t t1225 = 0.4e1 * t481;
  const float_t t1226 = 0.3e1 * t477;
  const float_t t1227 = 0.2e1 * t479;
  const float_t t1228 = t1225 + t482 + t1226 + t1227;
  const float_t t1230 = t287 * Fx__body;
  const float_t t1232 = 0.3e1 * t471;
  const float_t t1233 = 0.2e1 * t473;
  const float_t t1234 = -0.1e1 * t1230 - t1232 - t1233;
  const float_t t1249 = t20 * t18 * t15 * Fy__body;
  const float_t t1252 = t276 * t18 * t809;
  const float_t t1255 = t249 * t246 * vx__body * m__body;
  const float_t t1256 = t77 * t352;
  const float_t t1261 = t74 * t1088;
  const float_t t1266 = t203 - t445;
  const float_t t1269 = 0.3e1 * t420;
  const float_t t1274 = Fx__body * t74 * vy__body;
  const float_t t1276 = -t1191;
  const float_t t1279 = -t1193 - t1002;
  const float_t t1283 = 0.4e1 * t177;
  const float_t t1289 = 0.3e1 * t443;
  const float_t t1291 = -t1206 * Tz__body;
  const float_t t1293 = 0.7e1 * t450;
  const float_t t1305 = -0.1e1 * t482 - t1225 - t1226 - t1227;
  const float_t t1321 = vx__body * t581;
  const float_t t1335 = 0.3e1 * t363;
  const float_t t1340 = -0.5e1 * vy__body * t449 - 0.2e1 * vx__body * t1088;
  const float_t t1342 = 0.3e1 * t367;
  const float_t t1346 = 0.3e1 * t1089;
  const float_t t1347 = 0.4e1 * t374;
  const float_t t1351 = 0.3e1 * t296;
  const float_t t1357 = -t1351 - t301;
  const float_t t1362 = 0.3e1 * t268;
  const float_t t1368 = -t1082 - 0.4e1 * t287;
  const float_t t1385 =
      t23 * (t52 * (t58 + t15 * (t64 + t61) * J__body +
                    omega__body * (-t28 - t30) * t44) +
             t5 * (t12 * (t33 * (-0.1e1 * t31 + t29 + t28) * t26 +
                          t15 * (t38 + t39 - 0.1e1 * t987) * J__body +
                          omega__body * t56 * t44) +
                   t119 + t15 * (t496 - 0.1e1 * t101) * t26 +
                   omega__body * (pos__y__contact * t1003 + vx__body * t59) *
                       J__body -
                   0.1e1 * t20 * pos__x__contact * t44 - 0.1e1 * t132) +
             t113 * (-0.1e1 * omega__body * vy__body * t44 + t15 * t139) * t16 +
             t12 * (t118 * t588 + t15 * t10 * vx__body * t26 +
                    omega__body *
                        (pos__x__contact * t1003 -
                         0.1e1 * Fx__body * pos__y__contact * vx__body) *
                        J__body +
                    t496 * t44 - t103) +
             t33 * (t55 + t45 + 0.2e1 * t47) * t26 - 0.1e1 * t141 * t108 +
             t144 * vx__body * Tz__body * m__body +
             J__body * (-0.1e1 * t296 + t298)) +
      t211 *
          (t77 * (-t196 + t214 + t201 + t1050) * t26 +
           t33 * (t221 + t223 + t226 + t1056) * J__body + t237) *
          gamma__5 +
      t52 *
          (t12 * (t77 * t677 * t26 +
                  t33 * (t74 * t671 + t651 + t654 + t655) * J__body + t660) +
           t249 * (t341 + t344 + t343) * t26 +
           t77 * (t355 + t357 - t351) * J__body +
           t33 *
               (-t362 + t364 + t16 * J__body * t1078 +
                pos__x__contact * (pos__y__contact * J__body * t1083 + t368) -
                t1090 + t375) *
               m__body +
           t15 *
               (t16 * (-t1094 - t1095) * Fy__body +
                pos__x__contact * pos__y__contact * t1101 + t1105) *
               J__body +
           omega__body *
               (pos__x__contact * pos__y__contact * t1114 + t16 * t1110 +
                t18 * t1118) *
               t44) *
          gamma__5 +
      t5 *
          (t113 * t1131 * t419 +
           t12 * (t249 * (-t242 - t245 + t1134 - t682) * t26 +
                  t77 * (t817 + t253 + t255 - t686) * J__body +
                  t33 *
                      (t263 + t266 + t16 * t1141 +
                       pos__x__contact *
                           (pos__y__contact * J__body * t1143 + t273) -
                       t285 + t18 * t1148) *
                      m__body +
                  t15 * (t140 * t1159 * Fy__body + t16 * t1156 + t18 * t1162) *
                      J__body +
                  omega__body *
                      (pos__x__contact * pos__y__contact * t1083 + t16 * t1078 +
                       t18 * t1170) *
                      t44) +
           t77 *
               (t514 + t74 * (t517 + t515) + t156 * J__body * t1179 +
                pos__x__contact * (t283 - t1182) - t1186) *
               m__body +
           t33 *
               (t16 * pos__y__contact * t1195 + pos__x__contact * t18 * t1199 +
                t74 * t1191 - t1202) *
               J__body +
           t15 *
               (t74 * t1207 + t1209 +
                pos__x__contact * (t18 * t1210 * Tz__body - t852) - t1215 -
                0.1e1 * pos__y__contact * t1219) *
               m__body +
           omega__body * (pos__x__contact * t1228 + pos__y__contact * t1234) *
               J__body +
           (pos__x__contact * t453 * t21 - 0.1e1 * t867) * t44) *
          gamma__5 +
      t113 * (-0.1e1 * t1249 + t1252 + t1255 - 0.1e1 * t1256) * t637 +
      t12 *
          (t77 *
               (-t754 - 0.1e1 * t1261 + t16 * (-0.1e1 * t409 - t411) +
                t72 * J__body * t1266 + t1269 - t760) *
               m__body +
           t33 *
               (-0.1e1 * t1274 + t16 * pos__y__contact * t1276 +
                pos__x__contact * t18 * t1279 +
                t165 * (-0.1e1 * t175 - t1283)) *
               J__body +
           t15 *
               (-t1289 + t156 * t1291 +
                pos__x__contact * (-t1293 - 0.1e1 * t1219) +
                t165 * (-t1094 - t161) * Tz__body + t464) *
               m__body +
           omega__body * (pos__x__contact * t1234 + pos__y__contact * t1305) *
               J__body -
           0.1e1 *
               (0.1000000000e1 * t494 +
                0.1000000000e1 * pos__y__contact * t1218) *
               t44) *
          gamma__5 +
      t249 * gamma__5 * (-0.1e1 * t340 - 0.1e1 * t342 + t1321) * t26 -
      0.1e1 * t886 *
          (0.1000000000e1 * t18 * t62 + 0.1000000000e1 * t354 +
           0.1000000000e1 * t356) *
          J__body +
      t611 *
          (-0.1e1 * t361 - t1335 + t16 * t1340 +
           pos__x__contact * (pos__y__contact * t1148 - t1342) + t1346 -
           t1347) *
          m__body +
      t623 *
          (t16 * (-t1351 - 0.1e1 * t300) +
           pos__x__contact * pos__y__contact * t1162 + t18 * t1357) *
          J__body +
      omega__body * gamma__5 *
          (t16 * (-t1362 - t395) + pos__x__contact * pos__y__contact * t1170 +
           t18 * t1368) *
          t44 +
      gamma__5 * J__body *
          (-0.1000000000e1 * vy__body * t482 - 0.1000000000e1 * t287 * t175 -
           0.1000000000e1 * t21 * t298 - 0.1000000000e1 * t1216 * Fy__body);
  const float_t t1412 = -t1083;
  const float_t t1508 = t1230 + t1232 + t1233;
  const float_t t1602 =
      t643 * t1385 +
      t211 *
          (t77 * (t196 + t199 - t201 - t1050) * t26 +
           t33 * (t666 + t668 + t670 - t1056) * J__body + t679) *
          gamma__5 +
      t52 *
          (t12 * (t77 * t235 * t26 +
                  t33 * (t74 * t229 + t181 + t186 + t190) * J__body + t208) +
           t249 * (-t341 - t720 - t343) * t26 +
           t77 * (-t355 - t357 + t350) * J__body +
           t33 *
               (t362 - t364 + t16 * J__body * t1170 +
                pos__x__contact * (pos__y__contact * J__body * t1412 - t368) +
                t1090 - t375) *
               m__body +
           t15 *
               (t16 * (t20 + t1095) * Fy__body -
                pos__x__contact * pos__y__contact * t1101 - t1105) *
               J__body +
           omega__body *
               (pos__x__contact * pos__y__contact * t1143 + t18 * t1110 +
                t16 * t1118) *
               t44) *
          gamma__5 +
      t5 *
          (-t113 * t1131 * t419 +
           t12 * (t249 * (t242 + t245 - 0.1e1 * t1134 + t247) * t26 +
                  t77 * (-0.1e1 * t817 - t253 - t255 + t256) * J__body +
                  t33 *
                      (-t263 - t266 + t16 * t1148 +
                       pos__x__contact *
                           (pos__y__contact * J__body * t1114 - t273) +
                       t285 + t18 * t1141) *
                      m__body +
                  t15 * (-t140 * t1159 * Fy__body + t18 * t1156 + t16 * t1162) *
                      J__body +
                  omega__body *
                      (pos__x__contact * pos__y__contact * t1412 + t18 * t1078 +
                       t16 * t1170) *
                      t44) +
           t77 *
               (-t824 + t74 * (-t517 - 0.1e1 * t515) - t156 * J__body * t1179 +
                pos__x__contact * (-t830 + t1182) + t1186) *
               m__body +
           t33 *
               (-t16 * pos__y__contact * t1195 - pos__x__contact * t18 * t1199 +
                t74 * t1276 + t1202) *
               J__body +
           t15 *
               (t74 * t1291 - t1209 +
                pos__x__contact * (-t18 * t1210 * Tz__body + t552) + t1215 +
                t855 * t1088) *
               m__body +
           omega__body * (pos__x__contact * t1305 + pos__y__contact * t1508) *
               J__body +
           (-0.1e1 * pos__x__contact * t1218 + t462 * t2) * t44) *
          gamma__5 +
      t113 * (t1249 - 0.1e1 * t1252 - 0.1e1 * t1255 + t1256) * t637 +
      t12 *
          (t77 *
               (t406 + t1261 + t16 * (t409 + t411) - t72 * J__body * t1266 -
                t1269 + t423) *
               m__body +
           t33 *
               (t1274 + t16 * pos__y__contact * t1191 -
                pos__x__contact * t18 * t1279 + t165 * (t175 + t1283)) *
               J__body +
           t15 *
               (t1289 + t156 * t1207 +
                pos__x__contact * (t453 * t1088 + t1293) +
                t165 * (t20 + t161) * Tz__body - t786) *
               m__body +
           omega__body * (pos__y__contact * t1228 + pos__x__contact * t1508) *
               J__body +
           t10 * t462 * t44) *
          gamma__5 +
      t249 * gamma__5 * (t340 + t342 - 0.1e1 * t1321) * t26 +
      t77 * (t39 + t987 + t37) * gamma__5 * t589 +
      t611 *
          (t361 + t1335 - t16 * t1340 +
           pos__x__contact * (pos__y__contact * t1141 + t1342) - t1346 +
           t1347) *
          m__body +
      t623 *
          (t16 * (t1351 + t300) + pos__x__contact * pos__y__contact * t1156 -
           t18 * t1357) *
          J__body +
      omega__body * gamma__5 *
          (t16 * (t287 + t1362) + pos__x__contact * pos__y__contact * t1078 -
           t18 * t1368) *
          t44 +
      t638 * t462 * t637;
  const float_t tmp__2 = t973 * t1602 * t25;
  const float_t t1606 = sqrt(t116);
  const float_t tmp__3 = -t1606 * gamma__5 * (-1 + t643) * gamma__4;

  func(0) = tmp__1;
  func(1) = tmp__2;
  func(2) = tmp__3;

  return func;
}

Matrix contact_force_dt4_dx(VectorRef x, VectorRef u) {
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

Matrix contact_force_dt4_du(VectorRef x, VectorRef u) {
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
