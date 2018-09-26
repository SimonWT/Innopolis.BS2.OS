#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#define TRUE 1

// void sig_handler(int sig){
//   printf("Handle signal %d\n", sig);
// }

int main(){

  //signal(SIGINT, sig_handler);
  if(fork() == 0){
    while(TRUE){
      printf("I'm alive..\n");
      sleep(1);
    }

  }else{
    sleep(10);
    kill(0,2);
  }


  return 0;
}

//kill 30

