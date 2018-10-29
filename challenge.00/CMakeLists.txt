project(challenge.00.task)

set(PROJECT_NAME_EXE ${PROJECT_NAME}.exe)
set(PROJECT_NAME_BENCH ${PROJECT_NAME}.bench)

message("LIB: ${PROJECT_NAME}")
message("EXE: ${PROJECT_NAME_EXE}")
message("BENCH: ${PROJECT_NAME_BENCH}")

##############################################
# task library target

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME}
    INTERFACE
        include
)

target_sources(${PROJECT_NAME}
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/asumaneev/task.hpp
    #PUBLIC
    #PRIVATE
)

##############################################
# task example target

add_executable(${PROJECT_NAME_EXE} EXCLUDE_FROM_ALL)

target_sources(${PROJECT_NAME_EXE}
    PUBLIC
        src/main.hpp
    PRIVATE
        src/main.cpp
)

target_link_libraries(${PROJECT_NAME_EXE} ${PROJECT_NAME})

##############################################
# task benchmark example

add_executable(${PROJECT_NAME_BENCH} EXCLUDE_FROM_ALL)

target_sources(${PROJECT_NAME_BENCH}
    PUBLIC
        src/main.hpp
    PRIVATE
        src/main_bench.cpp
)

target_link_libraries(${PROJECT_NAME_BENCH}
                      ${PROJECT_NAME}
                      benchmark)

##############################################
# task tests
add_subdirectory(test)
