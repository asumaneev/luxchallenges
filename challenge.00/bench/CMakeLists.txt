project(challenge.00.bench)

add_executable(${PROJECT_NAME} EXCLUDE_FROM_ALL)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)


target_sources(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include/main.hpp
    PRIVATE
        main.cpp
)

target_link_libraries(${PROJECT_NAME}
                      benchmark
)

foreach(CHALLENGER ${CHALLENGERS})
    target_link_libraries(${PROJECT_NAME} challenge.00.${CHALLENGER})
endforeach()
