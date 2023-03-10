#ifndef PILES_H_INCLUDED
#define PILES_H_INCLUDED

#include <stdbool.h>
#include "types.h"

// On va gérer ici une pile de cartons de chaussures, défini dans types.h

typedef struct cellule {
    carton elem;            //prochaine etape: un type void*
    struct cellule *suiv;
} *pile;

pile creerPileVide();
int estVide(pile p);
pile empiler(pile p, carton c);
pile depiler(pile p);
int hauteurPile(pile p);
carton tetePile(pile p);
carton* tetepileADR(pile p);


#endif // PILES_H_INCLUDED
