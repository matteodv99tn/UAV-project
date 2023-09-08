#include <maple_codegen/system_model.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(system_model, m) {
  m.doc() = "Maple generated code for the function system_model";
  m.def("system_model", &system_model);
  m.def("system_model_dx", &system_model_dx);
  m.def("system_model_du", &system_model_du);
}
