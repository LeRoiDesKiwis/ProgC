#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


/* affiche successivement tous les nombres en base 10 contenant size
   chiffres (ceux commençant pas 0 compris).

L'idée est que si on connaît tous les nombres en base 10 contenant
(size-1) chiffres, on peut construire tous les nombres en base 10
contenant size chiffres. Il suffit pour cela de prendre chaque nombre de
(size-1) chiffres et de construire, pour chacun, 10 nombres à size chiffres
en lui ajoutant successivement 0, puis 1, puis... puis 9 en tête.

*/

void afficheNombre(int nb, int * values, int size){

  if (nb > 0){
    int i;
    int val[size-nb+1];
    for (i = 0 ; i < size-nb ; i++){
      val[i]=values[i];
    }
    for (i = 0 ; i <= 9 ; i++){
      val[size-nb]=i;
      afficheNombre(nb-1,val,size);
    }
  }
  else{
    int i;
    for (i = 0 ; i < size ; i++){
      fprintf(stdout,"%d",values[i]);
    }
    fprintf(stdout,"\n");
  }
}

int main(int argc, char * argv[]){

  if (argc != 2){
    fprintf(stderr,"1 argument required : number of digits");
    return EXIT_FAILURE;
  }
  else{
    int nb = strtol(argv[1],NULL,10);
    int * val = NULL;
    afficheNombre(nb, val, nb);

  }
  return EXIT_SUCCESS;
}
