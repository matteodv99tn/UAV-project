#include <maple_codegen/motor_force_mdl.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(motor_force_mdl, m) {
  m.doc() = "Maple generated code for the function motor_force_mdl";
  m.def("motor_force_mdl", &motor_force_mdl);
  m.def("motor_force_mdl_dx", &motor_force_mdl_dx);
}
