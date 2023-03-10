#include <stdlib.h>
#include <stdio.h>
#include "piles.h"

pile creerPileVide(){
    return NULL;
}

int estVide(pile p){
    if (p == NULL)
        return 1;
    else
        return 0;
}

pile empiler(pile p, carton c){
    pile new_elem = (pile)malloc(sizeof(struct cellule));
    new_elem->elem = c;
    new_elem->suiv = p;
    return new_elem;      //la Pile pointe sur la t�te de la pile
}

pile depiler(pile p){
pile p2 = p;
    if (p!=NULL){
        p2 = p->suiv;     // nouvelle t�te
        free(p);          // liberation de la m�moire sur l'ancienne t�te
    }
return p2;
}

int hauteurPile(pile p){
    if (p == NULL)
        return 0;
    else return 1 + hauteurPile(p->suiv);
}

carton tetePile(pile p){
    if (p!=NULL)
        return p->elem;
    else{
        printf("\nPile vide: erreur dans tetepile\n");
        exit(EXIT_FAILURE);
    }
}

carton* tetepileADR(pile p){
    if (p!=NULL)
        return &(p->elem);
    else{
        printf("\nPile vide: erreur dans tetepileADR\n");
        exit(EXIT_FAILURE);
    }
}
