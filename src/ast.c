#include "ast.h"
#include <stdlib.h>



// Analyseur
ASTNode* create_node(TokenType type, ASTNode* left, ASTNode* right, int value, char var_name) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = type;
    node->left = left;
    node->right = right;


    node->value = value;
    node->var_name = var_name;

    return node;
}
