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
    //token_print

} TokenType;



typedef struct {
    TokenType type;
    char var_name;
    int value;
} Token;

#endif
