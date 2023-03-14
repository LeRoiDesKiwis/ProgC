/*************************************************************************
 * Module de gestion des sémaphores
 *     (utilisation simplifiée par rapport aux possibilités réelles)
 *
 * note : un mutex est un sémaphore qui ne peut prendre que les valeurs 0 et 1
 *
 * Les fonctions classiques :
 *    - sema_creer
 *    - mutex_creer
 *    - sema_detruire
 *    - sema_prendre 
 *    - mutex_prendre
 *    - sema_vendre 
 *    - mutex_vendre
 *    - sema_attendre
 **************************************************************************/

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <stdlib.h>
#include <stdbool.h>


/*
 * A priori, seul le type Semaphore est à utiliser dans votre code
 */
struct SemaphoreP;
typedef struct SemaphoreP *Semaphore;
typedef const struct SemaphoreP *const_Semaphore;


/****
 * constructeurs et destructeur
 * surtout ne pas oublier de détruire le sémaphore pour ne pas
 * saturer le système
 ****/
// création sémaphore classique
Semaphore sema_creer(int val);
// création en mode mutex (par exemple vendre deux fois d'affilée est une erreur)
Semaphore mutex_creer();
// destructeur (attention au prototype) en supprimant le sémaphore du système
// fonction à appeler également pour les détruire les sémaphores de type mutex
void sema_detruire(Semaphore *self);


/****
 * opérations basiques
 ****/
// tentative de faire -1 sur le sémaphore (qui ne doit pas être un mutex) en mode bloquant
void sema_prendre(Semaphore self);
// équivalent pour les mutex
void mutex_prendre(Semaphore self);

// +1 sur le sémaphore (qui ne doit pas être un mutex)
void sema_vendre(Semaphore self);
// équivalent pour les mutex
void mutex_vendre(Semaphore self);

// attendre que le sémaphore (qui ne doit pas être un mutex) passe à 0
void sema_attendre(Semaphore self);





/****
 * accesseurs (ne pas utiliser dans un vrai programme)
 ****/
int sema_getVal(const_Semaphore self);
void sema_setVal(Semaphore self, int val);


#endif
