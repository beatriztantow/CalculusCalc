cmake_minimum_required(VERSION 3.5)

project(calculadoraBatata)

include_directories(include)

add_subdirectory(parser)
add_subdirectory(cli)

set(TESTS
    test/testNumber.c
)

add_executable(testNumber ${TESTS})


target_link_libraries(testNumber parser)

enable_testing()
add_test(NAME testNumber COMMAND testNumber)
