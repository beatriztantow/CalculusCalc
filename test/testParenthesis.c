#include<stdio.h>
#include<assert.h>
#include<math.h>

#include<parser.h>

#define TOL 0.0000001
#define fpequal(a, b) (fabs((a)-(b)) < TOL)

int main(void){

    double n;
    int error;

    n = parser("(2*3+9)", &error);
    assert(fpequal(15.0, n));
    assert(error == ERR_SUCESS);

    n = parser("((8+0))", &error);
    assert(fpequal(8.0, n));
    assert(error == ERR_SUCESS);

    n = parser("(((2+9)*(4+5)))", &error);
    assert(fpequal(99.0, n));
    assert(error == ERR_SUCESS);

    n = parser("(1)", &error);
    assert(fpequal(1.0, n));
    assert(error == ERR_SUCESS);

    n = parser("(((1)))", &error);
    assert(fpequal(1.0, n));
    assert(error == ERR_SUCESS);

    n = parser("(+1)", &error);
    assert(fpequal(1.0, n));
    assert(error == ERR_SUCESS);

    n = parser("(1.01)", &error);
    assert(fpequal(1.01, n));
    assert(error == ERR_SUCESS);

    n = parser("(+1.01)", &error);
    assert(fpequal(1.01, n));
    assert(error == ERR_SUCESS);

    n = parser("(+1.01-0.01)", &error);
    assert(fpequal(1.0, n));
    assert(error == ERR_SUCESS);

    n = parser("(1.0*2)", &error);
    assert(fpequal(2.0, n));
    assert(error == ERR_SUCESS);

    n = parser("(1.0)*(2)", &error);
    assert(fpequal(2.0, n));
    assert(error == ERR_SUCESS);

    n = parser("((1.0))*(2)", &error);
    assert(fpequal(2.0, n));
    assert(error == ERR_SUCESS);

    n = parser("()", &error);
    assert(error == ERR_NAN);

    n = parser("(", &error);
    assert(error == ERR_NAN);

    n = parser(")", &error);
    assert(error == ERR_NAN);

    n = parser("(1))", &error);
    assert(error == ERR_PARTIALEXPRESSION);

    n = parser("1)", &error);
    assert(error == ERR_PARTIALEXPRESSION);

    return 0;
}