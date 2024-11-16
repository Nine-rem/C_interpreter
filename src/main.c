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
void read_file(const char *f){
    FILE *file = fopen(f,"r");
    if(file ==NULL){
        printf("Erreur: Impossible d ouvrir le fichier %s \n ", f);
        return;

    }

    char line[256]; //taille max pour une line 

    while(fgets(line, sizeof(line), file)){
        // supprimer le car de fin de ligne s il existe 
        int len = strlen(line);
        if (len> 0 && line[len-1] == '\n'){
            line[ len -1 ] = '\0';
        }
      //  printf("Insctruction: %s\n",line);
        interpret(line);
    }
    fclose(file); // Ferme le fichier
    printf("Fin de la lecture du fichier %s.\n", f);
}
// Fonction principale avec REPL
int main() {
    printf("Bienvenue dans l'interpréteur\n");
    printf("Tapez 'exit' pour quitter ou 'file:<nom_du_fichier>' pour exécuter un fichier.\n");

    char input[256];  // entrées utilisateur

    while (1) {
        printf("> ");  // Invite de commande
        if (!fgets(input, sizeof(input), stdin)) {
            break;  // Arrête la boucle en cas d'erreur de lecture
        }

        // Supprimer le caractère de fin de ligne s'il existe
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Vérifier si l'utilisateur veut quitter
        if (strcmp(input, "exit") == 0) {
            printf("Au revoir !\n");
            break;
        }


        // Vérifier si l'utilisateur demande un fichier
        if (strncmp(input, "file:", 5) == 0) {
            char *file = input + 5;  // Extraire le nom du fichier
            read_file(file);  // Appeler une fonction existante pour lire un fichier
        } else {
            // Interpréter l'entrée utilisateur
            interpret(input);
        }
    }

    return 0;
}