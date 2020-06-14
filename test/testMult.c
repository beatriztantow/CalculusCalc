#include<stdio.h>
#include<assert.h>

#include<parser.h>

int main(void){
    
    double n;
    int error;

    n = parser("2*2", &error);
    assert(4.0 == n);
    assert(ERR_SUCESS == error);

    n = parser("-2*2", &error);
    assert(-4.0 == n);
    assert(ERR_SUCESS == error);

    n = parser("2*-2", &error);
    assert(ERR_PARTIALEXPRESSION == error);

    n = parser("2*+2", &error);
    assert(ERR_PARTIALEXPRESSION == error);

    n = parser("2*2*2", &error);
    assert(8.0 == n);
    assert(ERR_SUCESS == error);

    n = parser("-1*3*7", &error);
    assert(-21.0 == n);
    assert(ERR_SUCESS == error);
}