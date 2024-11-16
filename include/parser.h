#ifndef PARSER_H
#define PARSER_H

#include "ast.h"
#include "scope.h"
ASTNode* parse_expression();

ASTNode* parse_term();

ASTNode* parse_factor();

ASTNode* parse_assignment(Scope *scope);
void print();

#endif
