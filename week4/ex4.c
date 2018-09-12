#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
   char command[100];
   while(1){

     printf("\nYour command: \n>");
     fgets(command, 100, stdin);
     system(command);

          }

   return 0;
}

