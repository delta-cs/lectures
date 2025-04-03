cmake_minimum_required(VERSION 3.0)
project(code C)

set(CMAKE_C_STANDARD 17)

# Find OpenMP library
find_package(OpenMP REQUIRED)

add_executable(mutex_busy_wait mutex_busy_wait.c)
add_executable(cond_var cond_var.c)

add_executable(openmp openmp.c)
target_link_libraries(openmp PRIVATE OpenMP::OpenMP_C)
