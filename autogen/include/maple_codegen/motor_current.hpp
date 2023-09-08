#ifndef MAPLE_AUTOGEN_MOTOR_CURRENT_HPP__
#define MAPLE_AUTOGEN_MOTOR_CURRENT_HPP__

#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector motor_current(VectorRef x);
Matrix motor_current_dx(VectorRef x);

#endif // MAPLE_AUTOGEN_MOTOR_CURRENT_HPP__
