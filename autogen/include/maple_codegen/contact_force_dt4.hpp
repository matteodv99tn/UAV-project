#ifndef MAPLE_AUTOGEN_CONTACT_FORCE_DT4_HPP__
#define MAPLE_AUTOGEN_CONTACT_FORCE_DT4_HPP__

#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector contact_force_dt4(VectorRef x, VectorRef u);
Matrix contact_force_dt4_dx(VectorRef x, VectorRef u);
Matrix contact_force_dt4_du(VectorRef x, VectorRef u);

#endif // MAPLE_AUTOGEN_CONTACT_FORCE_DT4_HPP__
