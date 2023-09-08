#include <maple_codegen/motor_sys_lb_x.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(motor_sys_lb_x, m) {
  m.doc() = "Maple generated code for the function motor_sys_lb_x";
  m.def("motor_sys_lb_x", &motor_sys_lb_x);
}
