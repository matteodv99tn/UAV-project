#ifndef MAPLE_AUTOGEN_FORCE_CONTACT3_HPP__
#define MAPLE_AUTOGEN_FORCE_CONTACT3_HPP__

#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector force_contact3(VectorRef x);
Matrix force_contact3_dx(VectorRef x);

#endif // MAPLE_AUTOGEN_FORCE_CONTACT3_HPP__
