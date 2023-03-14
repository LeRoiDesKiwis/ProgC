#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  int l,k,j,i;
  int tab[4];
  int autre[4];

  fprintf(stdout, "adresse de i     : %p \n", (void*) &i);
  fprintf(stdout, "adresse de j     : %p \n", (void*) &j);
  fprintf(stdout, "adresse de k     : %p \n", (void*) &k);
  fprintf(stdout, "adresse de l     : %p \n", (void*) &l);
  fprintf(stdout, "adresse de tab   : %p \n", (void*) tab);
  fprintf(stdout, "adresse de autre : %p \n", (void*) autre);
  
  // on remplit tab avec -0, -1, -2, -3
  // que se passe-t-il et pourquoi ?
  for (i = 0; i <= 4; i++)
  {
    tab[i] = -i;
    // ajoutez un affichage pour comprendre
  }
  printf("tab[2] = %d\n", tab[2]);
  
  return EXIT_SUCCESS;
}

