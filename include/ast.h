#ifndef AST_H
#define AST_H

#include "lexer.h"
#include "scope.h"

typedef struct ASTNode {
    TokenType type;          // Type du nœud (e.g., token_while, token_int)
    struct ASTNode* left;    // Sous-nœud gauche (e.g., condition pour while)
    struct ASTNode* right;   // Sous-nœud droit (e.g., corps de la boucle)
    int value;               // Valeur pour les nœuds contenant des entiers
    char var_name;           // Nom de la variable pour les nœuds de type variable
} ASTNode;

ASTNode* create_node(TokenType type, ASTNode* left, ASTNode* right, int value, char var_name);

#endif
