#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>
#include <math.h>

#define CODE "3456712"

/* Crée et retourne une chaîne de caractères contenant
nb chiffres entre 0 et 9 générés aléatoirement  */
char * createCode(int nb){

  char * code = (char *) malloc (sizeof(char)*nb);
  int pos;

  for (pos = 0 ; pos < nb ; pos++){
    sprintf(&code[pos], "%ld",lroundl(rand() / (double) RAND_MAX * 9.0)) ;
  }

  return code;
}

/* Renvoie vrai si les deux chaînes de caractères contiennent les
mêmes caractères, faux sinon 
A noter qu'on aurait aussi pu utiliser la fonction strcmp */
bool found(char *atry, char *code){
  int i = 0;
  bool rep = true;
  while(rep && (atry[i] != '\0' && code[i] != '\0')){
    rep = (atry[i] == code[i]);
    i++;
  }

  return rep && (atry[i] == '\0' && code[i] == '\0');
}

int main(int argc, char * argv[]){

  /* Initialisation d'une graine et, à partir d'elle, d'un générateur
     pseudo-aléatoire */
  struct timeval t;
  gettimeofday(&t, NULL);
  srand(t.tv_sec * t.tv_usec * getpid());
  
  if (argc != 2){
    fprintf(stderr,"1 argument required : number of integers contained in the secret code");
    return EXIT_FAILURE;
  }
  else{
    int nb = strtol(argv[1],NULL,10);
    char * code = createCode(nb);
    char * s = (char *) malloc (nb * sizeof(char));

    /* Lecture sur l'entrée standard de chaînes de caractères, si
       l'une d'elles correspond au code secret généré, le programme
       s'arrête, et affiche le code plus si secret sinon il continue à
       lire sur l'entrée standard jusqu'à ce que le caractère de fin
       de fichier soit détecté */
    while(fscanf(stdin,"%s\n",s) != EOF){
      fprintf(stderr, "chaine : %s\n",s);
      if (found(s,code)){
	fprintf(stdout,"you are connected with password %s\n",s);
	break;
      }
    }

  }
  return EXIT_SUCCESS;
}
