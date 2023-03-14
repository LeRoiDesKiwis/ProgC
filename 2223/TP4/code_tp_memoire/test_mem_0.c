#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){

  fprintf(stdout, "taille d'un caractere : %zd  octet \n", sizeof(char));
  fprintf(stdout, "taille d'un size_t : %zd  octets \n", sizeof(size_t));
  fprintf(stdout, "taille d'un short : %zd  octets \n", sizeof(short));
  fprintf(stdout, "taille d'un int : %zd  octets \n", sizeof(int));
  fprintf(stdout, "taille d'un long : %zd  octets \n", sizeof(long));
  fprintf(stdout, "taille d'un float : %zd  octets \n", sizeof(float));
  fprintf(stdout, "taille d'un double : %zd  octets \n", sizeof(double));

  fprintf(stdout, "taille d'un pointeur : %zd  octets \n", sizeof(void*));
  
  
  return EXIT_SUCCESS;
}

