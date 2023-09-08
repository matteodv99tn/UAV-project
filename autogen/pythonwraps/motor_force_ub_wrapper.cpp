#include <maple_codegen/motor_force_ub.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(motor_force_ub, m) {
  m.doc() = "Maple generated code for the function motor_force_ub";
  m.def("motor_force_ub", &motor_force_ub);
}
