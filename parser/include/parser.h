#ifndef PARSER_H
#define PARSER_H

enum parser_error
{
    ERR_SUCESS,
    ERR_NAN,
    ERR_PARTIALEXPRESSION,
    ERR_NAP,
    ERR_EMPTYSTRING
};

double parser(char* s, int* error);

#endif