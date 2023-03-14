#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "Semaphore.h"

// variable globale pour alléger le code
// déclarer les sémaphores/mutex ici
// TODO déclarer les sémaphores/mutex ici

/*
 * le fils 1 doit s'exécuter avant le fils 2
 */
void fils1()
{
    printf("fils 1 : je commence\n");
    sleep(2);
    printf("fils 1 : je termine, le fils 2 ne devrait démarrer que maintenant\n");

    // autoriser fils 2 à démarrer
    // TODO

    // pour ne pas revenir dans le main
    exit(EXIT_SUCCESS);
}

/*
 * le fils 2 doit s'exécuter après le fils 1
 */
void fils2()
{
    // attendre la fin du fils 1
    // TODO
    
    printf("fils 2 : je commence, le fils 1 devrait avoir terminé\n");
    sleep(1);
    printf("fils 2 : je termine\n");

    // pour ne pas revenir dans le main
    exit(EXIT_SUCCESS);
}

int main()
{
    printf("\n");
    printf("/------------------------------------\n");
    printf("| exercice 2b\n");
    printf("\\------------------------------------\n");

    // à surtout créer avant le fork, sinon il y a deux sémaphores indépendants
    // TODO creation mutex/semaphore

    if (fork() == 0)
        fils1();          // rappel on ne sort pas de la fonction
    if (fork() == 0)
        fils2();          // rappel on ne sort pas de la fonction

    // ne pas oublier (rappel uniquement le père exécute ce code)
    wait(NULL);
    wait(NULL);

    // ne pas oublier non plus
    // à faire absolument après le wait, sinon on risque de le
    // détruire alors que le fils s'en sert encore
    // TODO destruction mutex
 
    return EXIT_SUCCESS;
}
