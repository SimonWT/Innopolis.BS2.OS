
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char** argv){

        for(int i=0; i < argc; i++ ) {
                printf("%s\n", argv[i]);
        }

        int arg = strcmp(argv[1], "-a");
        int num = 0;
        char *mode = "w";
        if(arg == 0) {
                //Append
                printf("append\n");
                mode = "a";
                for (int i = 1; i<argc-1; i++)
                    argv[i] = argv[i+1];
                argc--;
        }

        FILE **outputs = malloc((argc)*sizeof(FILE *));
        outputs[0] = stdout;
        for (int i = 1; i < argc; i++) {
                outputs[i] = fopen(argv[i], mode);
                printf("otkrivayu\n");
        }

        char * buffer = malloc(10000);
        while (fread(buffer, 1, 10000, stdin))
                for (int i = 0; i < argc; i++)
                        for (int j = 0; j < 10000; j++)
                                if(buffer[j]!='\0')
                                        fprintf(outputs[i], "%c", buffer[j]);

        printf("\n");

        //Close filestreams
        for (int i = 1; i < argc; i++) {
                fclose(outputs[i]);
        }

        return 0;
}
