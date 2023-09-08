#ifndef MAPLE_AUTOGEN_ROSPO_COM_COST_FUNC_HPP__
#define MAPLE_AUTOGEN_ROSPO_COM_COST_FUNC_HPP__

#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector rospo_com_cost_func(VectorRef x, VectorRef u);
Matrix rospo_com_cost_func_dx(VectorRef x, VectorRef u);
Matrix rospo_com_cost_func_du(VectorRef x, VectorRef u);

#endif // MAPLE_AUTOGEN_ROSPO_COM_COST_FUNC_HPP__
