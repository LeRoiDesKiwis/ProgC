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
 * 
 */
void fils1()
{
    srandom(getpid());

    printf("fils 1 : je commence partie 1\n");
    sleep(1 + random() % 3);
    printf("fils 1 : je termine partie 1\n");

    // Rendez-Vous
    // TODO synchroniser les deux fils
    
    printf("fils 1 : je commence partie 2\n");
    sleep(1 + random() % 3);
    printf("fils 1 : je termine partie 2\n");

    // pour ne pas revenir dans le main
    exit(EXIT_SUCCESS);
}

/*
 * 
 */
void fils2()
{
    srandom(getpid());

    printf("    fils 2 : je commence partie 1\n");
    sleep(1 + random() % 3);
    printf("    fils 2 : je termine partie 1\n");

    // Rendez-Vous
    // TODO synchroniser les deux fils
    
    printf("    fils 2 : je commence partie 2\n");
    sleep(1 + random() % 3);
    printf("    fils 2 : je termine partie 2\n");

    // pour ne pas revenir dans le main
    exit(EXIT_SUCCESS);
}

int main()
{
    printf("\n");
    printf("/------------------------------------\n");
    printf("| exercice 03\n");
    printf("\\------------------------------------\n");

    // à surtout créer avant le fork,
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
    // TODO destruction mutex/semaphore
 
    return EXIT_SUCCESS;
}
