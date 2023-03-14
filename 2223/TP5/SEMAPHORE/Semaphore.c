#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

#include "myassert.h"

#include "Semaphore.h"

struct SemaphoreP
{
    bool mode_mutex;
    int nbSem;
    int semId;
    key_t key;
};

/*
 * constructeurs, destructeur
 * val == -1 si c'est ce n'est pas une création
 */
static Semaphore sema_semget(key_t cle, int flags, int val)
{
    myassert(((flags & IPC_CREAT) == 0) || (val >= 0), "Création : la valeur initiale doit être >= 0");
    myassert(((flags & IPC_CREAT) != 0) || (val == -1), "Pour une récupération, val doit être à -1");

    Semaphore self = malloc(sizeof(struct SemaphoreP));
    myassert(self != NULL, "probleme memoire");

    self->mode_mutex = false;
    self->nbSem = 1;
    self->semId = semget(cle,  self->nbSem, flags);
    myassert(self->semId != -1, "creation semaphore");
    self->key = cle;

    if (val != -1)
    {
        int ret = semctl(self->semId, 0, SETVAL, val);
        myassert(ret != -1, "initialisation semaphore");
    }

    return self;
}

Semaphore sema_creer(int val)
{
    // IPC_CREAT n'est pas nécessaire avec IPC_PRIVATE
    // permission ésotérique pour le script de destruction
    return sema_semget(IPC_PRIVATE, IPC_CREAT | IPC_EXCL | 0601, val);
}

Semaphore mutex_creer()
{
    Semaphore self = sema_creer(1);
    self->mode_mutex = true;
    return self;
}

void sema_detruire(Semaphore *self)
{
    myassert(*self != NULL, "Sémaphore déjà détruit ?");

    int ret = semctl((*self)->semId, -1, IPC_RMID);
    myassert(ret != -1, "destruction semaphore");
    free (*self);
    *self = NULL;
}

// NON UTILISEE ICI (cf L3)
void sema_detruireSansSuppression(Semaphore *self)
{
    myassert(*self != NULL, "Sémaphore déjà détruit ?");

    free (*self);
    *self = NULL;
}


/*
 * accesseurs
 */
int sema_getVal(const_Semaphore self)
{
    int ret = semctl(self->semId, 0, GETVAL);
    myassert(ret != -1, "lecture semaphore");
    return ret;
}

void sema_setVal(Semaphore self, int val)
{
    myassert((! self->mode_mutex), "opération interdite pour un mutex");

    int ret = semctl(self->semId, 0, SETVAL, val);
    myassert(ret != -1, "ecriture semaphore");
}


/*
 * opérations basiques
 */
static int sema_operationFlags(Semaphore self, int num, int val, int flags)
{
    myassert(((0 <= num) && (num < self->nbSem)),
             "erreur interne : numero tinadéquat");

    struct sembuf SemB ;
    SemB.sem_num = num;               /* numero du semaphore */
    SemB.sem_op = val;                /* operation selon appel */
    SemB.sem_flg = flags;             /* flags */

    return semop(self->semId, &SemB, 1);   /* une seule opération */
}

static int sema_operation(Semaphore self, int num, int val)
{
    return sema_operationFlags(self, num, val, 0);
}

void sema_prendre(Semaphore self)
{
    myassert((! self->mode_mutex), "prendre interdit pour un mutex (utiliser mutex_prendre)");

    int ret = sema_operation(self, 0, -1);
    myassert(ret != -1, "-1 sur semaphore");
}

void mutex_prendre(Semaphore self)
{
    myassert(self->mode_mutex, "mutex_prendre utilisable uniquement pour un mutex");

    int ret = sema_operation(self, 0, -1);
    myassert(ret != -1, "-1 sur mutex");
}

void sema_vendre(Semaphore self)
{
    myassert((! self->mode_mutex), "vendre interdit pour un mutex (utiliser mutex_vendre)");

    int ret = sema_operation(self, 0, 1);
    myassert(ret != -1, "+1 sur semaphore");
}

void mutex_vendre(Semaphore self)
{
    myassert(self->mode_mutex, "mutex_vendre utilisable uniquement pour un mutex");
    myassert(sema_getVal(self) == 0, "mutex : deux mutex_vendre d'affilée");

    int ret = sema_operation(self, 0, 1);
    myassert(ret != -1, "+1 sur mutex");
}

void sema_attendre(Semaphore self)
{
    myassert((! self->mode_mutex), "attente interdite pour un mutex");

    int ret = sema_operation(self, 0, 0);
    myassert(ret != -1, "attente (i.e. 0) sur semaphore");
}
