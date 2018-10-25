cmake_minimum_required(VERSION 3.10)

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)
set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "Suppressing benchmark's installation" FORCE)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)


add_subdirectory(3rdparty/gtest)
add_subdirectory(3rdparty/gbench)

add_subdirectory(challenge.00)
if (DEFINED PERFORM_BENCHMARK)
    target_compile_definitions(challenge.00.task.exe
    PRIVATE
        PERFORM_BENCHMARK
)
endif()

# add_subdirectory(tests)
# add_dependencies(challenge.00.tests challenge.00.task)
# add_dependencies(challenge.00.tests googletest)
