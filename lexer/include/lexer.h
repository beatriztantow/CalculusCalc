#ifndef LEXER_H
#define LEXER_H
/*
 * INPUT:
 * s it's a non-null pointer
 * error it's a output parameter
 * 
 * OUTPUT:
 * a new string without spaces from s
*/
char* lexer(char* s, int* error);

#endif