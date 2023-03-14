#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void f2()
{
   int tab[4];
   fprintf(stdout, "f2 : adresse de tab   : %p \n", (void*) tab);
   // essayez ici de modifier la valeur du i qui est dans la fonction appelante (i.e. f1)
   // (vous pouvez aussi essayer de planter le programme)
   
}

void f1()
{
   int i = 4;
   
   fprintf(stdout, "f1 : adresse de i     : %p \n", (void*) &i);
   printf("f1 : i = %d\n", i);
   f2();
   printf("f1 : i = %d\n", i);
}

int main(int argc, char** argv){
  f1();  
  return EXIT_SUCCESS;
}

