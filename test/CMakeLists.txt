set(SOURCES_NUMBER
    testNumber.c
)
add_executable(testNumber ${SOURCES_NUMBER})
target_link_libraries(testNumber parser)
add_test(NAME testNumber COMMAND testNumber)

set(SOURCES_SUM
    testSum.c
)
add_executable(testSum ${SOURCES_SUM})
target_link_libraries(testSum parser)
add_test(NAME testSum COMMAND testSum)

set(SOURCES_SUB
    testSub.c
)
add_executable(testSub ${SOURCES_SUB})
target_link_libraries(testSub parser)
add_test(NAME testSub COMMAND testSub)

set(SOURCES_SUMSUB
    testSumSub.c
)
add_executable(testSumSub ${SOURCES_SUB})
target_link_libraries(testSumSub parser)
add_test(NAME testSumSub COMMAND testSumSub)

set(SOURCES_MULT
    testMult.c
)
add_executable(testMult ${SOURCES_SUB})
target_link_libraries(testMult parser)
add_test(NAME testMult COMMAND testMult)

set(SOURCES_PARENTHESIS
    testParenthesis.c
)
add_executable(testParenthesis ${SOURCES_PARENTHESIS})
target_link_libraries(testParenthesis parser)
add_test(NAME testParenthesis COMMAND testParenthesis)

set(SOURCES_LEXER
    testLexer.c
)
add_executable(testLexer ${SOURCES_LEXER})
target_link_libraries(testLexer parser)
add_test(NAME testLexer COMMAND testLexer)

set(SOURCES_PARSERSANITY
    testParserSanity.c
)
add_executable(testParserSanity ${SOURCES_PARSERSANITY})
target_link_libraries(testParserSanity parser)
add_test(NAME testParserSanity COMMAND testParserSanity)

add_test(NAME memoryLeakLexer COMMAND valgrind --error-exitcode=1 --leak-check=full --track-origins=yes ./testLexer)
add_test(NAME memoryLeakMult COMMAND valgrind --error-exitcode=1 --leak-check=full --track-origins=yes ./testMult)
add_test(NAME memoryLeakNumber COMMAND valgrind --error-exitcode=1 --leak-check=full --track-origins=yes ./testNumber)
add_test(NAME memoryLeakParenthesis COMMAND valgrind --error-exitcode=1 --leak-check=full --track-origins=yes ./testParenthesis)
add_test(NAME memoryLeakSub COMMAND valgrind --error-exitcode=1 --leak-check=full --track-origins=yes ./testSub)
add_test(NAME memoryLeakSum COMMAND valgrind --error-exitcode=1 --leak-check=full --track-origins=yes ./testSum)
add_test(NAME memoryLeakSumSub COMMAND valgrind --error-exitcode=1 --leak-check=full --track-origins=yes ./testSumSub)
add_test(NAME memoryLeakParserSanity COMMAND valgrind --error-exitcode=1 --leak-check=full --track-origins=yes ./testParserSanity)