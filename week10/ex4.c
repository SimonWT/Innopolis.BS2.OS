#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

typedef struct File{
   ino_t inode;
   bool flag;
   int nlink;
   char* name;
}File;

int main(){
  struct stat *buff = malloc(sizeof(struct stat));
  int count = 0;

  DIR* dirp = opendir("./tmp");
  
  struct dirent* dp;

  while ((dp = readdir(dirp)) != NULL) {
       stat(dp->d_name, buff );
         count++;
    }

  File files[count];

  int i = 0;
  while ((dp = readdir(dirp)) != NULL) {
       stat(dp->d_name, buff);
         files[i].inode = &buff->st_ino;
         files[i].flag = false;
         files[i].name = dp->d_name;
         files[i].nlink = &buff->st_nlink;
    }



    for(int j=0; j<count; j++){
      if(files[j].nlink > 1){
        files[j].flag = true;
        printf("\n%s (%lu) : ", files[j].name , files[j].inode);
         for(int k=0; k<count; k++){
           if(!files[k].flag && files[j].inode == files[k].inode ){
             printf("%s (%lu), ", files[k].name , files[k].inode);
             files[k].flag = true;
           }
         }
       }
     }


  //int j = 0;
  // while ((dp = readdir(dirp)) != NULL) {
  //      stat(dp->d_name, buff );
  //      if(buff->st_nlink > 1){
  //        files[j]->flag = true;
  //        files[j]->inode = buff->st_ino;
  //        printf("%s (%lu) : ", dp->d_name, buff->st_ino);
  //        j++;
  //
  //        //Search
  //        struct stat hbuff;
  //        while((hdp = readdir(dirp)) != NULL ){
  //           stat(hdp->d_name, hbuff);
  //           if(hbuff -> st_ino == buff -> st_ino){
  //
  //           }
  //        }
  //
  //      }
  //   }

  (void)closedir(dirp);
	return 0;
}

