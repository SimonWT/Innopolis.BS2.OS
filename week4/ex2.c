#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

     for (int i = 0; i< 3; i++){
       fork();
     }

   delay(5000);
   return 0;
}

/*
3 times call for();

init───init───bash───bash───sudo───bash───bash─┬─ex2.out─┬─ex2.out─┬─ex2.out───ex2.out
                                               │         │         └─ex2.out
                                               │         ├─ex2.out───ex2.out
                                               │         └─ex2.out
                                               ├─2*[nano]
                                               └─pstree

5 times call for();

init───init───bash───bash───sudo───bash───bash─┬─ex2.out─┬─ex2.out─┬─ex2.out─┬─ex2.out─┬─ex2.out
                                              │         │         │         │         └─ex2.out
                                              │         │         │         ├─ex2.out───ex2.out
                                              │         │         │         └─ex2.out
                                              │         │         ├─ex2.out─┬─ex2.out───ex2.out
                                              │         │         │         └─ex2.out
                                              │         │         ├─ex2.out───ex2.out
                                              │         │         └─ex2.out
                                              │         ├─ex2.out─┬─ex2.out─┬─ex2.out───ex2.out
                                              │         │         │         └─ex2.out
                                              │         │         ├─ex2.out───ex2.out
                                              │         │         └─ex2.out
                                              │         ├─ex2.out─┬─ex2.out───ex2.out
                                              │         │         └─ex2.out
                                              │         ├─ex2.out───ex2.out
                                              │         └─ex2.out
                                              ├─2*[nano]
                                              └─pstree

fork create copy of parent job i times. So in different i, we have more different number of childs.                                             

*/
