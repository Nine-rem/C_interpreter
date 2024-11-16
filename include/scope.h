#ifndef SCOPE_H
#define SCOPE_H

#include "symbol_table.h"

// Structure pour gérer les variables globales et locales
typedef struct {
    Symbol global[100];   // Table des variables globales
    Symbol local[100];    // Table des variables locales
    int global_count;     // Nombre de variables globales
    int local_count;      // Nombre de variables locales
    int use_local;        // 1 = locale / 0 = globale
} Scope;

// Prototypes des fonctions
void init_scope(Scope* s);                         // Initialise le contexte de scope
void set_variable(Scope* s, char var_name, int value); // met a jour une variable
int get_variable(Scope* s, char var_name);         // Récupère la valeur d'une variable

#endif 
