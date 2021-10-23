add_library(mallocMock mallocMock.c)
target_link_libraries(mallocMock PRIVATE loadSymbols)
target_include_directories(mallocMock PUBLIC include)
