#include <maple_codegen/overall_force.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(overall_force, m) {
  m.doc() = "Maple generated code for the function overall_force";
  m.def("overall_force", &overall_force);
  m.def("overall_force_dx", &overall_force_dx);
}
