#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>

int main(){
        setvbuf(stdout, NULL, _IOLBF, 5);
        printf("H");
        sleep(1);
        printf("e");
        sleep(1);
        printf("l");
        sleep(1);
        printf("l");
        sleep(1);
        printf("o");
        sleep(1);


        return 0;
}

