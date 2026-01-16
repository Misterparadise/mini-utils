#include <stdio.h>
#include <stdlib.h>

#include "cat/cat.h"
#include "common/io.h"

int run_cat(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: cat <file>\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = io_open(argv[i]);
        if (!fp)
        {
            perror(argv[i]);
            continue;
        }

        io_copy(fp, stdout);
        fclose(fp);
    }

    return 0;
}
