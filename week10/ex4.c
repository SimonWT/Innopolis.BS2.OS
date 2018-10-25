#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

int main(){
        struct stat *buff = malloc(sizeof(struct stat));
        int count = 0;

        DIR* dirp = opendir("tmp");
        struct dirent* dp;

        //Count how many files in directory
        while ((dp = readdir(dirp)) != NULL) {
                count++;
        }

        dirp = opendir("tmp");

        //Store files in directories in array
        struct dirent dps[count];

        //File arrays of that files
        int i = 0;
        while ((dp = readdir(dirp)) != NULL) {
                dps[i] = *dp;
                i++;
        }


        ino_t inode;
        for(int j=0; j < count; j++) {
                char *path = malloc(100); //Create a path to the files
                strcat(path, "./tmp/");
                strcat(path, dps[j].d_name );
                stat(path, buff);


                //Find files where number of links more than one and didn't already visited
                if( buff->st_nlink > 1 && dps[j].d_ino != 0) {
                        inode = buff->st_ino; //Store i-node number of that file
                        printf("\n%s (i-node #: %llu ) : ", dps[j].d_name , inode);
                        dps[j].d_ino = 0; //Mark it bs we had seen that
                        struct stat *buff_supp = malloc(sizeof(struct stat));
                        for(int k=0; k<count; k++) {
                                //Find all files that point to the file
                                if(dps[k].d_ino!=0) { // Check visited it or not
                                        char *path_supp = malloc(100); //Create a path to the files
                                        strcat(path_supp, "./tmp/");
                                        strcat(path_supp, dps[k].d_name );
                                        stat(path_supp, buff_supp); //Get stat of that
                                        if(buff_supp->st_ino == inode ) { //Check is it file that point to our
                                                printf("%s (i-node #: %llu ) ", dps[k].d_name, buff_supp->st_ino);
                                                dps[k].d_ino = 0; //Mark it visited
                                        }
                                }
                        }
                }
        }

        (void)closedir(dirp);
        return 0;
}

