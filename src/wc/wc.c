#include <stdio.h>
#include <stdlib.h>

#include "wc/wc.h"
#include "common/io.h"

#define IN 1
#define OUT 0

typedef struct {
    int show_lines;
    int show_words;
    int show_bytes;
} wc_flags_t;

static int parse_flags(int argc, char **argv, wc_flags_t *flags, int *first_file);

int run_wc(int argc, char **argv)
{
    wc_flags_t flags;
    int first_file;

    if (parse_flags(argc, argv, &flags, &first_file) < 0)
        return 1;

    if (first_file >= argc) {
        fprintf(stderr, "Usage: wc [-lwc] <file>\n");
        return 1;
    }


    
    for (int i = first_file; i < argc; i++) {         
        FILE *fp = io_open(argv[i]);
        if (!fp)
        {
            perror(argv[i]);
            continue;
        }



        size_t lines = 0, words = 0, bytes = 0;
        int state = OUT;
        int ch;

        while((ch = fgetc(fp)) != EOF)
        {

            bytes++;

            if(ch == '\n')
            {
                lines++;
            }


            if(ch == ' ' || ch == '\t')
            {
                state = OUT;
            }
            else if(!state)
            {
                state = IN;
                words++;
            }


        }

        fclose(fp);


        if (flags.show_lines) printf("%zu ", lines);
        if (flags.show_words) printf("%zu ", words);
        if (flags.show_bytes) printf("%zu ", bytes);

        printf("%s\n", argv[i]);
    }        



    return 0;
}


static int parse_flags(int argc, char **argv, wc_flags_t *flags, int *first_file)
{
    flags->show_lines = 0;
    flags->show_words = 0;
    flags->show_bytes = 0;

    int i = 1;
    for(;i < argc; i++)
    {
        if(argv[i][0] != '-')
        break;

        for(int j = 1; argv[i][j]; j++)
        {
            switch(argv[i][j])
            {
                case 'l': flags->show_lines = 1;break;
                case 'w': flags->show_words = 1;break;
                case 'b': flags->show_bytes = 1;break;
                default:
                          fprintf(stderr, "wc: invalid option -- '%c'\n", argv[i][j]);
                          return -1;
            }

        }
    }


    *first_file = i;

    if (!flags->show_lines && !flags->show_words && !flags->show_bytes)
    {
        flags->show_lines = 1;
        flags->show_words = 1;
        flags->show_bytes = 1;
    }

    return 0;




}