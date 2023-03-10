#include <stdio.h>
#include <stdlib.h>

#include "tri.h"
#include "listeDouble.h"

void tri_selection(int *tableau, int taille){
    int en_cours, plus_petit, j, temp;
    for (en_cours = 0; en_cours < taille - 1; en_cours++){
        plus_petit = en_cours;
        for (j = en_cours; j < taille; j++)
            if (tableau[j] < tableau[plus_petit])
                plus_petit = j;
        temp = tableau[en_cours];
        tableau[en_cours] = tableau[plus_petit];
        tableau[plus_petit] = temp;
    }
}

void create_random_list(T_liste l, int n){
    for(int i = 0; i < n; i++){
        int random_number = rand()%100;
        ajoutEnFin(l, random_number);
    }
}

int *list_to_tab(T_liste l, int size){
    int *tab = (int*)malloc(size*(sizeof(int)));
    T_liste courant = l;
    for(int i = 0; i < size; i++){
        if(courant == NULL) break;
        tab[i] = *(courant->pdata);
        courant = courant->suiv;
    }
    return tab;
}

int *list_to_tab_free(T_liste *l, int size){
    int *tab = (int*)malloc(size*(sizeof(int)));
    T_liste courant = *l;
    for(int i = 0; i < size; i++){
        if(courant == NULL) break;
        tab[i] = *(courant->pdata);
        T_liste next = getptrNextCell(courant);
        free(courant);
        courant = next;
    }

    *l = NULL;
    return tab;
}

T_liste tab_to_liste(T_liste l, int *tab, int size){
    for(int i = 0; i < size; i++){
        l = ajoutEnFin(l, tab[i]);
    }

    return l;

}

T_liste tri_liste(T_liste *l, int size){

    int *tab = list_to_tab_free(l, size);
    tri_selection(tab, size);
    initListe(l);
    tab_to_liste(*l, tab, size);
    return *l;
}

T_liste tri_selection_liste(T_liste l){
    T_liste courant, j, plus_petit;
    for (courant = l; courant != NULL; courant = getptrNextCell(courant)){
        plus_petit = courant;
        for (j = courant; j != NULL; j = getptrNextCell(j))
            if (*(j->pdata) < *(plus_petit->pdata))
                plus_petit = j;
        swapPtrData(courant, plus_petit);
    }
    return l;
}
