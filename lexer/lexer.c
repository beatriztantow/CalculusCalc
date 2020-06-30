#include <stdlib.h>

#include <lexer.h>

char* lexer(char* s, int* error){
    int i = 0, j = 0;
    int aux = 0;
    char *newS;
    while (s[i] != '\0')
    {
        if (s[i] != ' '){
            aux++;
        }
        i++;
    }
    if (aux) {
        newS = malloc(sizeof(char) * (i - aux));
        i = 0;
        while (s[i] != '\0') {
            if (s[i] != ' ') {
                newS[j] = s[i];
                j++;
            }
            i++;
        }

        free(s);
        return newS;
    }
    return s;
}