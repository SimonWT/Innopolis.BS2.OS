
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
   int n = 69;
   int pid = getpid();
   fork();
   if(pid == getpid())
   printf("Hello from parent [%d - %d]\n", pid, n);
   else
   printf("Hello from child [%d - %d]\n", getpid(), n);

   return 0;
}

