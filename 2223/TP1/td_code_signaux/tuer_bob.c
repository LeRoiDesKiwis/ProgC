#define _POSIX_C_SOURCE 1
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

/*
 *
 */
int main()
{
  int pid;
  int signum;
    
  printf("Bonjour, je m'appelle Carlo Tentacule !\n");
  printf("Quel est le numero (pid) de Bob : ");
  scanf("%d", &pid);

  while (1)
    {
      printf("Quel est le numero du signal (<= 0 pour arrêter) : ");
      scanf("%d", &signum);
      if (signum <= 0)
	break;
      if (signum > 31)
        {
	  printf("numero trop grand\n");
	  continue;
        }

      // TODO (i.e. "to do")
      // utilisez la fonction kill ici, en testant le code de retour
    }
    

  return EXIT_SUCCESS;
}
