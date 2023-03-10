#include <stdlib.h>
#include <stdio.h>
#include "types.h"

void afficheCarton(carton c){
    printf("\nId = %d, nb places libres = %d", c.id_carton, c.nb_places_libres);
};
