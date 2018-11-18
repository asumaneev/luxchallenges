project(${CHALLENGE_NAME}.asumaneev)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../include)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${INCLUDE_DIR}
    PRIVATE
        ${INCLUDE_DIR}/asumaneev
)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${INCLUDE_DIR}/asumaneev/task.hpp
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/task.cpp
)
