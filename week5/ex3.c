#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define SLEEP_TIME 6
int buffer[N];
int count = 0; //Number of elements in buffer
pthread_mutex_t mutex;
pthread_cond_t cond_con, cond_pro;


void *producer(){
    while(1){

      pthread_mutex_lock(&mutex);
      if(count == N){
        pthread_cond_wait(&cond_pro, &mutex);
      }
      sleep(SLEEP_TIME);

      buffer[count] = 66;
      printf("[PROD] Counter = %d; Element = %d\n", count, buffer[count]);
      count=count+1;

      if(count == N - 1){
       pthread_cond_signal(&cond_con);
       pthread_mutex_unlock(&mutex);
     }

    }
      pthread_exit(0);
  }

void *consumer(){
    while(1){

      pthread_mutex_lock(&mutex);
      if(count == 0){
        pthread_cond_wait(&cond_con, &mutex);
      }

      sleep(SLEEP_TIME);
      buffer[count] = 0;
      printf("[CONS] Counter = %d; Element = %d\n", count, buffer[count]);
      count=count-1;

      if(count == 1){
       pthread_cond_signal(&cond_pro);
       pthread_mutex_unlock(&mutex);
     }

    }
      pthread_exit(0);
  }

int main(int argc, char*argv[]){

    pthread_t tproducer, tconsumer;
    int status_pro, i, status_cons;

    pthread_mutex_init(&mutex, 0);
    pthread_cond_init(&cond_con, 0);
    pthread_cond_init(&cond_pro, 0);

    status_pro = pthread_create(&tproducer, NULL, producer, NULL);
    status_cons = pthread_create(&tconsumer, NULL, consumer, NULL);

    pthread_join(tproducer, NULL);
    pthread_join(tconsumer, NULL);

    pthread_cond_destroy(&cond_con);
    pthread_cond_destroy(&cond_pro);
    pthread_mutex_destroy(&mutex);

    if (status_pro != 0 || status_cons!=0) {
        printf("pthread create returned error code %d | %d\n", status_pro,status_cons);
        exit(-1);
      }


    return 0;
}

