#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "fichier.h"
#include "Semaphore.h"

#define FILENAME "bacasable.txt"
#define TAILLE 1000


// variable globale pour alléger le code
// déclarer les sémaphores/mutex ici
// TODO déclaration semaphotes/mutex
Semaphore mutex;

// il est bien plus élégant de gérer le mutex ici plutôt
// qu'en dehors de l'appel : ainsi on est sûr de ne pas l'oublier.
void code_SC_1(int fd, const char *s)
{
    // pour faire un peu d'aléatoire
    usleep(random()%500);

    mutex_prendre(mutex);
    // code en section critique
    fic_ecrire_chaine(fd, s);
    mutex_vendre(mutex);
}

/*
 *
 */
void fils1(int fd)
{
    srandom(getpid());

    // TODO : appeler le code critique ici
    // manipulez les sémaphores dans la fonction code_SC_1
    // donc la boucle ne doit pas être englobée dans la SC
    for (int i = 0; i < TAILLE; i++)
        code_SC_1(fd, "aaaaa\n");

    // chaque fils doit fermer le fichier
    fic_fermer(fd);

    // pour ne pas revenir dans le main
    exit(EXIT_SUCCESS);
}

/*
 *
 */
void fils2(int fd)
{
    srandom(getpid());

    for (int i = 0; i < TAILLE; i++)
        code_SC_1(fd, "ZZZZZ\n");

    // chaque fils doit fermer le fichier
    fic_fermer(fd);

    // pour ne pas revenir dans le main
    exit(EXIT_SUCCESS);
}

int main()
{
    printf("\n");
    printf("/------------------------------------\n");
    printf("| exercice 1c\n");
    printf("\\------------------------------------\n");

    // juste pour créer le fichier et s'assurer qu'il est vide
    fic_creer_vide(FILENAME);
    int fd = fic_ouvrir_ecriture(FILENAME);

    // à surtout créer avant le fork,
    // plutôt un mutex car seules les valeurs 0 et 1 doivent être prises
    // TODO création mutex/semphote
    mutex = mutex_creer();
    if (fork() == 0)
        fils1(fd);          // rappel on ne sort pas de la fonction
    if (fork() == 0)
        fils2(fd);          // rappel on ne sort pas de la fonction

    // ne pas oublier (rappel uniquement le père exécute ce code)
    wait(NULL);
    wait(NULL);

    // ne pas oublier non plus
    // à faire absolument après le wait, sinon on risque de le
    // détruire alors que le fils s'en sert encore
    // TODO destruction mutex/semphote
    sema_detruire(&mutex);
    return EXIT_SUCCESS;
}
