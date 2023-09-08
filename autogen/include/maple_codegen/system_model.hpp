#ifndef MAPLE_AUTOGEN_SYSTEM_MODEL_HPP__
#define MAPLE_AUTOGEN_SYSTEM_MODEL_HPP__

#include <maple_codegen/mapledefines.hpp>

using maple::float_t;
using maple::Matrix;
using maple::MatrixRef;
using maple::Vector;
using maple::VectorRef;

Vector system_model(VectorRef x, VectorRef u);
Matrix system_model_dx(VectorRef x, VectorRef u);
Matrix system_model_du(VectorRef x, VectorRef u);

#endif // MAPLE_AUTOGEN_SYSTEM_MODEL_HPP__
