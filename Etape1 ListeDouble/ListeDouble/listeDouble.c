#include <stdio.h>
#include <stdlib.h>

#include "listeDouble.h"


//initListe ne fait pas de malloc, juste une initialisation � NULL du pointeur de liste
void initListe(T_liste *l){
*l=NULL;
}


bool listeVide( T_liste l){
    return (l==NULL);
};

void afficheListeV0(T_liste l){
    T_liste courant = l;
    while (courant!=NULL){
        printf("\n%d prec : %p, suiv : %p\n current : %p",*(courant->pdata), courant->prec, courant->suiv, courant);
        courant=courant->suiv;
    }
    printf("\n");
}


void afficheListeV1(T_liste l){
    T_liste courant = l;
    while (courant!=NULL){
        printf(" %d ",*(courant->pdata));
        courant=courant->suiv;
    }
    printf("\n");
}

T_liste ajoutEnTete(T_liste l, int mydata){
    //cr�ation de la cellule � ajouter
    T_liste nouv = (T_liste)malloc(sizeof(struct T_cell));
    //struct T_cell * nouv = (struct T_cell *)malloc(sizeof(struct T_cell))
    //equivalent
    nouv->pdata = (int*)malloc(sizeof(int));
    *(nouv->pdata)=mydata; //on modifie le contenu � l�adresse de notre pointeur
    // fin cr�ation de la nouvelle cellule
    if (l==NULL) // on cr�e en fait la premi�re cellule de la liste
    {
        nouv->suiv = NULL;
        nouv->prec = NULL;
    }
    else // la liste n'�tait pas vide, on doit donc faire les branchements
    {
        nouv->suiv = l; //Fl�che orange sur le sch�ma
        nouv->prec = NULL;
        l->prec = nouv; //Fl�che verte
    }
    return nouv;
}

T_liste ajoutEnFin(T_liste l, int mydata){
    //cr�ation de la cellule � ajouter
    T_liste nouv = (T_liste)malloc(sizeof(struct T_cell));
    //struct T_cell * nouv = (struct T_cell *)malloc(sizeof(struct T_cell))
    //equivalent
    nouv->pdata = (int*)malloc(sizeof(int));
    *(nouv->pdata)=mydata; //on modifie le contenu � l�adresse de notre pointeur
    // fin cr�ation de la nouvelle cellule
    if (l==NULL) // on cr�e en fait la premi�re cellule de la liste
    {
        nouv->suiv = NULL;
        nouv->prec = NULL;
        return nouv;
    }
    else // la liste n'�tait pas vide, on doit donc faire les branchements
    {
        T_liste courant = l;
        while (courant->suiv!=NULL){
            courant=courant->suiv;
        }
        courant->suiv=nouv;
        nouv->suiv = NULL;
        nouv->prec = courant;
    }
    return l;
}

T_liste ajoutEnN(T_liste l, int pos, int mydata){
        //cr�ation de la cellule � ajouter
    T_liste nouv = (T_liste)malloc(sizeof(struct T_cell));
    //struct T_cell * nouv = (struct T_cell *)malloc(sizeof(struct T_cell))
    //equivalent
    nouv->pdata = (int*)malloc(sizeof(int));
    *(nouv->pdata)=mydata; //on modifie le contenu � l�adresse de notre pointeur
    // fin cr�ation de la nouvelle cellule
    if (l==NULL) // on cr�e en fait la premi�re cellule de la liste
    {
        nouv->suiv = NULL;
        nouv->prec = NULL;
        return nouv;
    }
    else // la liste n'�tait pas vide, on doit donc faire les branchements
    {
        T_liste prec = NULL;
        T_liste courant = l;
        int i = 0;
        while (courant !=NULL && i++ < pos){
            prec = courant;
            courant=courant->suiv;
        }
        if(courant == NULL){
            prec->suiv=nouv;
            nouv->suiv = NULL;
            nouv->prec = prec;
        } else {
            nouv->suiv = courant;

            nouv->prec = courant->prec;
            if(courant->prec != NULL) courant->prec->suiv = nouv;
            else l = nouv;
            courant->prec = nouv;
        }
    }
    return l;
}

T_liste suppEnTete(T_liste l){
    l->suiv->prec = NULL;
    T_liste suiv = l->suiv;
    free(l);
    return suiv;
}
T_liste suppEnFin(T_liste l){
    T_liste courant = l;
    while (courant->suiv!=NULL){
        courant=courant->suiv;
    }
    courant->prec->suiv = NULL;
    free(courant);
    return l;
}
T_liste suppEnN(T_liste l, int pos){
    T_liste courant = l;
    int i = 0;
    while (courant->suiv!=NULL && i++ < pos){
        courant=courant->suiv;
    }
    if(courant->prec != NULL) courant->prec->suiv = courant->suiv;
    if(courant->suiv != NULL) courant->suiv->prec = courant->prec;
    T_liste suiv = courant->suiv;
    free(courant);
    if(pos == 0) return suiv;
    else return l;
}

T_liste getptrFirstCell(T_liste l){
    T_liste courant = l;
    while (courant->prec!=NULL){
        courant=courant->prec;
    }
    return courant;
}

T_liste getptrLastCell(T_liste l){
    T_liste courant = l;
    while (courant->suiv!=NULL){
        courant=courant->suiv;
    }
    return courant;
}

T_liste getptrNextCell(T_liste l){
    return l->suiv;
}

T_liste getptrPrevCell(T_liste l){
    return l->prec;
}

int* getPtrData(T_liste l, int mydata){
    return l->pdata;
}

void swapPtrData( T_liste source, T_liste destination ){
    int* a = source->pdata;
    int* b = destination->pdata;
    source->pdata = a;
    source->pdata = b;
}

int getNbreCell(T_liste l){
    T_liste courant = l;
    int i = 0;
    while(courant != NULL){
        i++;
        courant = courant->suiv;
    }
    return i;
}

int getSizeBytes(T_liste l){
    return sizeof(struct T_cell)*getNbreCell(l);
}

T_liste creatNewListeFromFusion(T_liste l1, T_liste l2){
    T_liste l;
    initListe(&l);
    T_liste current1 = l1;
    for(int i = 0; current1 != NULL; i++){
        l = ajoutEnFin(l, *(current1->pdata));
        current1 = current1->suiv;
    }

    T_liste current2 = l2;
    for(int i = 0; current2 != NULL; i++){
        l = ajoutEnFin(l, *(current2->pdata));
        current2 = current2->suiv;
    }
    return l;
}

T_liste addBehind(T_liste debut, T_liste suite){
    getptrLastCell(debut)->suiv = suite;
    suite->prec = debut;
    return debut;
}

T_liste findCell(T_liste l, int data){
    T_liste courant = l;
    while(courant != NULL && data != *(courant->pdata)){
        courant = courant->suiv;
    }
    return courant;
}

int getOccurences(T_liste l, int data){
    int count = 0;
    T_liste courant = l;
    while(courant != NULL){
        if(*(courant->pdata) == data) count++;
        courant = courant->suiv;
    }
    return count;
}
