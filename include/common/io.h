#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stddef.h>


FILE *io_open(const char *path);


int io_copy(FILE *in, FILE *out);

#endif 