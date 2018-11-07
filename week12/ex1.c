
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
        FILE *fd;
        fd = fopen("/dev/random", "r");
        unsigned char ch = malloc(sizeof(unsigned char));
        if(fd) {
                for(int i=0; i<20; i++) {
                        ch = fgetc(fd);
                        printf("%c", ch);
                }
        }else{
                printf("ERROR: fopen");
        }
        printf("\n");
        return 0;
}
