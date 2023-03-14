#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char** argv){
  int exitvalue,seconds;
  int res = 0;
  int status = 0;
  if (argc != 3){
    fprintf(stderr,"2 arguments required");
    exit(EXIT_FAILURE);
  } 

  exitvalue = strtol(argv[1],NULL,10);
  seconds = strtol(argv[2],NULL,10);
  
  res = fork();
  if (res == -1){
    perror("Error : process creation in main");
    exit(EXIT_FAILURE);
  }
  else if (res != 0){
    int ret = wait(&status);
    fprintf(stdout, "%d pere de %d  \n", getpid(),ret);
  
    if (WIFEXITED(status)) {
      fprintf(stdout, "fils sorti avec la valeur de retour %d  \n", WEXITSTATUS(status) );
    }
    else if (WIFSIGNALED(status)){
      fprintf(stdout, "fils sorti à cause du signal %d  \n", WTERMSIG(status) );
    }
    
  }
  else{
    sleep(seconds);
    fprintf(stdout, "%d fils de %d  \n", getpid(),getppid());
    return exitvalue;
  }
  return EXIT_SUCCESS;
}
