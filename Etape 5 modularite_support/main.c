// version étudiant

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "types.h"
#include "entrepot.h"
#include "piles.h"


int main()
{
    stock monStock = creerStockVide();

    int nbDonneesStockee = 5000;
    int id_encours = 0;
    int id_carton_a_sup;

    // premiere facon de créer un carton et de le ranger
    carton c1 = creerCarton( &id_encours );
    carton c2 = creerCarton( &id_encours );
    monStock=ajouterCarton(monStock,c1);
    monStock=ajouterCarton(monStock,c2);

    // 2e façon
    for (int i=0; i<10; i++){
        monStock=ajouterCarton(monStock, creerCarton(&id_encours));
    }


    printf("\n\nStock complet (pour demo utlisation routines de entrepot.h):\n");
    printf("Hauteur monStock : %d\n", nbCartonsPresents(monStock) );
    monStock=afficheStock(monStock);


    // Augmentation siginifcative du nombre de données
    clock_t start = clock();  // Démarrage du chrono
    for (int i=0; i<nbDonneesStockee; i++){
        monStock=ajouterCarton(monStock, creerCarton(&id_encours));
    }
    printf("\n Ajout de %d donnees dans la SD du moment", nbDonneesStockee);

    printf("\nHauteur monStock : %d\n", nbCartonsPresents(monStock) );

    // UNE operation - qui coute (en temps et cpu) le parcours de ttes les données

    id_carton_a_sup=trouveCartonleMoinsRempli(&monStock);
    monStock=supprimerCarton(monStock,id_carton_a_sup);
    printf("\n\nSuppresion du carton le moins rempli: carton id numero %d\n", id_carton_a_sup);
    //afficheStock(monStock);

    /*
    A décommenter apres avoir ecrit le code de ces deux fonctions
    monStock=repatirNbBoitesDansTousLesCartons( monStock, 22 );
    printf("\nOn a denombre %d boites\n", nbBoitesTotalEnStock(&monStock));
    */
    clock_t stop = clock();  // arrêt du chrono

    unsigned long millis = (stop -  start) * 1000 / CLOCKS_PER_SEC;
    printf( "Temps chronometre pour la section de code concernee: %ld ms\n", millis );

    return 0;
}
