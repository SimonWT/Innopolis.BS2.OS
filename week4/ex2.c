#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

   for (int i = 0; i< 5; i++){
     fork();
   }

  // printf("Privetik ot Rinata\n");
   sleep(5000);
   return 0;
}

