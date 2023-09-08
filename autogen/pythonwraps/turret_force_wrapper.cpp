#include <maple_codegen/turret_force.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(turret_force, m) {
  m.doc() = "Maple generated code for the function turret_force";
  m.def("turret_force", &turret_force);
  m.def("turret_force_dx", &turret_force_dx);
}
