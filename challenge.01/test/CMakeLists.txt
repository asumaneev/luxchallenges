project(${CHALLENGE_NAME}.test)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PUBLIC
        src/test.cpp
)

target_link_libraries(${PROJECT_NAME}
                      gtest_main
)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE
        -DTEST_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/test_data"
)

foreach(CHALLENGER ${CHALLENGERS})
    target_link_libraries(${PROJECT_NAME} challenge.01.${CHALLENGER})
endforeach()
