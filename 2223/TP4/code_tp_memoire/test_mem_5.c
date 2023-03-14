#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int fibonacci(int n, int f0, int f1){
  if (n == 0){
    return f0;
  }
  else if (n==1){
    return f1;
  }

  return fibonacci(n-1,f1,f0+f1) ;
}

int main(int argc, char** argv){
  char * endptr;
  int base = 10;
  int val=10;
  int f0 = 1;
  int f1 = 1;

  fprintf(stdout,"Suite de fibonacci : \n");

  if (argc == 4){
    val = strtol(argv[1],&endptr,base);
    f0 = strtol(argv[2],&endptr,base);
    f1 = strtol(argv[3],&endptr,base);
  }
  else {
    fprintf(stdout,"Valeurs par défaut utilisées : \n "); 
  }
  fprintf(stdout,"fibo(0) = %d, fibo(1) = %d, n = %d \n",f0,f1,val); 

  fprintf(stdout,"fibo(%d) = %d\n", val, fibonacci(val,f0,f1));

  return EXIT_SUCCESS;

}

