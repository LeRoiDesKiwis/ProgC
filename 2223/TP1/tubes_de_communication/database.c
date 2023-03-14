#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <unistd.h>

#define SIZE 5
#define NBNOTES 6

char* names[]={"Diffie", "Dijkstra", "Hoare", "Kay", "Sutherland"};

int notes[SIZE][NBNOTES];

void init(){
  int perso, note;
  /* Initialisation d'une graine et, à partir d'elle, d'un générateur
     pseudo-aléatoire */
  struct timeval t;
  gettimeofday(&t, NULL);
  srand(t.tv_sec * t.tv_usec * getpid());

  for  (perso = 0 ; perso < SIZE ; perso++){
    for (note = 0 ; note < NBNOTES ; note++){
      long n = lroundl(rand() / (double) RAND_MAX * 20.0);
      notes[perso][note] = (int) n;
    }
  }
  
}

int main(int argc, char * argv[]){
  init();


  /* A COMPLETER POUR AFFICHER LES INFORMATIONS DE LA BASE */
  
  return EXIT_SUCCESS;
}


