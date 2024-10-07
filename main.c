#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    token_int,
    token_div,
    token_plus,
    token_mul,
    token_min,
    token_var,
    token_paren1,
    token_paren2,
    token_end
} TokenType;

typedef struct {
    TokenType type;
    char var_name;
    int value;
} Token;

Token tokens[100];
int index_token = 0;

void addToken(TokenType type, int value, char var_name) {
    tokens[index_token].type = type;
    tokens[index_token].value = value;
    tokens[index_token].var_name = var_name;
    index_token++;
}

void lexer(const char* input) {
    int i = 0;

    while (input[i] != '\0') {
        //nombre
        if (input[i] >='0' && input[i] <= '9') {
            int value = 0;
            while (input[i] >= '0' && input[i] <= '9') {
                value = value * 10 +(input[i] - '0');
                i++;
            }
            addToken(token_int, value, 0);
        }
            // variables
        else if (input[i] >= 'a' && input[i] <= 'z') {
            addToken(token_var, 0, input[i]);
            i++;
        }
        //opérateurs et parentheses
        else if (input[i] == '+') {
            addToken(token_plus, 0, 0);
            i++;
        }
        else if (input[i] == '-') {
            addToken(token_min,0, 0);
            i++;
        }
        else if (input[i] == '*') {
            addToken(token_mul,0, 0);
            i++;
        }
        else if (input[i] == '/') {
            addToken(token_div, 0, 0);
            i++;
        }
        else if (input[i] == '(') {
            addToken(token_paren1, 0, 0);
            i++;
        }
        else if (input[i] == ')') {
            addToken(token_paren2, 0, 0);
            i++;
        }
        else {
            i++;
        }
    }
    addToken(token_end, 0, 0);
}

int parse(int *current_token) {
    return 0;
}

int main() {
    const char *code = "b = (1 + 2) * (3 - 1)";
    lexer(code);
    for (int i = 0; i < index_token; i++) {
        if (tokens[i].type == token_int) {
            printf("Token: int, value: %d\n", tokens[i].value);
        } else if (tokens[i].type == token_var) {
            printf("Token: var, name: %c\n", tokens[i].var_name);
        } else if (tokens[i].type == token_plus) {
            printf("Token: + \n");
        }
        else if (tokens[i].type == token_min) {
            printf("Token: -\n");
        }
        else if (tokens[i].type == token_mul) {
            printf("Token: * \n");
        } else if (tokens[i].type == token_div) {
            printf("Token : / \n");
        } else if (tokens[i].type == token_paren1) {
            printf("Token: ( \n");
        } else if (tokens[i].type == token_paren2) {
            printf("Token:  )\n");
        } else if (tokens[i].type == token_end) {
            printf("Token: end\n");
        }
        else {
            printf("unknown Token\n");
        }
    }
    return 0;
}
