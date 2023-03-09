#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "tri.h"
#include "listeDouble.h"

int main()
{
    T_liste l;
    srand(time(NULL));
    initListe(l);
    printf("Zone de test de vos fonctions!\n");
    printf("1 fonction = 1 test immediat!\n");
    create_random_list(l, 100);
    afficheListeV0(l);

    return 0;
}
