#ifndef PARSER_H
#define PARSER_H

enum parser_error
{
    ERR_SUCESS,
    ERR_NAN,
    ERR_PARTIALEXPRESSION
};

int parser(char* s, int* error);

#endif