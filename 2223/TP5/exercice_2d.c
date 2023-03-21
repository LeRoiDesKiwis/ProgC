#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "Semaphore.h"

// variable globale pour alléger le code
// déclarer les sémaphores/mutex ici
// TODO déclarer les sémaphores/mutex ici

Semaphore mut1;
Semaphore mut2;

/*
 *
 */
void fils1()
{
    srandom(getpid());

    printf("fils 1 : je commence partie 1\n");
    sleep(1 + random() % 3);
    printf("fils 1 : je termine partie 1\n");

    mutex_vendre(mut2);
    // TODO synchroniser les deux fils
    mutex_prendre(mut1);

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

    mutex_vendre(mut1);
    // Rendez-Vous
    // TODO synchroniser les deux fils
    mutex_prendre(mut2);

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
    printf("| exercice 2d\n");
    printf("\\------------------------------------\n");

    // à surtout créer avant le fork,
    // TODO creation mutex/semaphore
    mut1 = mutex_creer();
    mut2 = mutex_creer();

    mutex_prendre(mut1);
    mutex_prendre(mut2);

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
    sema_detruire(&mut1);
    sema_detruire(&mut2);

    return EXIT_SUCCESS;
}
