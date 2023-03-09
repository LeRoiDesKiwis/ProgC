#ifndef TRI_H_INCLUDED
#define TRI_H_INCLUDED

#include "listeDouble.h"

void tri_selection(int *tableau, int taille);
void create_random_list(T_liste l, int n);
int *list_to_tab(T_liste l, int size);
int *list_to_tab_free(T_liste *l, int size);

#endif // TRI_H_INCLUDED
