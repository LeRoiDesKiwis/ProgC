#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
  int i = 0;
  
  while(1){
    fprintf(stdout,"%d\n",i);
    sleep(1);
    i++;
    
  }
  return EXIT_SUCCESS;
}
