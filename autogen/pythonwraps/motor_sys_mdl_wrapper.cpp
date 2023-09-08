#include <maple_codegen/motor_sys_mdl.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(motor_sys_mdl, m) {
  m.doc() = "Maple generated code for the function motor_sys_mdl";
  m.def("motor_sys_mdl", &motor_sys_mdl);
  m.def("motor_sys_mdl_dx", &motor_sys_mdl_dx);
  m.def("motor_sys_mdl_du", &motor_sys_mdl_du);
}
