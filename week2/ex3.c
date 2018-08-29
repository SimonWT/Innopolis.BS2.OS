#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);
  char star = '*';
  char space= ' ';
  int count = 1;
 
  for(int i=1; i<=n;i++){
    for(int lsp=0; lsp<=(n-i); lsp++) printf("%c",space);
    for(int s=1; s<=count; s++) printf("%c",star);
    for(int rsp=0; rsp<=(n-i); rsp++) printf("%c", space);
    printf("\n");
    count+=2;
  }  
  return 0;
}
