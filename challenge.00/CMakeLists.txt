project(challenge.00.task)

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

set(PROJECT_NAME_EXE ${PROJECT_NAME}.exe)

add_executable(${PROJECT_NAME_EXE} EXCLUDE_FROM_ALL)

target_sources(${PROJECT_NAME_EXE}
    PRIVATE
        src/main.cpp
)

target_link_libraries(${PROJECT_NAME_EXE} ${PROJECT_NAME})
if (DEFINED PERFORM_BENCHMARK)
    target_link_libraries(${PROJECT_NAME_EXE} benchmark)
endif()

message("LIB: ${PROJECT_NAME}")
message("EXE: ${PROJECT_NAME_EXE}")
