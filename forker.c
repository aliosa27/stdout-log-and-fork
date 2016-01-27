
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv) {
  if (argc <= 1) {
    printf("./forker <program and args> \n");
    exit(1);
  }
//char *log ="/tmp/wootlogger";



  pid_t pid;

  if ((pid = fork()) < 0) {
    perror("fork error.");
    exit(1);
  } else if (!pid) {

    // Child.
 int fd = open("/tmp/forker", O_WRONLY ); 
        close( 1 );  // existing stdout is no more
        dup( fd );  // stdout is now fd
        printf("child pid: %d\n", pid);
     if (execve(argv[1], &(argv[1]), NULL) == -1) {
      perror("execve error.");
      exit(1);
    }
  } else {
    // Parent: do nothing.
  }
  return 0;
}
