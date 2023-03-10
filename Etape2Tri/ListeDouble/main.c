#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "listeDouble.h"
#include "tri.h"

#define SIZE 100

int main()
{
    srand(time(NULL));
    T_liste l;
    printf("Zone de test de vos fonctions!\n");
    printf("1 fonction = 1 test immediat!\n");

    initListe(&l);
    l = creerListeNElem(l, SIZE);
    afficheListeV1(l);
    T_personne* p1 = (T_personne*)malloc(sizeof(T_personne));
    p1->taille = 170;
    l = tri_selection_liste(l, comp_taille_AinfB);
    afficheListeV1(l);
    printf("%d", getOccurences(l, *p1, comp_taille_AegaleB));

    return 0;
}
