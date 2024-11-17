#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "lexer.h"
#include "eval.h"
#include "symbol_table.h"
#include "scope.h"

// Variables globales
Token tokens[100];
int index_token = 0;

char string_storage[100][256]; // Stockage des chaînes
int string_count = 0;

// Analyse un facteur
ASTNode* parse_factor(Scope* scope) {
    if (tokens[index_token].type == token_int) {
        int value = tokens[index_token].value;
        index_token++;
        return create_node(token_int, NULL, NULL, value, 0);
    } else if (tokens[index_token].type == token_var) {
        char var_name = tokens[index_token].var_name;
        if (var_name == '\0') {
            printf("Erreur: nom de variable vide\n");
            exit(EXIT_FAILURE);
        }
        index_token++;
        return create_node(token_var, NULL, NULL, 0, var_name);
    } else if (tokens[index_token].type == token_paren1) {
        index_token++;
        ASTNode* node = parse_expression(scope);
        if (tokens[index_token].type != token_paren2) {
            printf("Erreur: parenthèse fermante manquante\n");
            exit(EXIT_FAILURE);
        }
        index_token++;
        return node;
    } else {
        printf("Erreur: facteur invalide au token %d\n", tokens[index_token].type);
        exit(EXIT_FAILURE);
    }
}

// Analyse un terme (multiplication/division)
ASTNode* parse_term(Scope* scope) {
    ASTNode* node = parse_factor(scope);
    while (tokens[index_token].type == token_mul || tokens[index_token].type == token_div) {
        TokenType type = tokens[index_token].type;
        index_token++;
        ASTNode* right = parse_factor(scope);
        node = create_node(type, node, right, 0, 0);
    }
    return node;
}

// Analyse une expression (addition/soustraction/ comparaison)
ASTNode* parse_expression(Scope* scope) {
    ASTNode* node = parse_term(scope);
    while (tokens[index_token].type == token_plus ||
           tokens[index_token].type == token_min ||
           tokens[index_token].type == token_less ||
           tokens[index_token].type == token_greater ||
           tokens[index_token].type == token_equal_equal) {
        TokenType type = tokens[index_token].type;
        index_token++;
        ASTNode* right = parse_term(scope);
        node = create_node(type, node, right, 0, 0);
    }
    return node;
}

// Analyse une affectation ou une boucle while
ASTNode* parse_assignment(Scope* scope) {
    if (tokens[index_token].type == token_var && tokens[index_token + 1].type == token_equal) {
        char var_name = tokens[index_token].var_name;
        if (var_name == '\0') {
            printf("Erreur: nom de variable vide\n");
            exit(EXIT_FAILURE);
        }
        index_token += 2; // equal 
        ASTNode* expr = parse_expression(scope);
        int value = eval_expression(expr, scope);
        set_variable(scope, var_name, value);
        return create_node(token_var, NULL, NULL, 0, var_name);
    } else if (tokens[index_token].type == token_while) {
        index_token++; // while

        // verification de la parenthese ouvrante
        if (tokens[index_token].type != token_paren1) {
            printf("Erreur: parenthese ouvrante manquante après while\n");
            exit(EXIT_FAILURE);
        }
        index_token++; // Passe la parenthèse ouvrante

        // Analyse la condition de la boucle
        ASTNode* condition = parse_expression(scope);

        // Vérification de la parenthese fermante
        if (tokens[index_token].type != token_paren2) {
            printf("Erreur ! : parenthese fermante manquante après la condition\n");
            exit(EXIT_FAILURE);
        }
        index_token++; // parenthese fermante

        // verification de la ccolade ouvrante pour le corps de la boucle
        if (tokens[index_token].type != token_brace_open) {
            printf("Erreur  : accolade ouvrante manquante pour le corps de la boucle\n");
            exit(EXIT_FAILURE);
        }
        index_token++; // Passe l accolade ouvrante

        // Analyse le corps de la boucle
        ASTNode* body = NULL;
        while (tokens[index_token].type != token_brace_close && tokens[index_token].type != token_end) {
            ASTNode* statement = parse_assignment(scope);
            if (body == NULL) {
                body = statement;
            } else {
                body = create_node(token_body, body, statement, 0, 0);
            }
        }

        // Vérification de accolade fermante pour la boucle
        if (tokens[index_token].type != token_brace_close) {
            printf("Erreur: accolade fermante manquante pour le corps de la boucle\n");
            exit(EXIT_FAILURE);
        }
        index_token++; // accolade fermante

        // nœud pour la boucle `while`
        return create_node(token_while, condition, body, 0, 0);
    }
    return parse_expression(scope);
}


// Gestion de la commande print
void print(Scope *scope) {
    if (tokens[index_token].type == token_paren1) {
        index_token++;
        if (tokens[index_token].type == token_var) {
            char var_name = tokens[index_token].var_name;
            index_token++;
            if (tokens[index_token].type == token_paren2) {
                index_token++;
                printf("%d\n", get_variable(scope, var_name));
            } else {
                printf("Erreur: parenthese fermante manquante pour la variable\n");
            }
        } else if (tokens[index_token].type == token_string) {
            int string_id = tokens[index_token].value;
            index_token++;
            if (tokens[index_token].type == token_paren2) {
                index_token++;
                printf("%s\n", string_storage[string_id]);
            } else {
                printf("Erreur ! : parenthese fermante manquante pour la chaine\n");
            }
        } else {
            printf("Erreur: la fonctoon print une variable ou une chaine valide\n");
        }
    } else {
        printf("Erreur: parenthese ouvrante manquante\n");
    }
}
