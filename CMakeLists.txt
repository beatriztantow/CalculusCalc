cmake_minimum_required(VERSION 3.5)

project(calculadoraBatata)
set(SOURCES
    src/main.c
    src/expressions.c
    src/operations.c
    src/ui.c
)

include_directories(include)

set(TESTS
    test/testNumber.c
)

add_library(parser STATIC src/parser.c)

add_executable(main ${SOURCES})
add_executable(testNumber ${TESTS})

target_link_libraries(main parser)
target_link_libraries(testNumber parser)

enable_testing()
add_test(NAME testNumber COMMAND testNumber)


