set(SOURCES
    cli.c
)

add_executable(cli ${SOURCES})

target_link_libraries(cli readline::readline)
target_link_libraries(cli parser)
