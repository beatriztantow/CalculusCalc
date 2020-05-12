#include<stdio.h>
#include "../include/parser.h"

int main(void){
    int n;
    n = number("+123");
    printf("%d\n", n);
    n = number("-123");
    printf("%d\n", n);
    n = number("123");
    printf("%d\n", n);
    
    return 0;
}