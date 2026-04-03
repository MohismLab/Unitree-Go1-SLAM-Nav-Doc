cmake_minimum_required(VERSION 2.8.3)
project(unitree_legged_sdk)

include_directories(include)

link_directories(lib)

add_compile_options(-std=c++11)

set(EXTRA_LIBS -pthread libunitree_legged_sdk_arm.so lcm)

set(CMAKE_CXX_FLAGS "-O3 -fPIC")
 

# B1 robot
add_executable(example_walk_B1 examples/example_walk_B1_sport.cpp)
target_link_libraries(example_walk_B1 ${EXTRA_LIBS})

add_executable(example_start_B1 examples/example_start_B1_sport.cpp)
target_link_libraries(example_start_B1 ${EXTRA_LIBS})

add_executable(example_joystick_B1 examples/example_joystick_B1_sport.cpp)
target_link_libraries(example_joystick_B1 ${EXTRA_LIBS})
