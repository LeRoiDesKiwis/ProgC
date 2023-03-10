#ifndef ENTREPOT_H_INCLUDED
#define ENTREPOT_H_INCLUDED

#include "types.h"   //défini le type carton
#include "piles.h"

typedef pile stock;  //On va gérer notre stock via des PILES --ie des pointeurs sur cellule

stock creerStockVide();
carton creerCarton(int *id_max);
int remplirCarton( carton *c, int nb_boites);
stock ajouterCarton( stock s, carton c);  //Attention, on travaille bien sur le type stock et non pas pile, en vue de modifier la SD plus tard
stock supprimerCarton( stock s, int id_carton);
int trouveCartonleMoinsRempli( stock *s );   //adresse de la SD car on déconstruit  (free) et reconstruit (malloc) la SD, donc le pointeur de tête peut être different
stock afficheStock( stock s );
int nbCartonsPresents( stock s );

// A FAIRE

/*
//repartir (ranger) nbBoites boites dans les N premieres places vides (disponibles)
stock repatirNbBoitesDansTousLesCartons( stock s, int nb_boites_total_a_dispatcher);

int  nbBoitesTotalEnStock( stock *s );  //adresse de la SD car on déconstruit  (free) et reconstruit (malloc) la SD, donc le pointeur de tête peut être different
*/

#endif // ENTREPOT_H_INCLUDED
