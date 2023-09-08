#include <maple_codegen/force_contact1.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(force_contact1, m) {
  m.doc() = "Maple generated code for the function force_contact1";
  m.def("force_contact1", &force_contact1);
  m.def("force_contact1_dx", &force_contact1_dx);
}
