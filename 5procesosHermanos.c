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
  pid_t pid_hijo1, pid_hijo2, pid_hijo3, pid_hijo4, pid_hijo5;

 

  // HIJO1
  pid_hijo1 = fork();
  if (pid_hijo1 == -1) // error, no se ha creado el proceso hijo
  {
    printf("No se ha podido crear el proceso hijo...\n");
    exit(-1);
  }
  else if (pid_hijo1 == 0)
  {
    printf("Soy el hijo 1  Mi padre es= %d, y Mi PID= %d \n", getppid(), getpid());
    sleep(2);
    exit(0);
  }
  /// HIJO 2
  pid_hijo2 = fork();
  if (pid_hijo2 == -1) // error, no se ha creado el proceso hijo
  {

    printf("No se ha podido crear el proceso hijo...\n");
    exit(-1);
  }
  else if (pid_hijo2 == 0)
  {
    printf("Soy el hijo 2  Mi padre es= %d, y Mi PID= %d \n", getppid(), getpid());
    sleep(2);
    exit(0);
  }

  /// HIJO 3
  pid_hijo3 = fork();
  if (pid_hijo3 == -1) // error, no se ha creado el proceso hijo
  {
    printf("No se ha podido crear el proceso hijo...\n");
    exit(-1);
  }
  else if (pid_hijo3 == 0)
  {
    printf("Soy el hijo 3  Mi padre es= %d, y Mi PID= %d \n", getppid(), getpid());
    sleep(2);
    exit(0);
  }
  // HIJO 4
  pid_hijo4 = fork();
  if (pid_hijo4 == -1) // error, no se ha creado el proceso hijo
  {
    printf("No se ha podido crear el proceso hijo...\n");
    exit(-1);
  }
  else if (pid_hijo4 == 0)
  {
    printf("Soy el hijo 4  Mi padre es= %d, y Mi PID= %d \n", getppid(), getpid());
    sleep(2);
    exit(0);
  }
  /// HIJO 5
  pid_hijo5 = fork();
  if (pid_hijo5 == -1) // error, no se ha creado el proceso hijo
  {
    printf("No se ha podido crear el proceso hijo...\n");
    exit(-1);
  }
  else if (pid_hijo5 == 0)
  {
    printf("Soy el hijo 5  Mi padre es= %d, y Mi PID= %d \n", getppid(), getpid());
    sleep(2);
    exit(0);
  }

  wait(NULL);
  printf("Proceso PADRE RAIZ = %d, mi PID: %d \n", getppid(), getpid());

  exit(0);
}
