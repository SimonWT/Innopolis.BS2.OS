#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(){


  for(int i=0; i < 10; i++){
    void* byte1 = malloc(sizeof(char)<<20);
    byte1 = memset(byte1, 0, sizeof(char)<<20);
    sleep(1);
  }

	return 0;
}

//si & so doesnt changes
//But free decreeases first 10 seconds, and after increased to stable number.
//It happens beacause be use allocation memory every second and doesnt free up memory that we used 

