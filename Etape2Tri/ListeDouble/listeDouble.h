#ifndef LISTEDOUBLE_H_INCLUDED
#define LISTEDOUBLE_H_INCLUDED

#include <stdbool.h>
#include <types.h>

typedef struct T_cell{
    struct T_cell *suiv;
    struct T_cell *prec;
    T_personne *pdata;              //attention à faire un malloc sur ce champ avant de s'en servir
} T_cellule;
typedef T_cellule *T_liste;

void initListe(T_liste *l);
bool listeVide( T_liste l);




void afficheListeV1( T_liste l);
//Pour "AfficheListeV1" Vous avez le droit de lire directement dans la structure de données
//Utile pour afficher et debuguer les fonctions ci-dessous

T_liste ajoutEnTete(T_liste l, T_personne mydata); //Bien mettre à NULL les champs suiv et prec non utilisés s'il y en a
T_liste ajoutEnFin(T_liste l, T_personne mydata);
T_liste ajoutEnN(T_liste l, int pos, T_personne mydata);

T_liste suppEnTete(T_liste l);
T_liste suppEnFin(T_liste l);
T_liste suppEnN(T_liste l, int pos);

T_liste getptrFirstCell(T_liste l);
T_liste getptrLastCell(T_liste l);
T_liste getptrNextCell(T_liste l);
T_liste getptrPrevCell(T_liste l);

T_personne* getPtrData(T_liste l, T_personne mydata);
void swapPtrData( T_liste source, T_liste destination );

int getNbreCell(T_liste l);
int getSizeBytes(T_liste l); //utilisation de sizeof

T_liste creatNewListeFromFusion(T_liste l1, T_liste l2); //on souhaite CREER une nouvelle liste sans modifier l1 et l2
T_liste addBehind(T_liste debut, T_liste suite);

T_liste findCell(T_liste l, T_personne data);
//int getOccurences(T_liste l, T_personne data);  //nbre de fois que data est présent dans toute la liste l1

void afficheListeV2( T_liste l);
//Pour "AfficheListeV2", vous devez utiliser uniquement les fonctions écrites ci-dessus (interdiction de passer directement par les champs ptr de la SD)
/* fin de tag ligne 50
début de tag ligne 16 */
T_liste creerListeNElem(T_liste l, int n);
int getOccurences(T_liste l, T_personne data, bool (*fcomp) (T_personne a, T_personne b));

#endif // LISTEDOUBLE_H_INCLUDED

