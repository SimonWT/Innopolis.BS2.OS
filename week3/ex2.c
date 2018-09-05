#include <stdio.h>

#define ARR_SIZE(a)(sizeof(a)/sizeof(*a))

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(){

  int x[] = {6, 4, 2, 1, 6, 0};
  bubble_sort(x, ARR_SIZE(x));
  print_array(x, ARR_SIZE(x));
  return 0;
}

void bubble_sort(int array[], int lenght){
  for(int i=0; i<lenght-1; i++){
    for(int j=0; j<lenght-1-i; j++){
      if(array[j] > array[j+1]){
        swap( &array[j], &array[j+1]);
      }
    }
  }
}

void print_array(int array[], int lenght){
  printf("[");
  for(int i =0; i<lenght; i++ )
    printf(" %d ", array[i]);
  printf("]\n");
}

