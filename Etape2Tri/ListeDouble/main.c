#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "listeDouble.h"
#include "tri.h"

#define SIZE 10

void afficheTab(int *tab, int size){
    for(int i = 0; i < size; i++){
        printf("%d, ", tab[i]);
    }
}

int main()
{
    srand(time(NULL));
    T_liste l;
    printf("Zone de test de vos fonctions!\n");
    printf("1 fonction = 1 test immediat!\n");
    time_t now = time(NULL);

    initListe(&l);
    l = ajoutEnFin(l, 1);
    create_random_list(l, SIZE);

    afficheListeV1(l);
    l = tri_selection_liste(l);
    afficheListeV1(l);

    time_t after = time(NULL);
    printf("Traitement effectue en %.2f seconde(s) !", difftime(after, now));

    return 0;
}
