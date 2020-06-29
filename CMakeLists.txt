cmake_minimum_required(VERSION 3.5)

project(calculadoraBatata)


enable_testing()

add_subdirectory(lexer)
find_package(readline REQUIRED)

add_subdirectory(parser)
add_subdirectory(cli)
add_subdirectory(test)


