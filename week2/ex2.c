#include <stdio.h>
#include <string.h>

int main(){
   char str[255]="Succi Gang";
   printf("%s\n",str);
   for(int i=1; i<=strlen(str); i++)
      printf("%c", str[strlen(str)-i]);
   printf("\n");
   return 0;
}
