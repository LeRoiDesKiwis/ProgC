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

    //tests
    initListe(&l);
    l = ajoutEnFin(l, 1);
    create_random_list(l, SIZE+1);
    int *tab = list_to_tab_free(&l, SIZE+1);
    afficheTab(tab, SIZE+1);

    return 0;
}
