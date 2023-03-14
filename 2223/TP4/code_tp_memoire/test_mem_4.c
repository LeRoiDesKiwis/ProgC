#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int valeur1 = 4;
int valeur2;

const int constante1 = 5;
const int constante2 = 6;


int mafonctioninutile(){
  return 0;
}

void madeuxiemefonction(int p1, int p2){

  fprintf(stdout, "madeuxiemefonction - adresse de p1 : %p \n", (void *) &p1);
  fprintf(stdout, "madeuxiemefonction - adresse de p2 : %p \n", (void *) &p2);
}

void matroisiemefonction(int param1, int param2){

  fprintf(stdout, "matroisiemefonction - adresse de param1 : %p \n", (void *) &param1);
  fprintf(stdout, "matroisiemefonction - adresse de param2 : %p \n", (void *) &param2);

  madeuxiemefonction(param1,param2);
}

const int t = 4;
int main(int argc, char** argv){

  int valeur3 = 4;
  int valeur4;
  const int constante3 = 6;

  int *  tabmain = (int *)  malloc(6*sizeof(int));
  char * chainemain = (char *) malloc(6*sizeof(char));

  fprintf(stdout, "adresse de valeur1 : %p \n", (void*) &valeur1);
  fprintf(stdout, "adresse de valeur2 : %p \n", (void*) &valeur2); 
  fprintf(stdout, "adresse de constante1 : %p \n", (void*) &constante1);
  fprintf(stdout, "adresse de constante2 : %p \n", (void*) &constante2);
  fprintf(stdout, "adresse de tabmain : %p \n", (void*) tabmain);
  fprintf(stdout, "adresse de chainemain : %p \n", (void*) chainemain);

  fprintf(stdout, "adresse de valeur3 : %p \n", (void*) &valeur3);
  fprintf(stdout, "adresse de valeur4 : %p \n", (void*) &valeur4);
  fprintf(stdout, "adresse de constante3 : %p \n", (void*) &constante3);

  free(tabmain);
  free(chainemain);


  return EXIT_SUCCESS;
}

