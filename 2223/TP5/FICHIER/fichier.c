#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include <stdbool.h>

#include "myassert.h"
#include "fichier.h"

/*
 * création d'un fichier
 */
void fic_creer_vide(const char *nom)
{
    int fd = open(nom, O_CREAT|O_RDWR|O_TRUNC, 0644);
    myassert((fd != -1), "creation fichier");
    fic_fermer(fd);
}

/*
 * destruction physique d'un fichier (attention !)
 */
void fic_detruire(const char *nom)
{
    int ret = unlink(nom);
    myassert((ret != -1), "destruction fichier");
}


/*
 * ouvertures de fichiers
 */
int fic_ouvrir_lecture(const char *nom)
{
    int fd = open(nom, O_RDONLY);
    myassert((fd != -1), "ouverture fichier en lecture");
    return fd;
}

int fic_ouvrir_ecriture(const char *nom)
{
    int fd = open(nom, O_WRONLY);
    myassert((fd != -1), "ouverture fichier en ecriture");
    return fd;
}

int fic_ouvrir_lecture_ecriture(const char *nom)
{
    int fd = open(nom, O_RDWR);
    myassert((fd != -1), "ouverture fichier en lecture et ecriture");
    return fd;
}


/*
 * fermeture
 */
void fic_fermer(int fd)
{
    int ret = close(fd);
    myassert((ret != -1), "fermeture fichier");
}


/*
 * écritures
 */
void fic_ecrire_char(int fd, char c)
{
    int ret = write(fd, &c, sizeof(char));
    myassert((ret == sizeof(char)), "écriture d'un char");
}

void fic_ecrire_chaine(int fd, const char *s)
{
    int ret = write(fd, s, strlen(s)*sizeof(char));
    myassert((ret == (int)(strlen(s) * sizeof(char))), "écriture d'une chaîne");
}

void fic_ecrire_int(int fd, int v)   // en mode binaire
{
    int ret = write(fd, &v, sizeof(int));
    myassert((ret == sizeof(int)), "écriture d'un int");
}


/*
 * lectures
 * return : le nombre d'octets non lus
 */
int fic_lire_char(int fd, char *c)
{
    int ret = read(fd, c, sizeof(char));
    myassert((ret != -1), "lecture d'un char");
    return (sizeof(char) - ret);
}

int fic_lire_chaine(int fd, char *s, int taille)
{
    int nbOctets = taille * sizeof(char);
    
    int ret = read(fd, s, nbOctets);
    myassert((ret != -1), "lecture d'une chaine");
    s[taille] = '\0';
    return (nbOctets - ret);
}

int fic_lire_int(int fd, int *v)  // en mode binaire
{
    int ret = read(fd, v, sizeof(int));
    myassert((ret!= -1), "lecture d'un int");
    return (sizeof(int) - ret);
}


/*
 * positionnements
 */
void fic_aller_debut(int fd)
{
    int ret = lseek(fd, 0, SEEK_SET);
    myassert((ret != -1), "positionnement debut");
}

void fic_aller_fin(int fd)
{
    int ret = lseek(fd, 0, SEEK_END);
    myassert((ret != -1), "positionnement fin");
}
