#include <maple_codegen/turret_mdl.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(turret_mdl, m) {
  m.doc() = "Maple generated code for the function turret_mdl";
  m.def("turret_mdl", &turret_mdl);
  m.def("turret_mdl_dx", &turret_mdl_dx);
  m.def("turret_mdl_du", &turret_mdl_du);
}
