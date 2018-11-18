project(${CHALLENGE_NAME}.anonymous)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../include)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${INCLUDE_DIR}
    PRIVATE
        ${INCLUDE_DIR}/anonymous
)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${INCLUDE_DIR}/anonymous/task.hpp
    PRIVATE
        task.cpp
)
