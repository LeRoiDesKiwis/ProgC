#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "listeDouble.h"

int main()
{
    T_liste l;
    printf("Zone de test de vos fonctions!\n");
    printf("1 fonction = 1 test immediat!\n");

    //tests
    initListe(&l);
    if (listeVide(l)) printf("la liste est vide\n");
    for(int i = 0; i < 20; i++){
        l = ajoutEnTete(l, i);
    }
    for(int i = 0; i < 5; i++){
        l = ajoutEnN(l, 10, 5);
    }
    afficheListeV1(l);
    /*l = suppEnTete(l);
    l = suppEnTete(l);
    afficheListeV1(l);
    l = suppEnFin(l);
    l = suppEnFin(l);
    afficheListeV1(l);
    l = suppEnN(l, 0);
    afficheListeV1(l);*/
    T_liste l2;
    initListe(&l2);
    for(int i = 20; i > 0; i--){
        l2 = ajoutEnTete(l2, i);
    }
    afficheListeV0(l);
    afficheListeV0(creatNewListeFromFusion(l, l2));
    printf("\n---\n");
    afficheListeV1(creatNewListeFromFusion(l, l2));
    //à vous la suite

    return 0;
}
