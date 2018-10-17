#include <stdlib.h>
#include <stdio.h>

#include <stdbool.h>

typedef struct Frame{
  bool referenced;
  unsigned char lifespan;
  int page_number;

} Frame;

// void ageing(int num, int framesize, Frame* frames){
//   //printf("\n Rad: %d Count = %d", *num, *count);
//
//   bool founded = false;
//
//   for(int i=0; i < framesize; i++ ){
//     if (num == frames[i].page_number){
//       frames[i].referenced = true;
//       founded = true;
//       Hit++;
//       printf("Hit: %d\n",num);
//     }
//   }
//
//   if(!founded){
//       Miss++;
//
//       int minSpan = frames[0].lifespan;
//       int minIndex = 0;
//       for(int j = 1; j < framesize; j++){
//         if(frames[j].lifespan < minSpan){
//           minSpan = frames[j].lifespan;
//           minIndex = j;
//         }
//       }
//
//       frames[minIndex].page_number = num;
//       frames[minIndex].referenced = true;
//   }
//
//   //Shift every lifespan;
//   for(int k = 0; k < framesize; k++){
//       frames[k].lifespan = frames[k].lifespan >> 1;
//       if(frames[k].referenced){
//         frames[k].lifespan = frames[k].lifespan | (1 << (sizeof(frames[k].lifespan)*8-1));
//       }
//   }
// }

int main(){
  int framesize=3;
  int Hit = 0;
  int Miss = 0;

  Frame frames[framesize];
  FILE *fp = fopen("input.txt", "r");
  int num=0;

  for (int i = 0 ; i < framesize; i++) {
    frames[i].page_number = -1;
    frames[i].referenced = false;
    frames[i].lifespan = 0;
  }

  while (fscanf(fp, "%d", &num) == 1) {
    // ageing(num, framesize, &frames);
    //printf("\n Rad: %d Count = %d", *num, *count);

    bool founded = false;

    for (int i = 0; i < framesize; i++) {
      if (num == frames[i].page_number) {
        frames[i].referenced = true;
        founded = true;
        Hit++;
        printf("Hit: %d\n",num);
      }
    }

    if(!founded){
        Miss++;

        unsigned char minSpan = frames[0].lifespan;
        int minIndex = 0;
        for(int j = 1; j < framesize; j++){
          if(frames[j].lifespan < minSpan){
            minSpan = frames[j].lifespan;
            minIndex = j;
          }
        }

        frames[minIndex].page_number = num;
        frames[minIndex].referenced = true;
    }

    //Shift every lifespan;
    for(int k = 0; k < framesize; k++){
        frames[k].lifespan >>= 1;
        if (frames[k].referenced) {
          frames[k].lifespan = frames[k].lifespan | (1 << (sizeof(frames[k].lifespan)*8-1));
        }
    }
  }

  fclose(fp);
  printf("\nHit = %d | Miss = %d\nHit/Miss Rate = %f\n",Hit, Miss, (float) Hit/Miss);

	return 0;
}
