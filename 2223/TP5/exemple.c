#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


#include "Semaphore.h"

/*******************************
 * illustration avec un mutex : c'est un sémaphore à 2 valeurs
 *******************************/
void demo1()
{
  printf("\n");
  printf("/------------------------------------\n");
  printf("| illustration basique d'un mutex\n");
  printf("\\------------------------------------\n");
    
  Semaphore mutex;

  mutex = mutex_creer();
  printf("Valeur initiale  : %d\n", sema_getVal(mutex));

  mutex_prendre(mutex);
  printf("Code en section critique avec exclusion mutuelle\n");
  printf("Valeur apres P : %d\n", sema_getVal(mutex));
  mutex_vendre(mutex);
  printf("Valeur apres V : %d\n", sema_getVal(mutex));


  sema_detruire(&mutex);
}

/*******************************
 * illustration basique 
 *
 * Attention, il s'agit juste ici de montrer le fonctionnement des
 * primitives sur les sémaphores. L'exemple n'a pas spécialement de
 * sens : un seul processus interagit avec les sémaphores et il en
 * vend suffisamment pour ne pas être bloqué quand il en prend...
 *******************************/
void demo2()
{
  printf("\n");
  printf("/------------------------------------\n");
  printf("| illustration basique des semaphores\n");
  printf("\\------------------------------------\n");
    
  Semaphore sem;

  // Création avec initialisation à une valeur de 1
  sem = sema_creer(1);
  printf("Valeur initiale  : %d\n", sema_getVal(sem));

  // 3 "vendre", i.e. on incrémente trois fois
  sema_vendre(sem);
  sema_vendre(sem);
  sema_vendre(sem);
  printf("Valeur apres 3 V : %d\n", sema_getVal(sem));

  // 2 "prendre", i.e on décrémente 2 fois
  sema_prendre(sem);
  sema_prendre(sem);
  printf("Ce code s'exécute lorsqu'on a pu prendre 2 fois le semaphore\n");
  printf("Valeur apres 2 P : %d\n", sema_getVal(sem));

  // ne pas oublier surtout
  sema_detruire(&sem);
}


/*******************************
 * illustration avec un fork et une SC
 *
 * les deux processus ont presque le même code, mais il est laissé
 * dupliqué pour éviter la création de trop de fonctions
 *******************************/
void demo3()
{
  printf("\n");
  printf("/------------------------------------\n");
  printf("| illustration avec un fork et une section critique\n");
  printf("\\------------------------------------\n");

  // à surtout créer avant le fork, sinon il y a deux sémaphores indépendants
  Semaphore sc = mutex_creer();

  int res = fork();
  if (res > 0)
    {
      // petite attente aléatoire pour que le premier à entrer en SC
      // ne soit pas toujours le même
      srandom(getpid());
      usleep(1 + (random()%10) * 100000);

      printf("(pere) tente d'entrer en section critique\n");
      mutex_prendre(sc);
      printf("(pere) est entré en section critique\n");
      printf("(pere) prend son temps\n");
      sleep(3);
      printf("(pere) va sortir de la section critique\n");
      mutex_vendre(sc);

      // ne pas oublier : le pere attend son fils
      wait(NULL);

      // ne pas oublier non plus
      // à faire absolument après le wait, sinon on risque de le
      // détruire alors que le fils s'en sert encore
      sema_detruire(&sc);
    }
  else
    {
      // petite attente aléatoire pour que le premier à entrer en SC
      // ne soit pas toujours le même
      srandom(getpid());
      //usleep(1 + (random()%10) * 100000);
      sleep(1);
      printf("(fils) tente d'entrer en section critique\n");
      mutex_prendre(sc);
      printf("(fils) est entré en section critique\n");
      printf("(fils) prend son temps\n");
      sleep(3);
      printf("(fils) va sortir de la section critique\n");
      mutex_vendre(sc);

      // attention
      // SURTOUT PAS : sema_detruire(&sc);
      // c'est au père de le détruire :
      // - il ne faut pas le détruire deux fois
      // - si c'est le fils qui le détruit, le père pourrait être en
      //   train de s'en servir
      // note : il y a une fuite mémoire, mais tant pis

      // pour éviter que le fils ne revienne dans le main
      exit(EXIT_SUCCESS);
    }
}

int main()
{
  demo1();
  //demo2();
  //demo3();
  
  return EXIT_SUCCESS;
}
