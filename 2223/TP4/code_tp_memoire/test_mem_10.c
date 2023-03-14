#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){
  int i;
  int tab1[4] = {1, 2, 3, 4};
  int tab2[4] = {10, 20, 30, 40};

  fprintf(stdout, "adresse de i    : %p \n", (void*) &i);
  fprintf(stdout, "adresse de tab1 : %p \n", (void*) tab1);
  fprintf(stdout, "adresse de tab2 : %p \n", (void*) tab2);
  
  // on modifie le tableau 2 et uniquement lui, et on affiche le tableau 1
  // que se passe-t-il et pourquoi ?
  printf("tab1[0] = %d\n", tab1[0]);
  for (i = 0; i <= 4; i++)
  {
    tab2[i] += 1000;
    // ajoutez un affichage pour comprendre
  }
  printf("tab1[0] = %d\n", tab1[0]);
  
  return EXIT_SUCCESS;
}

