#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int valeur1 = 4;
int valeur2;

const int constante1 = 5;
const int constante2 = 6;

int main(int argc, char** argv){

  int valeur3 = 4;
  int valeur4;
  const int constante3 = 6;

  fprintf(stdout, "adresse de valeur1 : %p \n", (void*) &valeur1);
  fprintf(stdout, "adresse de valeur2 : %p \n", (void*) &valeur2); 
  fprintf(stdout, "adresse de constante1 : %p \n", (void*) &constante1);
  fprintf(stdout, "adresse de constante2 : %p \n", (void*) &constante2);

  fprintf(stdout, "adresse de valeur3 : %p \n", (void*) &valeur3);
  fprintf(stdout, "adresse de valeur4 : %p \n", (void*) &valeur4);
  fprintf(stdout, "adresse de constante3 : %p \n", (void*) &constante3);


  return EXIT_SUCCESS;
}

