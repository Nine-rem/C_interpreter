#include <stdio.h>
#include <stdlib.h>

#include "symbol_table.h"

// Définition de la structure Scope
typedef struct {
    Symbol global[100];     // Tableau des variables globales
    Symbol local[100];      // Tableau des variables locales
    int global_count;       // Nombre de variables globales
    int local_count;        // Nombre de variables locales
    int use_local;          // Indicateur pour la portée locale
} Scope;

// Initialise la structure Scope
void init_scope(Scope* s) {
    s->global_count = 0;
    s->local_count = 0;
    s->use_local = 0; // Par défaut, utilise la portée globale
}

// Définit ou met à jour une variable dans le scope approprié
void set_variable(Scope* s, char var_name, int value) {
    Symbol* table;
    int* count;

    // Sélectionne la table et le compteur en fonction de la portée active
    if (s->use_local) {
        table = s->local;
        count = &s->local_count;
    } else {
        table = s->global;
        count = &s->global_count;
    }

    // Vérifie si la variable existe déjà et met à jour sa valeur
    for (int i = 0; i < *count; i++) {
        if (table[i].var_name == var_name) {
            table[i].value = value;
            return;
        }
    }

    // Ajoute une nouvelle variable si elle n'existe pas
    table[*count].var_name = var_name;
    table[*count].value = value;
    (*count)++;
}

// Récupère la valeur d'une variable en fonction de la portée
int get_variable(Scope* s, char var_name) {
    Symbol* table;
    int count;

    // Vérifie d'abord dans la portée locale si elle est activée
    if (s->use_local) {
        table = s->local;
        count = s->local_count;
        for (int i = 0; i < count; i++) {
            if (table[i].var_name == var_name) {
                return table[i].value;
            }
        }
    }

    // Vérifie ensuite dans la portée globale
    table = s->global;
    count = s->global_count;
    for (int i = 0; i < count; i++) {
        if (table[i].var_name == var_name) {
            return table[i].value;
        }
    }

    // Si la variable n'existe pas dans les deux portées, affiche une erreur
    printf("Erreur: variable '%c' non définie\n", var_name);
    exit(EXIT_FAILURE);
}
