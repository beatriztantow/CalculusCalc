#include <ctype.h>

#include <lexer.h>
#include <parser.h>


static double parenthesis(char *s, int *error, int *advancedChar);

static int isDigit(char* s) {
    return (s[0] >= '0' && s[0] <= '9');
}

static int isSign(char* s) {
    return (s[0] == '-' || s[0] == '+');
}

static int isEOS(char* s){
    return (s[0] == '\0');
}

static int isDot(char* s) {
    return (s[0] == '.');
}

static double mountDouble(int* integerPart, int* fractionalPart, int* amountDigits) {
    double aux = *fractionalPart;
    while (*amountDigits)
    {
        aux = aux / 10;
        *amountDigits = *amountDigits - 1;
    }

    return (*integerPart + aux);
}

static double number(char* s, int* error, int* advancedChar) {
    int i = 0;
    int dot = 0;
    int integerPart = 0;
    int fractionalPart = 0;
    int amountDigits = 0;
    double resp;

    if (isSign(s)) { i++; }
    
    if (!(isDot(s + i) || isDigit(s + i))) {
        *advancedChar = 0;
        *error = ERR_NAN;
        return 0;
    }

    *error = ERR_SUCESS;
    
    if (isDot(s + i)) {
        dot = 1;
        i++;
    }
    else {
        while (!(isEOS(s + i)) && isDigit(s + i)) {
            integerPart = integerPart*10 + (s[i] - '0');
            i++;
        }
    }
    
    if(!dot && isDot(s + i) && isDigit(s + i + 1)) {
        i++;
    }

    if (dot && !(isDigit(s + i))) {
        *advancedChar = 0;
        *error = ERR_NAN;
        return 0;
    }
    
    while (!(isEOS(s + i)) && isDigit(s + i))
    {
        fractionalPart = fractionalPart*10 + (s[i] - '0');
        amountDigits++;
        i++;
    }

    *advancedChar = i;

    resp = mountDouble(&integerPart, &fractionalPart, &amountDigits);

    if (s[0] == '-') {
        return resp * -1;
    }

    return resp;
}

static double factor(char* s, int* error, int* advancedChar) {
    double resp;
    resp = parenthesis(s, error, advancedChar);
    if (*error == ERR_SUCESS) {
        return resp;
    }
    else {
        return number(s, error, advancedChar);
    }
}

static double term(char* s, int* error, int* advancedChar) {
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

static double expression(char* s, int* error, int* advancedChar) {
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

static double parenthesis(char* s, int* error, int* advancedChar) {
    double resp = 0.0;
    if(s[0] == '(') {
        resp = expression(s + 1, error, advancedChar);
        if (*error == ERR_SUCESS) {
            if (!(s[*advancedChar + 1] == ')')) {
                *error = ERR_NAP;
                resp = 0.0;
            }
            else {
                *advancedChar = *advancedChar + 2;
            }
        }
    }
    else {
        *error = ERR_NAP;
        *advancedChar = 0;
    }
    return resp;
}

double parser(char* s, int* error) {
    int advancedChar = 0;
    char *lexeme;
    double resp = 0.0;
    lexeme = lexer(s, error);
    if(*lexeme == '\0'){
        *error = ERR_EMPTYSTRING;
        return resp;
    }
    resp = expression(lexeme, error, &advancedChar);
    if(*error == ERR_SUCESS && lexeme[advancedChar] != '\0') {
        *error = ERR_PARTIALEXPRESSION;
    }
    free(lexeme);
    return resp;
}
