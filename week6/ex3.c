#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#define TRUE 1

void sig_handler(int sig){
  printf("Handle signal %d\n", sig);
}

int main(){
  
  signal(SIGINT, sig_handler);
  while(TRUE){
    printf("I'm in infinite loooop\n");
    sleep(20);
  }

  return 0;
}

//kill 30

