#include<stdio.h>
#include<assert.h>
#include<math.h>

#include<parser.h>

#define TOL 0.0000001
#define fpequal(a, b) (fabs((a)-(b)) < TOL)

int main(void){
    
    double n;
    int error;

    n = parser("+123", &error);
    assert(fpequal(123.0, n));
    assert(error == ERR_SUCESS);

    n = parser("+123.0", &error);
    assert(fpequal(123.0, n));
    assert(error == ERR_SUCESS);
    
    n = parser("-123", &error);
    assert(fpequal(n, -123.0));
    assert(error == ERR_SUCESS);
    
    n = parser("-123.0", &error);
    assert(fpequal(n, -123.0));
    assert(error == ERR_SUCESS);
    
    n = parser("123", &error);
    assert(fpequal(n, 123.0));
    assert(error == ERR_SUCESS);
    
    n = parser("123.0666", &error);
    assert(fpequal(n, 123.0666));
    assert(error == ERR_SUCESS);
    
    n = parser(".666", &error);
    assert(fpequal(0.666, n));
    assert(error == ERR_SUCESS);

    n = parser(".666.666", &error);
    assert(error == ERR_NAN);

    n = parser(".", &error);
    assert(error == ERR_NAN);

    n = parser("0", &error);
    assert(fpequal(0.0, n));
    assert(error == ERR_SUCESS);
    
    return 0;
}