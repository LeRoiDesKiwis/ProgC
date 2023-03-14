#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * fonction écrite normalement
 * on stocke le mot de passe dans une variable locale qui est "détruite"
 * lorsqu'on sort de la fonction
 */
void f_normal()
{
   char passwd[30];
   printf("normal tab : %p\n", passwd);
   fprintf(stdout, "votre mot de passe : ");
   scanf("%s", passwd);
   printf("%s\n", passwd);
}

/*
 * dans cette fonction on déclare un tableau "grand" qu'on n'initialise surtout pas
 * et on affiche son contenu
 * ce qui revient à afficher l'état de la pile tel qu'a pu le laisser l'exécution d'une fonction précédente
 * Arrive-t-on à récupérer le mot de passe ?
 */
void f_pirate()
{
   char t[150];
   int i;
   printf("pirate i : %p\n", (void *) &i);
   printf("pirate tab : %p\n", t);
   for (i = 0; i < 150; i++)
      printf("%c\n", t[i]);
}

int main(int argc, char** argv){
  f_normal();
  f_pirate();
  return EXIT_SUCCESS;
}

