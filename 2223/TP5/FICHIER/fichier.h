#ifndef FICHIER_H
#define FICHIER_H

// permet de créer un fichier vide mais sans le laisser ouvert
void fic_creer_vide(const char *nom);
// effacer un fichier du disque (attention !)
void fic_detruire(const char *nom);

// ouverture en lecture ou en écriture, ou les deux
// return : le file descriptor
int fic_ouvrir_lecture(const char *nom);
int fic_ouvrir_ecriture(const char *nom);
int fic_ouvrir_lecture_ecriture(const char *nom);

// toujour fermer un fichier non utilisé
void fic_fermer(int fd);

// quelques fonctions d'écriture
void fic_ecrire_char(int fd, char c);
void fic_ecrire_chaine(int fd, const char *s);
void fic_ecrire_int(int fd, int v);   // en mode binaire

// et de lecture
// return : nbr d'octets manquants pour une lecture complète
//          i.e. 0 signifie que tout est ok
int fic_lire_char(int fd, char *c);
int fic_lire_chaine(int fd, char *s, int taille);
int fic_lire_int(int fd, int *v);  // en mode binaire

// pour se positionner dans le fichier
void fic_aller_debut(int fd);
void fic_aller_fin(int fd);

#endif
