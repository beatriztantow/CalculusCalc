add_library(loadSymbols::interface INTERFACE)
target_include_directories(loadSymbols PUBLIC include)

add_subdirectory(unix)

