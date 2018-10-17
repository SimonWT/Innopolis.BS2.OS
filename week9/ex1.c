#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
int Hit = 0;
int Miss = 0;

struct Frame{
  bool referenced;
  int lifespan;
  int page_number;
}Frame;

void ageing(int* num, int* framesize,struct Frame* frames, int* count){
  printf("\n Rad: %d Count = %d", *num, *count);
  bool founded = false;
  int minSpan=255;
  for(int i=0; i< *count; i++ ){
    if ( *num == frames[i].page_number){
      frames[i].referenced = true;
      founded = true;
    }else{
      frames[i].referenced = false;
    }

    if(minSpan > frames[i].lifespan){
      minSpan = frames[i].lifespan;
    }

  }

  if(founded==false){
    Miss= Miss +1;
    if(*count < *framesize){
      frames[*count].page_number = *num;
      frames[*count].referenced = true;
      *count = *count + 1;

      }else{

      //Find smaller lifespan
        int minSpan=255;
        for(int j=0; j< *framesize; j++ ){
          if(minSpan == frames[j].lifespan){
            frames[j].page_number = *num;
            frames[j].lifespan = true;
            break;
          }
        }
    }
  }else{
    Hit = Hit + 1;
  }

  //Shift every lifespan;
  for(int k = 0; k< *framesize; k++){
      frames[k].lifespan = frames[k].lifespan >> 1;
    if(frames[k].referenced == true){
      frames[k].lifespan = frames[k].lifespan | 1 << (sizeof(int)*8-2);
    }
  }

}

int main(){
  int framesize=5;
  scanf("Write your # of pages %d\n", &framesize );

  struct Frame frames[framesize];
  FILE *fp;
  char buff[255];
  char ch;
  fp = fopen("input.txt", "r");
  int count=0;
  int num=0;

  while(fscanf(fp, "%d", &num)==1){
    ageing(&num, &framesize, frames, &count);
    //printf("%d ", num );
  }

  fclose(fp);
  printf("\nHit = %d | Miss = %d\n",Hit, Miss );

	return 0;
}

