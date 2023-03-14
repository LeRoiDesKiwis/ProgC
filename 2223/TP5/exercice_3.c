#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#include "assert.h"
#include "fichier.h"
#include "Semaphore.h"

#define FILENAME "bacasable.bin"



// =============================================================
// Début gestion de la file d'attente
// =============================================================

// taille de la file d'attente
#define TAILLE 5

// fonction qui supprime le premier entier d'un fichier
// et décale les autres d'un cran vers le début
// attention : pendant cette opération, le fichier ne doit être
// ouvert et manipulé par personne
void retasse()
{
    void *buffer = NULL;
    int fd = fic_ouvrir_lecture(FILENAME);
    int longueur = lseek(fd, 0, SEEK_END) - sizeof(int);

    // lecture des données sauf le premier entier
    if (longueur > 0)
    {
        buffer = malloc(longueur);
        lseek(fd, sizeof(int), SEEK_SET);
        read(fd, buffer, longueur);
    }
    fic_fermer(fd);

    // réinitialisation du fichier
    fic_detruire(FILENAME);
    fic_creer_vide(FILENAME);

    // réécriture des données à conserver
    fd = fic_ouvrir_ecriture(FILENAME);
    if (longueur > 0)
    {
        write(fd, buffer, longueur);
        free(buffer);
    }
    fic_fermer(fd);
}

// déclaration ici de tous les sémaphores/mutex nécessaires
// ils ne doivent être utilisés que dans les deux fonctions du
// producteur-consommateur

// ========== TODO ============

// initialisation des sémaphores
void init_sema()
{
    // ========== TODO ============
}

// et leurs destructions
void detruire_sema()
{
    // ========== TODO ============
}

// écriture dans le fichier, en fin, d'un entier
void deposer_information(int v)
{
    // ========== TODO ============
}

// on lit dans le fichier, toujours en début
// une fois que c'est lu, on retasse toutes les valeurs restantantes vers
// le début
int prendre_information()
{
    // ========== TODO ============
}
// =============================================================
// Fin gestion de la file d'attente
// =============================================================


// consommateur :
// lit des entiers dans la file et s'arrête dès qu'il lit un -1
void consommateur(int num)
{
    srandom(getpid());
    int somme = 0;
    int v;

    while (true)
    {
        sleep(random() % 3 + 1);

        // TODO : récupérer une valeur à stocker dans v
        //        sortir si c'est -1

        printf("    consommateur %d a pris : %d\n", num, v);
    }

    printf("    consommateur %d : somme %d\n", num, somme);

    exit(0);
}

// producteur
// écrit un certain nombre (fixé à l'avance) d'entiers aléatoires
void producteur(int num)
{
    int NB_ECRIT = 4;
    
    srandom(getpid());

    for (int i = 0; i < NB_ECRIT; i++)
    {
        sleep(random() % 2 + 1);
        int v = random() % 100 + 1;
        // TODO : déposer la valeur v dans la file

        printf("producteur %d a depose : %d\n", num, v);
    }

    exit(0);
}

// lancement des producteurs et consommateurs
void genere()
{
    int NB_CONSO = 2;
    int NB_PROD = 3;

    // TODO : lancer avec fork les consommateurs et producteurs

    // attente de la fin de tous les producteurs
    // pourquoi est-on sûr que l'on ne détecte pas la fin d'un consommateur ?
    for (int i = 1; i <= NB_PROD; i++)
        wait(NULL);

    // pour arrêter les consommateurs
    for (int i = 1; i <= NB_CONSO; i++)
        deposer_information(-1);

    for (int i = 1; i <= NB_CONSO; i++)
        wait(NULL);
}

int main()
{
    fic_creer_vide(FILENAME);

    init_sema();
    genere();
    detruire_sema();

    return EXIT_SUCCESS;
}
