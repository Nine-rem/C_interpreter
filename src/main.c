#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "lexer.h"
#include "symbol_table.h"
#include "parser.h"
#include "types.h"
#include "eval.h"

void free_ast(ASTNode* node) {
    if (!node) return;
    free_ast(node->left);

    free_ast(node->right);
    free(node);
}
// Fonction d'interprétation
void interpret(const char* input) {
    lexer(input);
    index_token = 0;

    if (tokens[index_token].type  == token_var&& tokens[index_token].var_name == 'p') {
        index_token++;
        print();
    } else {
        ASTNode* root = parse_assignment();
        if (root->type == token_var) {

            printf("Variable '%c' = %d\n ", root->var_name, get_variable_value(root->var_name));
        } else {

            double result = eval_expression(root);
            printf("Résultat: %lf\n", result);

        }
        free_ast(root);
    }
}

// Fonction principale
int main() {
    printf("Bienvenue dans l\'interpreteur. Tapez 'exit' pour quitter.\n");

    char input[100];
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        if (strncmp(input,"exit", 4)== 0) {
            printf("Au revoir!\n");

        
            break;
        }
        interpret(input);
    }

    return 0;
}
