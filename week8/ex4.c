#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/resource.h>

int main(){
    struct rusage usage;
  for(int i=0; i < 10; i++){
    void* byte1 = malloc(sizeof(char)<<20);
    byte1 = memset(byte1, 0, sizeof(char)<<20);
    getrusage(RUSAGE_SELF,&usage);
    printf("Memory usage: %lu\n", usage.ru_maxrss);
    sleep(1);
  }

	return 0;
}

