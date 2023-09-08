#ifndef MAPLE_AUTOGEN_TURRET_FORCE_HPP__
#define MAPLE_AUTOGEN_TURRET_FORCE_HPP__

#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector turret_force(VectorRef x);
Matrix turret_force_dx(VectorRef x);

#endif // MAPLE_AUTOGEN_TURRET_FORCE_HPP__
