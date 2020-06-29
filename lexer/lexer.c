#include <stdlib.h>

#include <lexer.h>

char* lexer(char* s, int* error){
    int i = 0, j = 0;
    int aux = 0;
    char *newS;
    while (s[i] != '\0') {
        if (s[i] == ' '){
            aux++;
        }
        i++;
    }
    newS = malloc(sizeof(char) * (i - aux + 1));
    i = 0;
    while (s[i] != '\0') {
        if (s[i] != ' ') {
            newS[j] = s[i];
            j++;
        }
        i++;
    }
    newS[j] = '\0';
    return newS;
}
