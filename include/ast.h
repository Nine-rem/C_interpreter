#ifndef AST_H
#define AST_H

#include "lexer.h"

typedef struct ASTNode {
    TokenType type;
    struct ASTNode *left;
    struct ASTNode *right;
    double value;
    char var_name;
} ASTNode;

ASTNode* create_node(TokenType type, ASTNode* left, ASTNode* right, int value, char var_name);

#endif
