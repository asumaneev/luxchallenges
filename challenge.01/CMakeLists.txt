set(CHALLENGE_NAME challenge.01)

##############################################
# tasks

set(CHALLENGERS
    asumaneev
)

foreach(CHALLENGER ${CHALLENGERS})

    message("${CHALLENGE_NAME} challenger: ${CHALLENGER}")

    add_subdirectory(src/${CHALLENGER})

endforeach(CHALLENGER)

##############################################
# task example target

add_subdirectory(example)

##############################################
# task benchmark example

add_subdirectory(bench)

##############################################
# task tests
add_subdirectory(test)
