#include <maple_codegen/contact_force_dt1.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(contact_force_dt1, m) {
  m.doc() = "Maple generated code for the function contact_force_dt1";
  m.def("contact_force_dt1", &contact_force_dt1);
  m.def("contact_force_dt1_dx", &contact_force_dt1_dx);
  m.def("contact_force_dt1_du", &contact_force_dt1_du);
}
