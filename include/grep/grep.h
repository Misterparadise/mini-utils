#ifndef GREP_H
#define GREP_H


typedef struct {
    int show_line_numbers;  // -n flag
} grep_options_t;


int run_grep(int argc, char **argv);

#endif