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
// TODO déclarer les sémaphores/mutex ici
Semaphore mutex;

void code_SC_1(int fd, const char *s)
{
  for (int i = 0; i < TAILLE; i++){
    fic_ecrire_chaine(fd, s);
  }
}

/*
 *
 */
void fils1(int fd)
{
    srandom(getpid());

    sleep(1 + random() % 3);

    // TODO : appeler le code critique ici
    // manipulez les sémaphores en dehors de la fonction code_SC_1
    mutex_prendre(mutex);
    code_SC_1(fd, "aaaaa\n");
    mutex_vendre(mutex);
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

    sleep(1 + random() % 3);

    // TODO : appeler le code critique ici
    // manipulez les sémaphores en dehors de la fonction code_SC_1
    mutex_prendre(mutex);
    code_SC_1(fd, "ZZZZZ\n");
    mutex_vendre(mutex);

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
    // TODO creation mutex/semaphore

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
    // TODO destruction mutex/semaphore
    sema_detruire(&mutex);

    return EXIT_SUCCESS;
}
