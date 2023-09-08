#include <maple_codegen/mapledefines.hpp>
#include <maple_codegen/rospo_com_force_ub.hpp>
#include <maple_codegen/rospo_com_force_ub_params.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector rospo_com_force_ub() {

  Vector func = Vector::Zero(8);

  const float_t t1 = Omega__ref * Omega__ref;
  const float_t tmp__1 = t1 * k__l;
  const float_t tmp__2 = phi__max;
  const float_t tmp__3 = tmp__1;
  const float_t tmp__4 = phi__max;
  const float_t tmp__5 = tmp__3;
  const float_t tmp__6 = phi__max;
  const float_t tmp__7 = tmp__5;
  const float_t tmp__8 = phi__max;

  func(0) = tmp__1;
  func(1) = tmp__2;
  func(2) = tmp__3;
  func(3) = tmp__4;
  func(4) = tmp__5;
  func(5) = tmp__6;
  func(6) = tmp__7;
  func(7) = tmp__8;

  return func;
}
