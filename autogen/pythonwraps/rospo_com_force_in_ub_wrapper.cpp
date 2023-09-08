#include <maple_codegen/rospo_com_force_in_ub.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(rospo_com_force_in_ub, m) {
  m.doc() = "Maple generated code for the function rospo_com_force_in_ub";
  m.def("rospo_com_force_in_ub", &rospo_com_force_in_ub);
}
