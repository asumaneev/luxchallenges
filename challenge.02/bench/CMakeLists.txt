project(${CHALLENGE_NAME}.bench)

add_executable(${PROJECT_NAME} EXCLUDE_FROM_ALL)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)


target_sources(${PROJECT_NAME}
    PRIVATE
        main.cpp
)

target_link_libraries(${PROJECT_NAME}
                      benchmark
)

foreach(CHALLENGER ${CHALLENGERS})
    target_link_libraries(${PROJECT_NAME} ${CHALLENGE_NAME}.${CHALLENGER})
endforeach()
