#ifndef EVAL_H
#define EVAL_H

#include "ast.h"
#include "scope.h"
#include "symbol_table.h"

// Évalue une expression représentée sous forme d'AST
double eval_expression(ASTNode* node, Scope* scope);

// Évalue un bloc d'instructions (délimité par des accolades `{}`)
void eval_block(ASTNode* node, Scope* scope);

// Gère l'évaluation des instructions `print`
void eval_print(ASTNode* node, Scope* scope);

#endif // EVAL_H
