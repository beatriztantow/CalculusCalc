#include <parser.h>

static double number(char* s, int* error, int* advancedChar){
    int i = 0;
    double aux = 0;
    if ((s[i] == '-') || (s[i] == '+')){i++;}
    
    if (s[i] < '0' || s[i] > '9'){
        *advancedChar = 0;
        *error = ERR_NAN;
        return 0;
    }
    *error = ERR_SUCESS;
    
    while (s[i] != '\0' && !(s[i] < '0' || s[i] > '9')){
        aux = aux*10 + (s[i] - '0');
        i++;
    }
    *advancedChar = i;
    if (s[0] == '-') {
        return aux * -1;
    }
    return aux;
}

static double factor (char* s, int* error, int* advancedChar) {
    return number(s, error, advancedChar);
}

static double term (char* s, int* error, int* advancedChar) {
    double auxResp;
    double resp = factor(s, error, advancedChar);
    while (ERR_SUCESS == *error
    && (s[*advancedChar] == '*' || s[*advancedChar] == '/')
    && (s[*advancedChar + 1] != '-' && s[*advancedChar + 1] != '+')) {
        int auxAdvancedChar;
        auxResp = factor(s + *advancedChar + 1, error, &auxAdvancedChar);
        if (ERR_SUCESS == *error) {
            if (s[*advancedChar] == '*'){
                resp = resp * auxResp;
            }else {
                resp = resp / auxResp;
            }
            *advancedChar = *advancedChar + auxAdvancedChar + 1;
        }
    }
    return resp;

}

static double expression (char* s, int* error, int* advancedChar) {
    double auxResp;
    double resp = term(s, error, advancedChar);
    while (ERR_SUCESS == *error
    && (s[*advancedChar] == '+' || s[*advancedChar] == '-')
    && (s[*advancedChar + 1] != '-' && s[*advancedChar + 1] != '+')) {
        int auxAdvancedChar;
        auxResp = term(s + *advancedChar + 1, error, &auxAdvancedChar);
        if (ERR_SUCESS == *error) {
            if (s[*advancedChar] == '+'){
                resp = resp + auxResp;
            }else{
                resp = resp - auxResp;
            }
            *advancedChar = *advancedChar + auxAdvancedChar + 1;
        }
    }
    return resp;
}

double parser(char* s, int* error){
    int advancedChar = 0;
    double resp = expression(s, error, &advancedChar);
    if(*error == ERR_SUCESS && s[advancedChar] != '\0') {
        *error = ERR_PARTIALEXPRESSION;
    }
    return resp;
}
