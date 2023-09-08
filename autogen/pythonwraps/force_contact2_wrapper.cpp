#include <maple_codegen/force_contact2.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(force_contact2, m) {
  m.doc() = "Maple generated code for the function force_contact2";
  m.def("force_contact2", &force_contact2);
  m.def("force_contact2_dx", &force_contact2_dx);
}
