#include<stdio.h>
#include<assert.h>

#include<parser.h>

int main(void){
    
    int n, error;

    n = parser("2+2-3+4-666", &error);
    assert(-661 == n);
    assert(ERR_SUCESS == error);

    n = parser("2+2-2+-2", &error);
    assert(ERR_PARTIALEXPRESSION == error);


    n = parser("2+2-+2+2", &error);
    assert(ERR_PARTIALEXPRESSION == error);

}