#include <maple_codegen/mapledefines.hpp>
#include <maple_codegen/rospo_com_force_max.hpp>
#include <maple_codegen/rospo_com_force_max_params.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector rospo_com_force_max() {

  Vector func = Vector::Zero(2);

  const float_t t1 = Omega__ref * Omega__ref;
  const float_t t2 = t1 * k__l;
  const float_t tmp__1 = 4 * t2;
  const float_t t3 = pos__x__turr * pos__x__turr;
  const float_t t4 = pos__y__turr * pos__y__turr;
  const float_t t6 = sqrt(t3 + t4);
  const float_t tmp__2 = 4 * t6 * t2;

  func(0) = tmp__1;
  func(1) = tmp__2;

  return func;
}
