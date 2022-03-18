cmake_minimum_required(VERSION 3.15)

project(cxx-case-convert)

set(CASE_CONVERT_TESTS OFF CACHE BOOL "Enable testing.")

add_subdirectory(src)

if(CASE_CONVERT_TESTS)
    add_subdirectory(thirdparty)
    enable_testing()
    add_subdirectory(test)
endif()
