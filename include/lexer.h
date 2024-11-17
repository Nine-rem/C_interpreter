#ifndef LEXER_H
#define LEXER_H

#include "types.h"

void lexer(const char *input);
void addToken(TokenType type, int value, char var_name);
 
#endif
