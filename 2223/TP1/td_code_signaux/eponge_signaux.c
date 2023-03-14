#define _POSIX_C_SOURCE 1
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>



/*
 * Fonction (handler) appelée lorsqu'un signal est reçu
 */
void myhandler(int num)
{
    printf("Signal %d recu\n", num);
}

/*
 * On branche une fonction (un handler) sur un maximum de signaux
 * attention : tous les signaux ne sont pas "attrapables (SIGSTOP et SIGKILL)
 */
void branchement()
{
    struct sigaction action;

    action.sa_handler = myhandler;
    sigfillset(&action.sa_mask);
    action.sa_flags = 0;
    action.sa_restorer = NULL;

    for (int num = 1; num <= 31; num++)
    {
        int ret = sigaction(num, &action, NULL);
        if (ret != 0)
            printf("Erreur lors du branchement du signal %d\n", num);
    }
}

/*
 * boucle infinie pour attendre les signaux
 */
void attente()
{
    while (1)
    {
        pause();
    }
}

/*
 *
 */
int main()
{
    printf("Je suis une eponge à signaux !\n");
    printf("Mon pid est : %d\n", getpid());
    printf("Envoyez-moi des signaux. Par exemple, a partir du shell :\n");
    printf("   kill -15 %d\n", getpid());
    printf("ou equivalent (et plus clair) :\n");
    printf("   kill -TERM %d\n", getpid());
    printf("\n");

    branchement();
    attente();

    printf("fin\n");

    return EXIT_SUCCESS;
}
