#include "common/io.h"

#include <errno.h>
#include <string.h>


FILE *io_open(const char *path)
{
    
    return fopen(path, "r");
}


int io_copy(FILE *in, FILE *out)
{
    char buffer[4096];
    size_t n;

    while ((n = fread(buffer, 1, sizeof(buffer), in)) > 0) {
        if (fwrite(buffer, 1, n, out) != n) {
            perror("write");
            return -1;
        }
    }

    if (ferror(in)) {
        perror("read");
        return -1;
    }

    return 0;
}
