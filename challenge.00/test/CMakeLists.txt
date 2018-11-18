project(${CHALLENGE_NAME}.test)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PUBLIC
        src/test.cpp
)

target_link_libraries(${PROJECT_NAME}
                      gtest_main
)

foreach(CHALLENGER ${CHALLENGERS})
    target_link_libraries(${PROJECT_NAME} challenge.00.${CHALLENGER})
endforeach()
