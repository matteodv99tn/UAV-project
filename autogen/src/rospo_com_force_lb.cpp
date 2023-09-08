#include <maple_codegen/mapledefines.hpp>
#include <maple_codegen/rospo_com_force_lb.hpp>
#include <maple_codegen/rospo_com_force_lb_params.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector rospo_com_force_lb() {

  Vector func = Vector::Zero(8);

  const float_t tmp__2 = phi__min;
  const float_t tmp__4 = phi__min;
  const float_t tmp__6 = phi__min;
  const float_t tmp__8 = phi__min;

  func(1) = tmp__2;
  func(3) = tmp__4;
  func(5) = tmp__6;
  func(7) = tmp__8;

  return func;
}
