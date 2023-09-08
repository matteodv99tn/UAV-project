#include <maple_codegen/motor_sys_ub_u.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(motor_sys_ub_u, m) {
  m.doc() = "Maple generated code for the function motor_sys_ub_u";
  m.def("motor_sys_ub_u", &motor_sys_ub_u);
}
