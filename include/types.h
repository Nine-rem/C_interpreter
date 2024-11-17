#ifndef TYPES_H
#define TYPES_H

typedef enum {
    token_int,
    token_var,
    token_plus,
    token_min,
    token_mul,
    token_div,
    token_while,
    token_paren1,
    token_paren2,
    token_brace_open,
    token_brace_close,

    token_equal,
    token_less,
    token_greater,
    token_equal_equal,
    token_end,
    token_string,
     token_print ,
     token_body
} TokenType;


typedef struct {
    TokenType type;
    char var_name;
    int value;
} Token;

extern Token tokens[100];
extern int index_token;
extern char string_storage[100][256]; // Declaration de la variable globale
extern int string_count;

#endif
