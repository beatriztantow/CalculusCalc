#include<stdio.h>
#include<assert.h>

#include<parser.h>

int main(void){
    
    double n;
    int error;

    n = parser("+123", &error);
    assert(n == 123.0);
    assert(error == ERR_SUCESS);
    n = parser("-123", &error);
    assert(n == -123.0);
    assert(error == ERR_SUCESS);
    n = parser("123", &error);
    assert(n == 123.0);
    assert(error == ERR_SUCESS);
    
    return 0;
}