add_library(parser STATIC parser.c)

target_include_directories(parser PUBLIC include)

target_link_libraries(parser lexer)