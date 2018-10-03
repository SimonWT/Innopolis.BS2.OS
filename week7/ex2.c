#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void print_array(int *array, int size){
  printf("Array of size = %d : ", size);

  for(int i=0; i<size; i++){
    printf("%d ", array[i]);
  }
   printf("\n");
}

int main(){
    int N;
    printf("Write size of an Array N = ");
    scanf("%d", &N);
    printf("N = %d\n", N);
    int *array = malloc(N*(sizeof(int)));
    for(int i=0; i<N; i++){
       array[i] = i;
    }

    print_array(array, N);
    free(array);

    return 0;
}

