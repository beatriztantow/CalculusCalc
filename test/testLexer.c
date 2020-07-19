#include<stdio.h>
#include<assert.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#include<lexer.h>

#define TOL 0.0000001
#define fpequal(a, b) (fabs((a)-(b)) < TOL)
#define strequal(a, b) (!strcmp(a, b))

int main(void){

    char *str;
    int error;

    str = lexer(" ", &error);
    assert(strequal(str, ""));
    free(str);

    str = lexer(" (2*3+9)", &error);
    assert(strequal(str, "(2*3+9)"));
    free(str);

    str = lexer("(2*3+9) ", &error);
    assert(strequal(str, "(2*3+9)"));
    free(str);

    str = lexer("(2 * 3 + 9)", &error);
    assert(strequal(str, "(2*3+9)"));
    free(str);

    str = lexer(" ( 2 * 3 + 9 ) ", &error);
    assert(strequal(str, "(2*3+9)"));
    free(str);

    str = lexer("  (  2  *  3  +  9  )  ", &error);
    assert(strequal(str, "(2*3+9)"));
    free(str);

    return 0;
}