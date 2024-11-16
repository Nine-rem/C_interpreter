#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char var_name;
    int value;
} Symbol;

Symbol symbol_table[100];
int symbol_count = 0;

void set_variable_value(char var_name, int value) {
    for (int i = 0; i < symbol_count; i++) {
        if (symbol_table[i].var_name == var_name) {
            symbol_table[i].value = value;
            return;
        }
    }
    symbol_table[symbol_count].var_name = var_name;
    symbol_table[symbol_count].value = value;
    symbol_count++;
}

int get_variable_value(char var_name) {
    for (int i = 0; i < symbol_count; i++) {
        if (symbol_table[i].var_name == var_name) {
            return symbol_table[i].value;
        }
    }
    printf("Erreur: variable '%c' non définie\n", var_name);
    exit(EXIT_FAILURE);
}
