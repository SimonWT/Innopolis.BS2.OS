#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

// typedef struct File{
//    ino_t inode;
//    bool flag;
//    int nlink;
//    char* name;
// }File;

int main(){
  struct stat *buff = malloc(sizeof(struct stat));
  int count = 0;

  DIR* dirp = opendir("tmp");

  struct dirent* dp;

  while ((dp = readdir(dirp)) != NULL) {
         printf("%s\n", dp->d_name);
         count++;
    }

  dirp = opendir("tmp");

  struct dirent dps[count];

  int i = 0;
  while ((dp = readdir(dirp)) != NULL) {
       dps[i] = *dp;
       printf("%s\n", dps[i].d_name);
       i++;
    }


    ino_t inode;
    for(int j=0; j < count; j++){
      char *p1 = malloc(100);
      strcat(p1, "./tmp/");
      strcat(p1, dps[j].d_name );
      int info = stat( p1, buff);
      printf("%d Check: %s, %d\n", info, dps[j].d_name, buff->st_nlink);
      if( buff -> st_nlink > 1 ){
        inode = buff->st_ino;
        printf("\n%s (%llu) : ", dps[j].d_name , inode);
        dps[j].d_ino = 0;
         for(int k=0; k<count; k++){
           if(dps[k].d_ino!=0){
             char *p = malloc(100);
             strcat(p, "./tmp/");
             strcat(p, dps[k].d_name );
             stat( p, buff);
             if(buff->st_ino == inode ){
               printf("%s (%llu), ", dps[k].d_name , buff->st_ino);
               dps[k].d_ino = 0;
            }
           }
         }
       }
     }

  (void)closedir(dirp);
	return 0;
}

