# Install script for directory: /home/matteo/Documents/UAV-Project/Repo/autogen/pythonwraps

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact3.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact3.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact3.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact3.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/force_contact3.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact3.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact3.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact3.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/contact_force.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/rospo_com_force.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact4.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact4.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact4.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact4.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/force_contact4.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact4.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact4.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact4.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact1.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact1.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact1.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact1.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/force_contact1.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact1.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact1.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact1.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact2.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact2.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact2.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact2.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/force_contact2.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact2.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact2.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/force_contact2.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt4.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt4.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt4.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt4.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/contact_force_dt4.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt4.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt4.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt4.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_lb.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_lb.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_lb.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_lb.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/rospo_com_force_lb.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_lb.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_lb.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_lb.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_current.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_current.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_current.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_current.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/motor_current.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_current.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_current.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_current.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt3.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt3.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt3.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt3.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/contact_force_dt3.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt3.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt3.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt3.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt1.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt1.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt1.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt1.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/contact_force_dt1.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt1.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt1.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt1.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/body_mdl.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/body_mdl.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/body_mdl.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/body_mdl.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/body_mdl.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/body_mdl.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/body_mdl.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/body_mdl.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_max.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_max.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_max.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_max.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/rospo_com_force_max.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_max.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_max.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_max.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/overall_force.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/overall_force.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/overall_force.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/overall_force.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/overall_force.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/overall_force.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/overall_force.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/overall_force.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_in_ub.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_in_ub.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_in_ub.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_in_ub.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/rospo_com_force_in_ub.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_in_ub.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_in_ub.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_in_ub.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_lb_u.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_lb_u.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_lb_u.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_lb_u.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/motor_sys_lb_u.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_lb_u.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_lb_u.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_lb_u.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_ub.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_ub.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_ub.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_ub.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/motor_force_ub.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_ub.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_ub.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_ub.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_mdl.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_mdl.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_mdl.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_mdl.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/motor_sys_mdl.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_mdl.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_mdl.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_mdl.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/turret_force.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/turret_force.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/turret_force.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/turret_force.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/turret_force.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/turret_force.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/turret_force.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/turret_force.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_mdl.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_mdl.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_mdl.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_mdl.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/motor_force_mdl.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_mdl.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_mdl.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_mdl.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/system_model.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/system_model.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/system_model.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/system_model.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/system_model.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/system_model.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/system_model.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/system_model.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_ub.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_ub.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_ub.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_ub.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/rospo_com_force_ub.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_ub.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_ub.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_ub.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_lb_x.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_lb_x.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_lb_x.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_lb_x.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/motor_sys_lb_x.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_lb_x.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_lb_x.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_lb_x.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/turret_mdl.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/turret_mdl.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/turret_mdl.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/turret_mdl.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/turret_mdl.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/turret_mdl.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/turret_mdl.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/turret_mdl.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_cost_func.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_cost_func.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_cost_func.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_cost_func.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/rospo_com_cost_func.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_cost_func.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_cost_func.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_cost_func.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_in_lb.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_in_lb.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_in_lb.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_in_lb.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/rospo_com_force_in_lb.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_in_lb.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_in_lb.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/rospo_com_force_in_lb.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_lb.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_lb.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_lb.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_lb.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/motor_force_lb.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_lb.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_lb.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_force_lb.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_ub_x.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_ub_x.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_ub_x.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_ub_x.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/motor_sys_ub_x.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_ub_x.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_ub_x.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_ub_x.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt2.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt2.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt2.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt2.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/contact_force_dt2.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt2.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt2.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/contact_force_dt2.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_ub_u.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_ub_u.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_ub_u.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_ub_u.cpython-310-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/matteo/Documents/UAV-Project/Repo/autogen/lib" TYPE MODULE FILES "/home/matteo/Documents/UAV-Project/Repo/autogen/build/pythonwraps/motor_sys_ub_u.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_ub_u.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_ub_u.cpython-310-x86_64-linux-gnu.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/matteo/Documents/UAV-Project/Repo/autogen/lib/motor_sys_ub_u.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

