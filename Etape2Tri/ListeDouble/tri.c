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
