cmake_minimum_required(VERSION 3.10)

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)
set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "Suppressing benchmark's installation" FORCE)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)

find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if (CMAKE_CXX_CPPCHECK)
    list(
        APPEND CMAKE_CXX_CPPCHECK
            "--enable=all"
            "-i${CMAKE_CURRENT_SOURCE_DIR}/3rdparty"
            "--suppress=missingIncludeSystem"
    )
else()
    message(WARNING "cppcheck is not found")
endif()

add_subdirectory(3rdparty/gtest)
add_subdirectory(3rdparty/gbench)

add_subdirectory(challenge.00)
