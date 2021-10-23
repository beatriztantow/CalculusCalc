#ifndef _LOADSYMBOLS_H_
#define _LOADSYMBOLS_H_

struct symbol;

// symbol* can be cast to any function type symbolName must be
symbol* loadSymbol(char* symbolName);
void unloadSymbol(symbol* symbol);

#endif
