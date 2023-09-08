#ifndef MAPLE_AUTOGEN_CONTACT_FORCE_DT3_HPP__
#define MAPLE_AUTOGEN_CONTACT_FORCE_DT3_HPP__

#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector contact_force_dt3(VectorRef x, VectorRef u);
Matrix contact_force_dt3_dx(VectorRef x, VectorRef u);
Matrix contact_force_dt3_du(VectorRef x, VectorRef u);

#endif // MAPLE_AUTOGEN_CONTACT_FORCE_DT3_HPP__
