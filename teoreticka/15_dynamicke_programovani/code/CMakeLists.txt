cmake_minimum_required(VERSION 3.22)
project(code C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-O0")

add_executable(fib_recursive fibonacci/fib_recursive.c)
add_executable(fib_memoization fibonacci/fib_memoization.c)
add_executable(fib_bottom_up fibonacci/fib_bottom_up.c)

add_executable(knapsack_recursive knapsack/knapsack_recursive.c)
add_executable(knapsack_memoization knapsack/knapsack_memoization.c)
add_executable(knapsack_bottom_up knapsack/knapsack_bottom_up.c)
add_executable(knapsack_memoization_items_print knapsack/knapsack_memoization_items_print.c)
add_executable(knapsack_bottom_up_items_print knapsack/knapsack_bottom_up_items_print.c)
