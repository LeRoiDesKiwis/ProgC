#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "entrepot.h"
#include "types.h"
#include "piles.h"

//
//OBJECTIF; ici, on utilise les routines de la SD choisie (ici piles.h) pour écrire le code des fonctions de cette librairie
//

//---------------------------------------------------------------------------------------------------------------------
stock creerStockVide(){
    stock s = creerPileVide();  // le type stock (equivalent au type pile) est un pointeur sur cellule
    return s;
}
//---------------------------------------------------------------------------------------------------------------------
carton creerCarton(int *id_max){
    carton c;
    c.id_carton= ++(*id_max);  // pré-incrémentation de la valeur pointée, puis affectation
    c.nb_places_libres = 10;
    return c;
}
//---------------------------------------------------------------------------------------------------------------------
// retourne le nb de boites qui n'ont pu etre rangées parmi les "nb_boites" à ranger
int remplirCarton( carton *c, int nb_boites){
    c->nb_places_libres=c->nb_places_libres - nb_boites;
    if (c->nb_places_libres <0){
            int places_manquantes = c->nb_places_libres * -1;
            c->nb_places_libres = 0;
            return places_manquantes;
    }
    else
        return 0;
}
//---------------------------------------------------------------------------------------------------------------------
// IMPORTANT: ici on utilise les routines de piles.h, puisque "stock" est une "pile"  (pour rappel pile est un pointeur sur cellule)
stock ajouterCarton( stock s, carton c){
s = empiler(s, c);
return s;
}
//---------------------------------------------------------------------------------------------------------------------
// ici on va devoir trouver notre carton dans notre "stock", avant de le supprimer, sachant que c'est stocké dans une pile
stock  supprimerCarton( stock s, int id_carton){
 bool carton_trouve = false;  //va permettre de ne pas dépiler la fin de la pile qd on aura trouvé le carton à supprimer
 pile pileA;
 pileA = creerPileVide();

 while (!estVide(s) && (!carton_trouve)) {  // ce n'est pas vide ET on n'a pas encore trouvé
    if (tetePile(s).id_carton==id_carton){
        s=depiler(s);  // on ne garde pas le carton en question
    } else {
        pileA = empiler(pileA, tetePile(s));  //on sauvegarde le carton lambda
        s=depiler(s);
    }
 }

 // on remet les boites enlevés
 while (!estVide(pileA)){
    s = empiler(s, tetePile(pileA));
    pileA=depiler(pileA);
 }
return s;
}
//---------------------------------------------------------------------------------------------------------------------

// remarque: ci-dessous on va dépiler notre pile pour répondre à une question. Pensez à la sauvegarder et à la restaurer

//retourne l'id du carton le moins rempli
//on passe l'adresse de la SD car on déconstruit  (free) et reconstruit (malloc) la SD lors du parcours, donc le pointeur de tête peut être different
int trouveCartonleMoinsRempli( stock *s ){
 int plus_bas = tetePile(*s).nb_places_libres;  // permet de ne pas mettre une valeur plus basse que la plus basse rééllement présente ds la pile
 int id_du_plus_vide=tetePile(*s).id_carton;
 pile pileA = creerPileVide();

 // on passe en revue tous les cartons et on memorise celui qui est le plus bas
 while (!estVide(*s)) {
    if (tetePile(*s).nb_places_libres > plus_bas){
        plus_bas = tetePile(*s).nb_places_libres;
        id_du_plus_vide = tetePile(*s).id_carton;
    }
    pileA = empiler(pileA, tetePile(*s));  // sauveragede de la pile
    *s=depiler(*s);
 }

  while (!estVide(pileA)){
    *s = empiler(*s, tetePile(pileA));    //restauration de la pile,
    pileA=depiler(pileA);
 }
 //ATTENTION, bien voir que *s a potentiellement changé
 return id_du_plus_vide;
}
//---------------------------------------------------------------------------------------------------------------------
stock afficheStock( stock s ){
 pile pileA;
 pileA = creerPileVide();

 //on depile, on affiche à la volée et on remplie dans une copie
 while (estVide(s)!=true) {
     afficheCarton(tetePile(s));
     pileA = empiler(pileA, tetePile(s));
     s=depiler(s);
 }
 // on remet la pile à l'endroit
 while (!estVide(pileA)){
    s = empiler(s, tetePile(pileA));
    pileA=depiler(pileA);
 }
 return s;  //l'adresse s n'est pas forcément la même qu'en entrée de fct, car on on a déplier (free) et re-empiler (malloc)
}
//---------------------------------------------------------------------------------------------------------------------
int nbCartonsPresents( stock s ){
    return hauteurPile( s );
}
//---------------------------------------------------------------------------------------------------------------------
// A FAIRE
/*
stock repatirNbBoitesDansTousLesCartons( stock s, int nb_boites_total_a_dispatcher){

}
//---------------------------------------------------------------------------------------------------------------------
int nbBoitesTotalEnStock( stock *s ){

}
*/
