set(SOURCES
    cli.c
)

add_executable(cli ${SOURCES})

target_link_libraries(cli parser)