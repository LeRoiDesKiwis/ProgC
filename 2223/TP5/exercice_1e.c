#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "Semaphore.h"

#define N 10
#define K  3 // nombre de processus pouvant être simultanément en SC

// variable globale pour alléger le code
// TODO déclarer les sémaphores/mutex ici


/*
 * même code pour tous les fils
 */
void fils(int numero)
{
    srandom(getpid());

    sleep(1 + random() % 3);

    // Début de la section critique
    printf("fils %d : est entré en section critique\n", numero);
    sleep(3);
    printf("fils %d : va sortir de la section critique\n", numero);
    // fin de la section critique
 
    // pour ne pas revenir dans le main
    exit(EXIT_SUCCESS);
}


int main()
{
    printf("\n");
    printf("/------------------------------------\n");
    printf("| exercice 1e\n");
    printf("\\------------------------------------\n");

    // à surtout créer avant le fork,
    // pas de mutex car la valeur peut être supérieure à 1
    // TODO création sémaphore

    for (int i = 0; i < N; i++)
    {
        if (fork() == 0)
            fils(i+1);        // rappel on ne sort pas de la fonction
    }
    
    // ne pas oublier (rappel uniquement le père exécute ce code)
    for (int i = 0; i < N; i++)
        wait(NULL);

    // ne pas oublier non plus
    // à faire absolument après le wait, sinon on risque de le
    // détruire alors que le fils s'en sert encore
    // TODO destruction mutex/semaphore
 
    return EXIT_SUCCESS;
}
