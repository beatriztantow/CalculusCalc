#include <parser.h>

int number(char* s){
    int i = 0, aux = 0;
    if ((s[0] == '-') || (s[0] == '+')){i++;}
    while (s[i] != '\0'){
        aux = aux*10 + (s[i] - '0');
        i++;
    }
    if (s[0] == '-') return aux * -1;
    return aux;
}