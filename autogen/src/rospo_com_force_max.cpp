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

  const float_t tmp__1 = Uvc_max;
  const float_t tmp__2 = TUvc_max;

  func(0) = tmp__1;
  func(1) = tmp__2;

  return func;
}
