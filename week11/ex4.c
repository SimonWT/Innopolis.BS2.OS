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
        char *path1 = malloc(100); //Create a path to the first file
        char *path2 = malloc(100); //Create a path to the second file
        strcat(path1, "ex1.txt"); //Concatenate path with name of file
        strcat(path2, "ex1.memcpy.txt"); //Concatenate path with name of file
        int fd1;
        int fd2;
        int lenght;
        fd1 = open("ex1.txt", O_RDWR); //open file with permission(Owner Read & Write)
        fd2 = open("ex1.memcpy.txt", O_RDWR); //open file with permission(Owner Read & Write)

        stat(path1, stat_info); //Get stat of file ex1.txt
        lenght = stat_info->st_size; //Get size of the file

        char* map1 = mmap(path1, lenght, PROT_WRITE, MAP_SHARED, fd1, 0);

        ftruncate(fd2, lenght);


        char* map2 = mmap(path2, lenght, PROT_WRITE, MAP_SHARED, fd2, 0);
        memcpy(map2, map1, lenght);
        munmap(path1, lenght);
        munmap(path2, lenght);
        close(fd1);
        close(fd2);
        return 0;
}
