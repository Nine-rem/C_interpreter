#ifndef TYPES_H
#define TYPES_H

typedef enum {
    token_int,
    token_div,
    token_plus,
    token_mul,
    token_min,
    token_var,
    token_paren1,
    token_paren2,
    token_equal,
    token_end,
    token_string,
    //token_print

} TokenType;



typedef struct {
    TokenType type;
    char var_name;
    int value;
} Token;

extern Token tokens[100];
extern int index_token;
extern char string_storage[100][256]; // Déclaration de la variable globale
extern int string_count;
#endif
