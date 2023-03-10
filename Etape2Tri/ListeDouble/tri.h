#ifndef TRI_H_INCLUDED
#define TRI_H_INCLUDED

#include "listeDouble.h"

void tri_selection(int *tableau, int taille);
void create_random_list(T_liste l, int n);
int *list_to_tab(T_liste l, int size);
int *list_to_tab_free(T_liste *l, int size);
T_liste tab_to_liste(T_liste l, int *tab, int size);
T_liste tri_liste(T_liste *l, int size);
T_liste tri_selection_liste(T_liste l, bool (*fcomp) (T_personne a, T_personne b));

#endif // TRI_H_INCLUDED
