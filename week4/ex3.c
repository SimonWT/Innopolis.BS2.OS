#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
   char command[12];
   while(1){
     printf("\nYour command: \n>");
     scanf("%s", command);
     system(command);
              }

   return 0;
}

