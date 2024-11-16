#ifndef LEXER_H
#define LEXER_H

#include "types.h"

void lexer(const char* input);
void addToken(TokenType type, int value, char var_name);
extern Token tokens[100];
extern int index_token;

#endif
