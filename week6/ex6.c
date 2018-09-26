#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#define TRUE 1

int main(){
  int pipefd[2];
  pipe(pipefd);
  int status;

  pid_t fork_status1;
  pid_t fork_status2;

  fork_status1 = fork();

  if(fork_status1){
    fork_status2 = fork();

    if(fork_status2){
      printf("..Send 2st child pid to 1st child..\n", (int) fork_status2);
      write(pipefd[1], &fork_status2, sizeof(fork_status2));
      printf("..Wait for state changes in second child\n");
      waitpid(fork_status2, &status, 0);
      printf("Got status form 2d child: %d\n",status );

    }else{

    }
  }else{
    sleep(4);
    int child_pid;
    read(pipefd[0], &child_pid, sizeof(child_pid));
    printf("[Child 1]: child2 pid = %d\n", child_pid);

    printf("..Killing child 2..\n");
    kill(child_pid, SIGKILL);
  }




  return 0;
}

//kill 30

