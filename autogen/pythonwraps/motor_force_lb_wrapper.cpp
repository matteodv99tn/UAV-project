#include <maple_codegen/motor_force_lb.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(motor_force_lb, m) {
  m.doc() = "Maple generated code for the function motor_force_lb";
  m.def("motor_force_lb", &motor_force_lb);
}
