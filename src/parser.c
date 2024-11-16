#include "parser.h"
#include "lexer.h"
#include "eval.h"
#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>

extern Token tokens[100];
extern int index_token;

ASTNode* parse_factor() {
    if (tokens[index_token].type == token_int) {
        int value = tokens[index_token].value;
        index_token++;
        return create_node(token_int, NULL, NULL, value, 0);
    } else if (tokens[index_token].type == token_var) {
        char var_name = tokens[index_token].var_name;
        index_token++;
        return create_node(token_var, NULL, NULL, 0, var_name);
    } else if (tokens[index_token].type == token_paren1) {
        index_token++;
        ASTNode* node = parse_expression();
        if (tokens[index_token].type != token_paren2) {
            printf("Erreur: parenthèse fermante manquante\n");
            exit(EXIT_FAILURE);
        }
        index_token++;
        return node;
    } else {
        printf("Erreur: facteur invalide\n");
        exit(EXIT_FAILURE);
    }
}

ASTNode* parse_term() {
    ASTNode* node = parse_factor();
    while (tokens[index_token].type == token_mul || tokens[index_token].type == token_div) {
        TokenType type = tokens[index_token].type;
        index_token++;
        ASTNode* right = parse_factor();
        node = create_node(type, node, right, 0, 0);
    }
    return node;
}

ASTNode* parse_expression() {
    ASTNode* node = parse_term();
    while (tokens[index_token].type == token_plus || tokens[index_token].type == token_min) {
        TokenType type = tokens[index_token].type;
        index_token++;
        ASTNode* right = parse_term();
        node = create_node(type, node, right, 0, 0);
    }
    return node;
}

ASTNode* parse_assignment() {
    if (tokens[index_token].type == token_var && tokens[index_token + 1].type == token_equal) {
        char var_name = tokens[index_token].var_name;
        index_token += 2;
        ASTNode* expr = parse_expression();
        int value = eval_expression(expr);
        set_variable_value(var_name, value);
        return create_node(token_var, NULL, NULL, 0, var_name);
    }
    return parse_expression();
}


// Gestion de la commande print
void print() {
    if (tokens[index_token].type == token_paren1) {
        index_token++;
        if (tokens[index_token].type == token_var) {
            char var_name = tokens[index_token].var_name;
            index_token++;
            if (tokens[index_token].type == token_paren2) {
                index_token++;
                printf("%d\n", get_variable_value(var_name));
            } else {
                printf("Erreur: parenthèse fermante manquante\n");
            }
        } else {
            printf("Erreur: print() nécessite une variable valide\n");
        }
    } else {
        printf("Erreur: parenthèse ouvrante manquante\n");
    }
}