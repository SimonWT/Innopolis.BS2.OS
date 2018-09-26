#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#define TRUE 1

void sig_handler(int sig){
  printf("Handle signal %d\n", sig);
}

int main(){

  signal(SIGKILL, sig_handler);
  signal(SIGSTOP, sig_handler);
  signal(SIGUSR1, sig_handler);

  while(TRUE){
    printf("I'm in infinite loooop\n");
    sleep(3);
  }

  return 0;
}

//kill -SIGUSR1 was handled with code 10
//But kill -SIGKILL/-SIGSTOP terminated process because cannot be caught by defenition

