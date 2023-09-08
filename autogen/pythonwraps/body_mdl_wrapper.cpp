#include <maple_codegen/body_mdl.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(body_mdl, m) {
  m.doc() = "Maple generated code for the function body_mdl";
  m.def("body_mdl", &body_mdl);
  m.def("body_mdl_dx", &body_mdl_dx);
  m.def("body_mdl_du", &body_mdl_du);
}
