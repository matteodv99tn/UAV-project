#ifndef MAPLE_AUTOGEN_MOTOR_FORCE_MDL_HPP__
#define MAPLE_AUTOGEN_MOTOR_FORCE_MDL_HPP__

#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector motor_force_mdl(VectorRef x);
Matrix motor_force_mdl_dx(VectorRef x);

#endif // MAPLE_AUTOGEN_MOTOR_FORCE_MDL_HPP__
