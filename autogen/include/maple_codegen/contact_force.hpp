#ifndef MAPLE_AUTOGEN_CONTACT_FORCE_HPP__
#define MAPLE_AUTOGEN_CONTACT_FORCE_HPP__

#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector contact_force(VectorRef x);
Matrix contact_force_dx(VectorRef x);

#endif // MAPLE_AUTOGEN_CONTACT_FORCE_HPP__
