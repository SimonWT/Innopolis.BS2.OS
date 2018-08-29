#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){

  int i=INT_MAX;
  float f=FLT_MAX;
  double d=DBL_MAX;

  printf("%lu, %d\n%lu, %f\n%lu, %lf",sizeof(i), i, sizeof(f), f, sizeof(d), d );

  return 0;

}
