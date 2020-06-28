set(SOURCES_NUMBER
    testNumber.c
)
set(SOURCES_SUM
    testSum.c
)
set(SOURCES_SUB
    testSub.c
)
set(SOURCES_SUMSUB
    testSumSub.c
)
set(SOURCES_MULT
    testMult.c
)
set(SOURCES_PARENTHESIS
    testParenthesis.c
)

add_executable(testNumber ${SOURCES_NUMBER})
add_executable(testSum ${SOURCES_SUM})
add_executable(testSub ${SOURCES_SUB})
add_executable(testSumSub ${SOURCES_SUB})
add_executable(testMult ${SOURCES_SUB})
add_executable(testParenthesis ${SOURCES_PARENTHESIS})

target_link_libraries(testNumber parser)
target_link_libraries(testSum parser)
target_link_libraries(testSub parser)
target_link_libraries(testSumSub parser)
target_link_libraries(testMult parser)
target_link_libraries(testParenthesis parser)

add_test(NAME testNumber COMMAND testNumber)
add_test(NAME testSum COMMAND testSum)
add_test(NAME testSub COMMAND testSub)
add_test(NAME testSumSub COMMAND testSumSub)
add_test(NAME testMult COMMAND testMult)
add_test(NAME testParenthesis COMMAND testParenthesis)

