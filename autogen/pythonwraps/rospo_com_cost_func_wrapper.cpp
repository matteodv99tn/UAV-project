#include <maple_codegen/rospo_com_cost_func.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(rospo_com_cost_func, m) {
  m.doc() = "Maple generated code for the function rospo_com_cost_func";
  m.def("rospo_com_cost_func", &rospo_com_cost_func);
  m.def("rospo_com_cost_func_dx", &rospo_com_cost_func_dx);
  m.def("rospo_com_cost_func_du", &rospo_com_cost_func_du);
}
