#include<stdio.h>

#include<parser.h>

#define MAXLINE 666

int main(void){
    char exp[MAXLINE];
    int error;
    double val;
    while (1) {
        printf("Digite uma expressao: ");
        scanf("%s", exp);
        val = parser(exp, &error);
        if(error == ERR_SUCESS){
            printf("Expressao: %f.\n", val);
        }else{
            printf("Entrada invalida.\n");
        }
    }
    return 0;
}