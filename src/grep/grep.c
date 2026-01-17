#include <stdio.h>
#include <string.h>
#include <string.h>

#include "grep/grep.h"
#include "common/io.h"

#define MAX_LINE 1024

int run_grep(int argc, char **argv)
{
    if(argc < 3)
    {
        fprintf(stderr, "Usage: grep <pattern> <file>\n");
        return 1;
    }

    char *pattern = argv[1];
    char *file_name = argv[2];

    FILE *fp = io_open(file_name);
    if (!fp) {
        perror(file_name);
        return 1;
    }

    char line[MAX_LINE];

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, pattern)) {
            fputs(line, stdout);
        }
    }

    fclose(fp);


    return 0;
}