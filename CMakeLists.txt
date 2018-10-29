cmake_minimum_required(VERSION 3.10)

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)
set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "Suppressing benchmark's installation" FORCE)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)

find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if (CMAKE_CXX_CPPCHECK)
    list(
        APPEND CMAKE_CXX_CPPCHECK
            "--enable=all"
            "--inconclusive"
            "--suppress=missingIncludeSystem"
            "--force"
            "--inline-suppr"
            "-i${CMAKE_CURRENT_SOURCE_DIR}/3rdparty"
    )
else()
    message(WARNING "cppcheck is not found")
endif()

add_subdirectory(3rdparty/gtest)
add_subdirectory(3rdparty/gbench)

add_subdirectory(challenge.00)

# add_subdirectory(tests)
# add_dependencies(challenge.00.tests challenge.00.task)
# add_dependencies(challenge.00.tests googletest)
