#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void declare_correcte();

int main(int argc, char** argv){
   char *s1 = "bonjour";
   char s2[] = "bonjour";
   
   // quelle est la différence entre les deux instructions précédentes ?
   // c'est délicat mais primordiale !
   // Essayez d'afficher les deux variables
   // Essayez de modifier la quatrième (par exemple) case des deux tableau
   // et surtout comprenez ce qu'il se passe
   
   printf("s1 : %s\n", s1);
   printf("s2 : %s\n", s2);
   
   // décommentez pour tester
   /*
   s1[3] = 'z';   // BOUM
   s2[3] = 'z';
   */
   
   printf("s1 : %s\n", s1);
   printf("s2 : %s\n", s2);
   
   // et d'ailleurs la déclaration de s1 est incorrecte
   // cf. fonction declare_correcte
   declare_correcte();
   
   return EXIT_SUCCESS;
}


void declare_correcte()
{
   const char *s1 = "bonjour";
   printf("s1 : %s\n", s1);
   
   // quel est la différence avec l'affection faite dans le main ?
   // décomentez pour tester
   /*
   s1[2] = 'z';   // BOUM
   */
}
