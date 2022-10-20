#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

// pid=0; proceso hijo
// pid>0; proceo padre
// pid=-1 error.
// no van a compartit mismo segemento de memoria, solo variables

// getpid() obtiene el identificador del proceso que lo invoca
// getppid() obtiene el identificador del padre del proceso que lo invoca

void main()
{

  pid_t pid_hijo;

  printf("soy el proceso padre mi PID es %d, el de mi padre Padre es %d\n", getpid(), getppid());

  for (int i = 0; i < 5; i++)
  {

    pid_hijo = fork();

    if (pid_hijo == 0)
    {

      printf("Soy el hijo %d, Mi padre es= %d, Mi PID= %d \n", i, getppid(), getpid());
      sleep(2);
      exit(0);
    }
  }

  // proceso padre
  wait(NULL);
  printf("Soy el proceso padre mi PID es %d, el de mi padre Padre es %d \n", getpid(), getppid());

  exit(0);
}
