#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct {
    char var_name;
    int value;
} Symbol;


void set_variable_value(char var_name, int value);

int get_variable_value(char var_name);


#endif


