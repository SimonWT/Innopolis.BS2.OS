#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    char str1[50];
    char str2[50];
    int size;
    int pipefd[2];
    pipe(pipefd);

    printf("Input 1st string: ");
    scanf("%s", str1);
    size = strlen(str1);
    printf("1st string: %s\n2d string: %s\n", str1, str2);

    if(fork()==0){
      printf("...Pipe...\n");
      read(pipefd[0], str2, size);
      printf("1st string: %s\n2d string: %s\n", str1, str2);
    }else{
      write(pipefd[1], str1, size);

    }



    return 0;
}

