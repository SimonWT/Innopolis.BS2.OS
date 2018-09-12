#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
   char command[100];
   char cmd[10];
   char argument[100];

   while(1){

     printf("\nYour command: \n>");
     fgets(command, 100, stdin);

     int dif;

     for(int i=0; i< 100; i++){
      //printf("%d - '%c' \n", i, command[i]);
       if(command[i]==' '){
         dif = i+1;
         for(int j=0; j<i; j++){
           cmd[j] = command[j];
           if(j==i-1) cmd[j+1] = '\0';
         }
        break;
       }
     }

     for(int k = 0; k < (100 - dif); k++){
       argument[k] = command[k+dif];
     }

     //printf("%s\n%s\n", cmd, argument);


     char* argv[] = {cmd, argument, NULL};


    //system(command);
     fork();

     execvp(argv[0], argv);

   }


   return 0;
}

