#ifndef PARSER_H
#define PARSER_H

#include "ast.h"
#include "scope.h"

// Autres déclarations
ASTNode* parse_statement(Scope *scope);
ASTNode* parse_expression(Scope *scope);
ASTNode* parse_factor(Scope *scope);
ASTNode* parse_term(Scope *scope);
ASTNode* parse_while(Scope *scope);
ASTNode* parse_assignment(Scope *scope);

void print(Scope *scope);

#endif
