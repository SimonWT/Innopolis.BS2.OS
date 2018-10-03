#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <memory.h>

void print_array(int *array, int size){
  printf("Array of size = %d : ", size);

  for(int i=0; i<size; i++){
    printf("%d ", array[i]);
  }
   printf("\n");
}

void *myrealloc(int *ptr, size_t size){
  int *new_arr;
  if(size == 0 ){
   free(ptr);
   printf("Size = 0\n");
   return ptr;
  }else if(ptr == NULL){
    new_arr = malloc(size);
    printf("ptr is NULL\n");
  }else{
    new_arr = malloc(size);
    int old_size = sizeof(ptr);
    memcpy(new_arr, ptr, size);
    free(ptr);
  }

  return new_arr;
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

    printf("\nEnter new array size: ");
  	int n2=0;
  	scanf("%d",&n2);

    array = myrealloc(array, n2*sizeof(int));

    print_array(array, n2);


    return 0;
}

