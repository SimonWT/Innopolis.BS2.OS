#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(){
	char* byte1;

  for(int i=0; i < 10; i++){
    byte1 = malloc(sizeof(char)>>20);
    byte1 = memset(byte1, 0, sizeof(char)>>20);
    sleep(1);
  }

	return 0;
}

