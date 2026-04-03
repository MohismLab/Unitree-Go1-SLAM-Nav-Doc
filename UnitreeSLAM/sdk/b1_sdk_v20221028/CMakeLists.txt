cmake_minimum_required(VERSION 2.8.3)
project(unitree_legged_sdk)

include_directories(include)

# add_compile_options(-std=c++11)
add_compile_options(-std=c++14)

# check arch and os
message("-- CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
if("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "x86_64.*")
  set(ARCH amd64)
endif()
if("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "aarch64.*")
  set(ARCH arm64)
endif()

link_directories(lib/cpp/${ARCH})
set(EXTRA_LIBS -pthread libunitree_legged_sdk.so)

set(CMAKE_CXX_FLAGS "-O3 -fPIC")

# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib/cpp/${ARCH})  # .lib .a
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../lib/python)  # .so .dylib
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../py/bin)   #  .exe .dll

# one pc one process
add_executable(example_position example/example_position.cpp)
target_link_libraries(example_position ${EXTRA_LIBS})

add_executable(example_velocity example/example_velocity.cpp)
target_link_libraries(example_velocity ${EXTRA_LIBS})

add_executable(example_torque example/example_torque.cpp)
target_link_libraries(example_torque ${EXTRA_LIBS})

add_executable(example_walk example/example_walk.cpp)
target_link_libraries(example_walk ${EXTRA_LIBS})

add_executable(example_joystick example/example_joystick.cpp)
target_link_libraries(example_joystick ${EXTRA_LIBS})

add_executable(example_dance example/example_dance.cpp)
target_link_libraries(example_dance ${EXTRA_LIBS})

# # python
# # add_subdirectory(third_party/pybind11)
# pybind11_add_module(robot_interface_high example_py/robots/python_interface_high.cpp)
# target_link_libraries(robot_interface_high ${EXTRA_LIBS})

# pybind11_add_module(robot_interface_low example_py/robots/python_interface_low.cpp)
# target_link_libraries(robot_interface_low ${EXTRA_LIBS})

# pybind11_add_module(robot_interface example_py/robots/python_interface_test.cpp)
# target_link_libraries(robot_interface ${EXTRA_LIBS})

# install
install(TARGETS
  example_position example_velocity example_torque example_walk example_joystick example_dance
  DESTINATION bin/unitree)
install(DIRECTORY lib/cpp/${ARCH}/
  DESTINATION lib/unitree
  USE_SOURCE_PERMISSIONS)

