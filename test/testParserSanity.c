#include<stdio.h>
#include<assert.h>

#include<parser.h>

int main(void){
    
    double n;
    int error;

    n = parser("          ", &error);
    assert(ERR_EMPTYSTRING == error);
}