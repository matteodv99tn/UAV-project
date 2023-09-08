#include <maple_codegen/force_contact3.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(force_contact3, m) {
  m.doc() = "Maple generated code for the function force_contact3";
  m.def("force_contact3", &force_contact3);
  m.def("force_contact3_dx", &force_contact3_dx);
}
