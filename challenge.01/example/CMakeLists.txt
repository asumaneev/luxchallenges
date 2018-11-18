project(${CHALLENGE_NAME}.example)

add_executable(${PROJECT_NAME} EXCLUDE_FROM_ALL)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_sources(${PROJECT_NAME}
    PRIVATE
        main.cpp
)

foreach(CHALLENGER ${CHALLENGERS})
    target_link_libraries(${PROJECT_NAME} challenge.01.${CHALLENGER})
endforeach()
