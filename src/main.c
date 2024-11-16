#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "lexer.h"
#include "symbol_table.h"
#include "parser.h"
#include "types.h"
#include "eval.h"
#include "scope.h"

void free_ast(ASTNode* node) {
    if (!node) return;
    free_ast(node->left);
    free_ast(node->right);
    free(node);
}

// Fonction d'interprétation
void interpret(const char* input, Scope* scope) {
    lexer(input);
    index_token = 0;

    if (strcmp(input, "use_local") == 0) {
        scope->use_local = 1; // Active la portee locale
        printf("Passage a la portee locale.\n");
        return;
    }

    if (strcmp(input, "use_global") == 0) {
        scope->use_local = 0; //Active la portee globale
        printf("Passage a la portee globale.\n");
        return;
    }

    // Gestion de l'instruction print()
    if (tokens[index_token].type == token_var && tokens[index_token].var_name == 'p') {
        index_token++;
        print(scope);
    } else {
        // Analyse de l'expression ou de l'affectation
        ASTNode* root = parse_assignment(scope);
        if (root->type == token_var) {
            printf("Variable '%c' = %d\n", root->var_name, get_variable(scope, root->var_name));
        } else {
            double result = eval_expression(root);
            printf("Résultat: %lf\n", result);
        }
        free_ast(root);
    }
}

// Lecture des instructions à partir d'un fichier
void read_file(const char* f, Scope* scope) {
    FILE* file = fopen(f, "r");
    if (file == NULL) {
        printf("Erreur: Impossible d'ouvrir le fichier %s\n", f);
        return;
    }

    char line[256]; // taille max de ligne
    while (fgets(line, sizeof(line), file)) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        interpret(line, scope); // interprete chaque ligne
    }

    fclose(file);
    printf("Fin de la lecture du fichier %s.\n", f);
}

// Fonction principale avec REPL
int main() {
    Scope scope;
    init_scope(&scope);

    printf("Bienvenue dans l'interpréteur\n");
    printf("Tapez 'exit' pour quitter, 'use_local' ou 'use_global' pour changer de portée.\n");
    printf("Tapez 'file:<nom_du_fichier>' pour exécuter un fichier.\n");

    char input[256]; // Entrée utilisateur

    while (1) {
        printf("> "); // Invite de commande
        if (!fgets(input, sizeof(input), stdin)) {
            break; // Arrête la boucle en cas d'erreur de lecture
        }

        // Supprime le caractère de fin de ligne
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Vérifie si l'utilisateur veut quitter
        if (strcmp(input, "exit") == 0) {
            printf("Au revoir !\n");
            break;
        }

        // Vérifie si l'utilisateur demande un fichier
        if (strncmp(input, "file:", 5) == 0) {
            read_file(input + 5, &scope); // Passe le scope pour lire le fichier
        } else {
            // Interpréter l entre utilisateur
            interpret(input, &scope);
        }
    }

    return 0;
}
