cmake_minimum_required(VERSION 3.22)
project(code C)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(CMAKE_C_STANDARD 17)

add_executable(main main.c)
target_link_libraries(main PRIVATE Threads::Threads)

add_executable(counter counter.c)
target_link_libraries(counter PRIVATE Threads::Threads)

add_executable(fact fact.c)
target_link_libraries(fact PRIVATE Threads::Threads)

add_executable(matrix matrix.c)
target_link_libraries(matrix PRIVATE Threads::Threads)

add_executable(deadlock deadlock.c)
target_link_libraries(deadlock PRIVATE Threads::Threads)
