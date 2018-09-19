#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_THREADS 10

void *hello_world(void* tid){
/*This function prints the thread’s identifier and then exits.*/
  printf("Hello World. Greetings from thread %d\n", (int) tid);
  pthread_exit(0);
}

int main(int argc, char*argv[]){

    pthread_t threads[NUMBER_OF_THREADS];
    int status, i, status_adr;

    for(i=0; i < NUMBER_OF_THREADS; i++) {
      printf("Main here. Creating thread %d\n", i);
      status = pthread_create(&threads[i], NULL, hello_world, i);
      pthread_join(threads[i], NULL);
      if (status != 0) {
          printf("Oops. pthread create returned error code %d\n", status);
          exit(-1);
        }
      }
  return 0;
}

