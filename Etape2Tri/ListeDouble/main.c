#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "listeDouble.h"
#include "tri.h"

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
    create_random_list(l, 100);
    int *tab = list_to_tab(l, 100);
    afficheTab(tab, 100);

    return 0;
}
