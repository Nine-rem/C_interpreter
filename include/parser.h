#ifndef PARSER_H
#define PARSER_H

#include "ast.h"

ASTNode* parse_expression();

ASTNode* parse_term();

ASTNode* parse_factor();

ASTNode* parse_assignment();
void print();
#endif
