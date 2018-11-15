#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

        FILE* fp = fopen("input.txt", "r");
        int processNumber;
        int resoursesNumber;
        char* string;

        fscanf(fp, "%d\n%d\n", &processNumber, &resoursesNumber);
        printf("%d %d\n", processNumber, resoursesNumber);

        int Req[processNumber][resoursesNumber];
        int Cur[processNumber][resoursesNumber];
        int Ex[resoursesNumber];
        int Av[resoursesNumber];
        bool flag[processNumber]; //Not possible to run?

        bool isDeadlock = false;
        bool allFlag = false;

        //Read Existed resourses
        for (int e = 0; e < resoursesNumber; e++) {
                fscanf(fp, "%d", &Ex[e]);
                printf("%d ", Ex[e]);
        }
        printf("\n");

        //Read Available resourses
        for (int a = 0; a < resoursesNumber; a++) {
                fscanf(fp, "%d", &Av[a]);
                printf("%d ", Av[a] );
        }
        printf("\n\n");

        //Read Current usage of resoursed by processes
        for (int e = 0; e < processNumber; e++) {
                for (int f = 0; f < resoursesNumber; f++) {
                        fscanf(fp, "%d", &Cur[e][f]);
                        printf("%d ", Cur[e][f]);
                }
                printf("\n");
                flag[e] = false;
        }
        printf("\n");

        //Read Required resourses for processes
        for (int o = 0; o < processNumber; o++) {
                for (int l = 0; l < resoursesNumber; l++) {
                        fscanf(fp, "%d", &Req[o][l]);
                        printf("%d ", Req[o][l]);
                }
                printf("\n");
        }


        int i=0;
        while(!allFlag && !isDeadlock) {
                for (int j = 0; (j < resoursesNumber) && !flag[i]; j++) {
                        //Check Existance (easy deadlock)
                        if((Req[i][j] + Cur[i][j]) > Ex[j]) {
                                isDeadlock = true;
                                flag[i] = true;
                                break;
                        }

                        //Check Availability to run current process
                        if(Req[i][j] > Av[j]) {
                                flag[i] = true;
                        }

                        //Check can we run this process with him request
                        if((Req[i][j] <= Av[j]) && (j == (resoursesNumber-1)) && !(flag[i])) {
                                //Run this process
                                for(int k = 0; k< resoursesNumber; k++) {
                                        Av[k] = Av[k] + Cur[k];
                                        Cur[i][k] = 0;
                                        Req[i][k] = -1;
                                }

                                flag[i] = false;
                        }

                }

                i++;
                if(i == processNumber) {

                        allFlag = true;
                        for(int p=0; p< processNumber; p++) {
                                allFlag = allFlag && !flag[p];
                                isDeadlock = isDeadlock && flag[p];
                        }
                        i=0;
                }

        }
        FILE* fpw;
        printf("Deadlock? %d\n", isDeadlock );
        if(isDeadlock) {
                fpw = fopen("output_dl.txt", "w");
                fprintf(fpw, "Deadlocked: ");
                for(int i=0; i< processNumber; i++) {
                        if(flag[i]) {
                                fprintf(fpw, "%d ", i);
                        }
                }
        }else{
                fpw = fopen("output_ok.txt", "w");
                fprintf(fpw, "OK");
        }

}
