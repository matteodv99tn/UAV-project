#include <maple_codegen/rospo_com_force_lb.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(rospo_com_force_lb, m) {
  m.doc() = "Maple generated code for the function rospo_com_force_lb";
  m.def("rospo_com_force_lb", &rospo_com_force_lb);
}
