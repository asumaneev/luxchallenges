project (challenge.00.test)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PUBLIC
        src/test.cpp
)

target_link_libraries(${PROJECT_NAME}
                      gtest_main
                      challenge.00.task
)
