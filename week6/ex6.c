#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#define TRUE 1

int main(){
  int pipefd[2];
  pipe(pipefd);

  int fork_status1;
  int fork_status2;

  fork_status1 = fork();
  if(fork_status1 == 0){
    fork_status2 = fork();
    if(fork_status2 == 0){
      int pid= getpid();
      write(pipefd[1], pid, 500);
      printf("[Child 2]: pid = %d\n..1.Send pid to 1st child..\n", pid);

    }else{
      int child_pid, status;
      read(pipefd[0], child_pid, 500);
      printf("[Child 1]: child2 pid = %d\n", child_pid);
      waitpid(child_pid, status, 0);

    }
  }else{

  }




  return 0;
}

//kill 30

