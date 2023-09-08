#ifndef MAPLE_AUTOGEN_BODY_MDL_HPP__
#define MAPLE_AUTOGEN_BODY_MDL_HPP__

#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector body_mdl(VectorRef x, VectorRef u);
Matrix body_mdl_dx(VectorRef x, VectorRef u);
Matrix body_mdl_du(VectorRef x, VectorRef u);

#endif // MAPLE_AUTOGEN_BODY_MDL_HPP__
