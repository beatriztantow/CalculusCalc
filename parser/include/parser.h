#ifndef PARSER_H
#define PARSER_H

enum parser_error
{
    ERR_SUCESS,
    ERR_NAN
};

int parser(char* s, int* error);

#endif