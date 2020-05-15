#include <parser.h>

static int number(char* s, int* error){
    int i = 0, aux = 0;
    if ((s[0] == '-') || (s[0] == '+')){i++;}
    
    if (s[i] < '0' || s[i] > '9'){
        *error = ERR_NAN;
        return 0;
    }
    *error = ERR_SUCESS;
    
    while (s[i] != '\0' && !(s[i] < '0' || s[i] > '9')){
        aux = aux*10 + (s[i] - '0');
        i++;
    }
    if (s[0] == '-') return aux * -1;
    return aux;
}

int parser(char* s, int* error){
    return number(s, error);
}
