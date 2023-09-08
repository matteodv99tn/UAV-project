#include <maple_codegen/contact_force.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(contact_force, m) {
  m.doc() = "Maple generated code for the function contact_force";
  m.def("contact_force", &contact_force);
  m.def("contact_force_dx", &contact_force_dx);
}
