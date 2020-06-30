#include<stdio.h>
#include<assert.h>
#include<math.h>

#include<parser.h>

#define TOL 0.0000001
#define fpequal(a, b) (fabs((a)-(b)) < TOL)

int main(void){

    double n;
    int error;

    n = parser(" (2*3+9)", &error);
    assert(fpequal(15.0, n));
    assert(error == ERR_SUCESS);

    n = parser("(2*3+9) ", &error);
    assert(fpequal(15.0, n));
    assert(error == ERR_SUCESS);

    n = parser("(2 * 3 + 9)", &error);
    assert(fpequal(15.0, n));
    assert(error == ERR_SUCESS);

    n = parser(" ( 2 * 3 + 9 ) ", &error);
    assert(fpequal(15.0, n));
    assert(error == ERR_SUCESS);

    n = parser("  (  2  *  3  +  9  )  ", &error);
    assert(fpequal(15.0, n));
    assert(error == ERR_SUCESS);

    return 0;
}