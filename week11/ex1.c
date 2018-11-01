#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>

int main(){
        char *new_string = "This is a nice day";
        struct stat* stat_info = malloc(sizeof(struct stat)); //Create stat variable
        char *path = malloc(100); //Create a path to the files
        strcat(path, "ex1.txt"); //Concatenate path with name of file
        int fd;
        int lenght;
        fd = open("ex1.txt", O_RDWR); //open file with permission(Owner Read & Write)
        stat(path, stat_info); //Get stat of file ex1.txt
        lenght = stat_info->st_size; //Get size of the file

        if(lenght!=strlen(new_string)){
          ftruncate(fd, strlen(new_string));
        }

        char* map = mmap(path, strlen(new_string), PROT_WRITE, MAP_SHARED, fd, 0);
        memcpy(map, new_string, strlen(new_string));
        munmap(path, strlen(new_string));
        close(fd);
        return 0;
}
