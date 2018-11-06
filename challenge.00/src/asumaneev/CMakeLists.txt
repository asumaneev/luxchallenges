project(challenge.00.asumaneev)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../include)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${INCLUDE_DIR}
)

target_sources(${PROJECT_NAME}
    INTERFACE
        ${INCLUDE_DIR}/asumaneev/task.hpp
)
