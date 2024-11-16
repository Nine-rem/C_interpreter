#include "eval.h"
#include "symbol_table.h"
#include <stdio.h>


double eval_expression(ASTNode* node) {
    if (node->type == token_int) {
        return node->value;
    } else if (node->type == token_var) {
        return get_variable_value(node->var_name);

    } else  if (node->type == token_plus) {

        return eval_expression(node->left) + eval_expression(node->right);

    } else if (node->type == token_min) {

     return eval_expression(node->left)- eval_expression(node->right);
    } else if  (node->type == token_mul) {

        return eval_expression(node->left) * eval_expression(node->right);
    } else if (node->type == token_div) {
        return eval_expression(node->left) /eval_expression(node->right);
    }
    return 0;
}

