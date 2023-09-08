#ifndef MAPLE_AUTOGEN_FORCE_CONTACT2_HPP__
#define MAPLE_AUTOGEN_FORCE_CONTACT2_HPP__

#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector force_contact2(VectorRef x);
Matrix force_contact2_dx(VectorRef x);

#endif // MAPLE_AUTOGEN_FORCE_CONTACT2_HPP__
