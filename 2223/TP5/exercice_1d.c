#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "fichier.h"
#include "Semaphore.h"

#define NB_FILS 10
#define FILENAME "bacasable.txt"
#define TAILLE 1000

// variable globale pour alléger le code
// TODO déclarer les sémaphores/mutex ici

void code_SC_1(int fd)
{
    int v;

    fic_aller_debut(fd);
    fic_lire_int(fd, &v);
    v ++;
    fic_aller_debut(fd);
    fic_ecrire_int(fd, v);
}

/*
 * même code pour tous les fils
 */
void fils()
{
    srandom(getpid());

    int fd = fic_ouvrir_lecture_ecriture(FILENAME);

    // TODO : 
    // manipulez les sémaphores dans la fonction code_SC_1
    // donc la boucle ne doit pas être englobée dans la SC
    for (int i = 0; i < TAILLE; i++)
        code_SC_1(fd);

    // pour ne pas revenir dans le main
    exit(EXIT_SUCCESS);
}


int main()
{
    printf("\n");
    printf("/------------------------------------\n");
    printf("| exercice 1d\n");
    printf("\\------------------------------------\n");

    // juste pour créer le fichier et s'assurer qu'il est vide
    fic_creer_vide(FILENAME);
    // on initialise le contenu du fichier avec le nombre 0
    int fd = fic_ouvrir_ecriture(FILENAME);
    fic_ecrire_int(fd, 0);
    fic_fermer(fd);

    // à surtout créer avant le fork,
    // plutôt un mutex car seules les valeurs 0 et 1 doivent être prises
    // TODO création mutex

    for (int i = 0; i < NB_FILS; i++)
    {
        if (fork() == 0)
            fils(i+1);        // rappel on ne sort pas de la fonction
    }
    
    // ne pas oublier (rappel uniquement le père exécute ce code)
    for (int i = 0; i < NB_FILS; i++)
        wait(NULL);

    // ne pas oublier non plus
    // à faire absolument après le wait, sinon on risque de le
    // détruire alors que le fils s'en sert encore
    // TODO destruction mutex/semaphore
 
    printf("Il y a %d iterations par processus et %d fils\n", TAILLE, NB_FILS);
    printf("le resultat devrait être : %d\n", TAILLE*NB_FILS);

    int res;
    fd = fic_ouvrir_lecture(FILENAME);
    fic_lire_int(fd, &res);
    fic_fermer(fd);
    printf("le resultat est : %d\n", res);

    return EXIT_SUCCESS;
}
