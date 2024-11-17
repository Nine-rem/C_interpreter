#include "eval.h"
#include "symbol_table.h"
#include "scope.h"
#include <stdio.h>
#include <stdlib.h>

double eval_expression(ASTNode* node, Scope* scope) {
    if (!node) {
        printf("Erreur: nœud NULL rencontré dans l'évaluation de l'expression.\n");
        exit(EXIT_FAILURE);
    }

    switch (node->type) {
        case token_int:
            // Retourne une constante entière
            return node->value;

        case token_var: {
            // Retourne la valeur d'une variable
            double value = get_variable(scope, node->var_name);
            return value;
        }

        case token_plus:
            // Addition
            return eval_expression(node->left, scope) + eval_expression(node->right, scope);

        case token_min:
            // Soustraction
            return eval_expression(node->left, scope) - eval_expression(node->right, scope);

        case token_mul:
            // Multiplication
            return eval_expression(node->left, scope) * eval_expression(node->right, scope);

        case token_div: {
            // Division avec vérification de division par zéro
            double right = eval_expression(node->right, scope);
            if (right == 0) {
                printf("Erreur: division par zéro.\n");
                exit(EXIT_FAILURE);
            }
            return eval_expression(node->left, scope) / right;
        }

        case token_less:
            // Comparateur `<`
            return eval_expression(node->left, scope) < eval_expression(node->right, scope);

        case token_greater:
            // Comparateur `>`
            return eval_expression(node->left, scope) > eval_expression(node->right, scope);

        case token_equal_equal:
            // Comparateur `==`
            return eval_expression(node->left, scope) == eval_expression(node->right, scope);

        case token_while: {
            // Boucle `while`
            while (eval_expression(node->left, scope)) {
                eval_expression(node->right, scope); // Évalue le corps de la boucle
            }
            return 0; // Les boucles ne retournent pas de valeur
        }

        case token_body:
            // Évalue un bloc d'instructions délimité par `{}` (multiple statements)
            eval_block(node, scope);
            return 0; // Un bloc ne retourne pas de valeur

        case token_print:
            // Évaluation de l'instruction `print`
            eval_print(node->left, scope);
            return 0;

        default:
            printf("Erreur: type de nœud invalide (%d).\n", node->type);
            exit(EXIT_FAILURE);
    }
}

// Évaluation d'un bloc d'instructions
void eval_block(ASTNode* node, Scope* scope) {
    if (!node) return;

    // Parcourt récursivement les instructions du bloc
    eval_expression(node->left, scope);
    if (node->right) {
        eval_block(node->right, scope);
    }
}

// Fonction `eval_print` pour gérer l'instruction `print`
void eval_print(ASTNode* node, Scope* scope) {
    if (!node) {
        printf("Erreur: rien à imprimer.\n");
        exit(EXIT_FAILURE);
    }

    if (node->type == token_string) {
        // Affiche une chaîne de caractères
        printf("%s\n", string_storage[node->value]);
    } else {
        // Affiche une valeur numérique
        double value = eval_expression(node, scope);
        printf("%.2f\n", value);
    }
}
