##############################################
# tasks

set(CHALLENGERS
    asumaneev
    anonymous
)

foreach(CHALLENGER ${CHALLENGERS})

    message("Challenger: ${CHALLENGER}")

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
