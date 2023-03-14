#include <stdlib.h>
#include <stdio.h>

#include "Semaphore.h"

/*
 * un mutex est automatiquement initialisé à 1 lors de la création
 * pour l'initialiser à 0, il faut faire un "prendre" après la création
 */

int main()
{
    printf("\n");
    printf("/------------------------------------\n");
    printf("| exercice 1b\n");
    printf("\\------------------------------------\n");

    // TODO : création, utilisation d'un semaphore-mutex
    Semaphore mutex;
    mutex = mutex_creer();
    mutex_prendre(mutex);
    mutex_vendre(mutex);
    mutex_vendre(mutex);
    sema_detruire(&mutex);

    return EXIT_SUCCESS;
}
