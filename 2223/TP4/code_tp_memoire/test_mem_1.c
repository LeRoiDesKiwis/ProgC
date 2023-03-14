#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){


  short a = 2;
  short b = 4;
  

  fprintf(stdout, "adresse de a : %p \n", (void*) &a);
  fprintf(stdout, "adresse de b : %p \n", (void*) &b); 



  return EXIT_SUCCESS;
}

