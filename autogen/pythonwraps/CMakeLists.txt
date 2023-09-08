pybind11_add_module(force_contact3 
    ${WRAPPER_FILE_DIR}/force_contact3_wrapper.cpp
    ${SOURCE_FILE_DIR}/force_contact3.cpp
    )
pybind11_add_module(contact_force 
    ${WRAPPER_FILE_DIR}/contact_force_wrapper.cpp
    ${SOURCE_FILE_DIR}/contact_force.cpp
    )
pybind11_add_module(rospo_com_force 
    ${WRAPPER_FILE_DIR}/rospo_com_force_wrapper.cpp
    ${SOURCE_FILE_DIR}/rospo_com_force.cpp
    )
pybind11_add_module(force_contact4 
    ${WRAPPER_FILE_DIR}/force_contact4_wrapper.cpp
    ${SOURCE_FILE_DIR}/force_contact4.cpp
    )
pybind11_add_module(force_contact1 
    ${WRAPPER_FILE_DIR}/force_contact1_wrapper.cpp
    ${SOURCE_FILE_DIR}/force_contact1.cpp
    )
pybind11_add_module(force_contact2 
    ${WRAPPER_FILE_DIR}/force_contact2_wrapper.cpp
    ${SOURCE_FILE_DIR}/force_contact2.cpp
    )
pybind11_add_module(contact_force_dt4 
    ${WRAPPER_FILE_DIR}/contact_force_dt4_wrapper.cpp
    ${SOURCE_FILE_DIR}/contact_force_dt4.cpp
    )
pybind11_add_module(rospo_com_force_lb 
    ${WRAPPER_FILE_DIR}/rospo_com_force_lb_wrapper.cpp
    ${SOURCE_FILE_DIR}/rospo_com_force_lb.cpp
    )
pybind11_add_module(motor_current 
    ${WRAPPER_FILE_DIR}/motor_current_wrapper.cpp
    ${SOURCE_FILE_DIR}/motor_current.cpp
    )
pybind11_add_module(contact_force_dt3 
    ${WRAPPER_FILE_DIR}/contact_force_dt3_wrapper.cpp
    ${SOURCE_FILE_DIR}/contact_force_dt3.cpp
    )
pybind11_add_module(contact_force_dt1 
    ${WRAPPER_FILE_DIR}/contact_force_dt1_wrapper.cpp
    ${SOURCE_FILE_DIR}/contact_force_dt1.cpp
    )
pybind11_add_module(body_mdl 
    ${WRAPPER_FILE_DIR}/body_mdl_wrapper.cpp
    ${SOURCE_FILE_DIR}/body_mdl.cpp
    )
pybind11_add_module(rospo_com_force_max 
    ${WRAPPER_FILE_DIR}/rospo_com_force_max_wrapper.cpp
    ${SOURCE_FILE_DIR}/rospo_com_force_max.cpp
    )
pybind11_add_module(overall_force 
    ${WRAPPER_FILE_DIR}/overall_force_wrapper.cpp
    ${SOURCE_FILE_DIR}/overall_force.cpp
    )
pybind11_add_module(rospo_com_force_in_ub 
    ${WRAPPER_FILE_DIR}/rospo_com_force_in_ub_wrapper.cpp
    ${SOURCE_FILE_DIR}/rospo_com_force_in_ub.cpp
    )
pybind11_add_module(motor_sys_lb_u 
    ${WRAPPER_FILE_DIR}/motor_sys_lb_u_wrapper.cpp
    ${SOURCE_FILE_DIR}/motor_sys_lb_u.cpp
    )
pybind11_add_module(motor_force_ub 
    ${WRAPPER_FILE_DIR}/motor_force_ub_wrapper.cpp
    ${SOURCE_FILE_DIR}/motor_force_ub.cpp
    )
pybind11_add_module(motor_sys_mdl 
    ${WRAPPER_FILE_DIR}/motor_sys_mdl_wrapper.cpp
    ${SOURCE_FILE_DIR}/motor_sys_mdl.cpp
    )
pybind11_add_module(turret_force 
    ${WRAPPER_FILE_DIR}/turret_force_wrapper.cpp
    ${SOURCE_FILE_DIR}/turret_force.cpp
    )
pybind11_add_module(motor_force_mdl 
    ${WRAPPER_FILE_DIR}/motor_force_mdl_wrapper.cpp
    ${SOURCE_FILE_DIR}/motor_force_mdl.cpp
    )
pybind11_add_module(system_model 
    ${WRAPPER_FILE_DIR}/system_model_wrapper.cpp
    ${SOURCE_FILE_DIR}/system_model.cpp
    )
pybind11_add_module(rospo_com_force_ub 
    ${WRAPPER_FILE_DIR}/rospo_com_force_ub_wrapper.cpp
    ${SOURCE_FILE_DIR}/rospo_com_force_ub.cpp
    )
pybind11_add_module(motor_sys_lb_x 
    ${WRAPPER_FILE_DIR}/motor_sys_lb_x_wrapper.cpp
    ${SOURCE_FILE_DIR}/motor_sys_lb_x.cpp
    )
pybind11_add_module(turret_mdl 
    ${WRAPPER_FILE_DIR}/turret_mdl_wrapper.cpp
    ${SOURCE_FILE_DIR}/turret_mdl.cpp
    )
pybind11_add_module(rospo_com_cost_func 
    ${WRAPPER_FILE_DIR}/rospo_com_cost_func_wrapper.cpp
    ${SOURCE_FILE_DIR}/rospo_com_cost_func.cpp
    )
pybind11_add_module(rospo_com_force_in_lb 
    ${WRAPPER_FILE_DIR}/rospo_com_force_in_lb_wrapper.cpp
    ${SOURCE_FILE_DIR}/rospo_com_force_in_lb.cpp
    )
pybind11_add_module(motor_force_lb 
    ${WRAPPER_FILE_DIR}/motor_force_lb_wrapper.cpp
    ${SOURCE_FILE_DIR}/motor_force_lb.cpp
    )
pybind11_add_module(motor_sys_ub_x 
    ${WRAPPER_FILE_DIR}/motor_sys_ub_x_wrapper.cpp
    ${SOURCE_FILE_DIR}/motor_sys_ub_x.cpp
    )
pybind11_add_module(contact_force_dt2 
    ${WRAPPER_FILE_DIR}/contact_force_dt2_wrapper.cpp
    ${SOURCE_FILE_DIR}/contact_force_dt2.cpp
    )
pybind11_add_module(motor_sys_ub_u 
    ${WRAPPER_FILE_DIR}/motor_sys_ub_u_wrapper.cpp
    ${SOURCE_FILE_DIR}/motor_sys_ub_u.cpp
    )


install(TARGETS force_contact3 DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS contact_force DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS rospo_com_force DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS force_contact4 DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS force_contact1 DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS force_contact2 DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS contact_force_dt4 DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS rospo_com_force_lb DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS motor_current DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS contact_force_dt3 DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS contact_force_dt1 DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS body_mdl DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS rospo_com_force_max DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS overall_force DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS rospo_com_force_in_ub DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS motor_sys_lb_u DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS motor_force_ub DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS motor_sys_mdl DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS turret_force DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS motor_force_mdl DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS system_model DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS rospo_com_force_ub DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS motor_sys_lb_x DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS turret_mdl DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS rospo_com_cost_func DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS rospo_com_force_in_lb DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS motor_force_lb DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS motor_sys_ub_x DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS contact_force_dt2 DESTINATION ${MODULE_INSTALL_DIR})
install(TARGETS motor_sys_ub_u DESTINATION ${MODULE_INSTALL_DIR})
