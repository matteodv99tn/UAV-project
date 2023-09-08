#include <maple_codegen/motor_current.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(motor_current, m) {
  m.doc() = "Maple generated code for the function motor_current";
  m.def("motor_current", &motor_current);
  m.def("motor_current_dx", &motor_current_dx);
}
