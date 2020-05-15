set(SOURCES
    testNumber.c
)

add_executable(testNumber ${SOURCE})

target_link_libraries(testNumber parser)