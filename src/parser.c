#include <stdio.h>
#include <stdlib.h>


#include "parser.h"
#include "lexer.h"
#include "eval.h"
#include "symbol_table.h"
#include "scope.h"



Token tokens[100];
int index_token;

char string_storage[100][256]; // Déclaration de la variable globale
int string_count;
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

ASTNode* parse_assignment(Scope *scope) {

    if (tokens[index_token].type == token_var && tokens[index_token + 1].type == token_equal) {
        char var_name = tokens[index_token].var_name;
        index_token += 2;
        ASTNode* expr = parse_expression();
        int value = eval_expression(expr);
        set_variable(scope,var_name, value);
        return create_node(token_var, NULL, NULL, 0, var_name);
    }
    return parse_expression();
}


// Gestion de la commande print
void print(Scope *scope) {
    if (tokens[index_token].type == token_paren1) {
        index_token++;
        if (tokens[index_token].type == token_var) { // Gestion des variable
            char var_name = tokens[index_token].var_name;
            index_token++;
            if (tokens[index_token].type == token_paren2) { // Parenthese fermante
                index_token++;
                printf("%d\n",get_variable(scope, var_name));
            } else {
                printf("Erreur: parenthèse fermante manquante pour la variable\n");
            }
        } else if (tokens[index_token].type == token_string) { // Gestion des chaînes
            int string_id = tokens[index_token].value; // Récupérer l'index
            index_token++ ;
            if ( tokens[index_token].type == token_paren2) { // Parenthèse fermante
                 index_token++;
                printf("%s\n", string_storage[string_id]); // Affiche la chaîne
            } else {

                printf("Erreur: parenthèse fermante manquante pour la chaîne\n");
            }
        } else {
            printf("Erreur: print() nécessite une variable ou une chaîne valide\n");
        }
    } else {
        printf("Erreur: parenthèse ouvrante manquante\n");
    }
}

