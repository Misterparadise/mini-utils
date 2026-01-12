#include <stdio.h>
#include <stdlib.h>
#include "cat.h"




void cat_file(char *file);


int run_cat(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: cat <file>\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        cat_file(argv[i]);
    }

    return 0;
}


void cat_file(char *file)
{

    FILE *stream;


    stream = fopen(file, "r");
    if(stream == NULL)
    {
        perror(file);
        return;
    }

   
    int c;
    while ((c = fgetc(stream)) != EOF) {
        putchar(c);  // print character directly
    }
    

   
    
    

    fclose(stream);
}