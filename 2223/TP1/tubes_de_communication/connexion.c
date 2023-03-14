#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>
#include <math.h>

#define CODE "3456712"

/* Cr�e et retourne une cha�ne de caract�res contenant
nb chiffres entre 0 et 9 g�n�r�s al�atoirement  */
char * createCode(int nb){

  char * code = (char *) malloc (sizeof(char)*nb);
  int pos;

  for (pos = 0 ; pos < nb ; pos++){
    sprintf(&code[pos], "%ld",lroundl(rand() / (double) RAND_MAX * 9.0)) ;
  }

  return code;
}

/* Renvoie vrai si les deux cha�nes de caract�res contiennent les
m�mes caract�res, faux sinon 
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

  /* Initialisation d'une graine et, � partir d'elle, d'un g�n�rateur
     pseudo-al�atoire */
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

    /* Lecture sur l'entr�e standard de cha�nes de caract�res, si
       l'une d'elles correspond au code secret g�n�r�, le programme
       s'arr�te, et affiche le code plus si secret sinon il continue �
       lire sur l'entr�e standard jusqu'� ce que le caract�re de fin
       de fichier soit d�tect� */
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
