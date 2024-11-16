#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"
#include "types.h"

void addToken(TokenType type, int value, char var_name) {
    tokens[index_token].type = type;
    tokens[index_token].value = value;
    tokens[index_token].var_name = var_name;
    index_token++;
    
}


void lexer(const char* input) {
    index_token = 0;
    int i = 0;
    while (input[i] != '\0' && input[i] != '\n') {
        if (input[i] == '"') { // detecte une chaîne
            i++;
            int j = 0;

            char buffer[256] = {0}; // Stockage pour la chaîne
            while (input[i] != '"' && input[i] != '\0') {
                buffer[j++] = input[i++];
            }

            if (input[i] == '"') {
                i++; // Passe le guillemet fermant

                if (string_count < 100) { // verifie si le tableau n est pas plein
                    strncpy(string_storage[string_count], buffer, 256);
                    string_storage[string_count][255] = '\0'; // Assure la terminaison

                    addToken(token_string, string_count, 0); // Stocke l'index dans value
                    string_count++;
                } else {
                    printf("Erreur: Trop de chaînes stockées\n");
                    exit(EXIT_FAILURE);
                }
            } else {
                printf("Erreur: chaîne non terminée\n");
                exit(EXIT_FAILURE);
            }
        }

        
         else if (strncmp(&input[i], "print", 5) == 0) {
            addToken(token_var, 0, 'p');
            i +=5;


        } else if (input[i] >= '0' && input[i] <= '9') {
            int value = 0;
            while(input[i] >= '0' && input[i] <= '9') {
                value = value * 10 + (input[i] - '0');
                i++;
            }
            addToken(token_int, value    , 0);
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            addToken(token_var, 0, input[i]);
            i++;
        } else if (input[i] == '+') {
            addToken(token_plus, 0, 0);
            i++;
        } else if (input[i] == '-') {
            addToken(token_min, 0, 0);
            i++;
        } else if (input[i] == '*') {
            addToken(token_mul, 0, 0);
            i++;
        } else if (input[i] == '/') {
            addToken(token_div, 0, 0);
            i++;
        } else if (input[i] == '(') {
            addToken(token_paren1, 0, 0);
            i++;
        } else if (input[i] == ')') {
            addToken(token_paren2, 0, 0);
            i++;
        } else if (input[i] == '=') {
            addToken(token_equal, 0, 0);
            i++;
        } else {
            i++; // Ignore les espaces
        }
    }
    addToken(token_end, 0, 0);
}
