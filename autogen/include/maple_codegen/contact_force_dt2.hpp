#ifndef MAPLE_AUTOGEN_CONTACT_FORCE_DT2_HPP__
#define MAPLE_AUTOGEN_CONTACT_FORCE_DT2_HPP__

#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector contact_force_dt2(VectorRef x, VectorRef u);
Matrix contact_force_dt2_dx(VectorRef x, VectorRef u);
Matrix contact_force_dt2_du(VectorRef x, VectorRef u);

#endif // MAPLE_AUTOGEN_CONTACT_FORCE_DT2_HPP__
