#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "listeDouble.h"
#include "tri.h"

int main()
{
    T_liste l;
    printf("Zone de test de vos fonctions!\n");
    printf("1 fonction = 1 test immediat!\n");

    //tests
    initListe(&l);
    create_random_list(l, 100);
    afficheListeV1(l);

    return 0;
}
