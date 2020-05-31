set(SOURCES_NUMBER
    testNumber.c
)
set(SOURCES_SUM
    testSum.c
)

add_executable(testNumber ${SOURCES_NUMBER})
add_executable(testSum ${SOURCES_SUM})

target_link_libraries(testNumber parser)
target_link_libraries(testSum parser)


add_test(NAME testNumber COMMAND testNumber)
add_test(NAME testSum COMMAND testSum)


