cmake_minimum_required(VERSION 3.13.4)
project(projekt_22)

set(CMAKE_CXX_STANDARD 11)

add_executable(projekt_22 main.cpp search_result.cpp search_result.h single_search.cpp single_search.h pair_search.cpp pair_search.h recursive_single_search.cpp recursive_single_search.h search_algorithm_base.cpp search_algorithm_base.h projekt_22.h projekt_22_tests.h utils.h execution_timer.cpp execution_timer.h recursive_pair_search.cpp recursive_pair_search.h)