#include <stdio.h>
#include <string.h>


#include "grep/grep.h"
#include "common/io.h"



#define MAX_LINE 1024

static int parse_flags(int argc, char **argv, grep_options_t *flag);
int grep_strem(FILE *in, const char *pattern, grep_options_t *flag);


int run_grep(int argc, char **argv)
{
    grep_options_t flags = {0}; 
    int pattern_pos;
   
    if(argc < 3)
    {
        fprintf(stderr, "Usage: grep <pattern> <file>\n");
        return 1;
    }
    
    pattern_pos = parse_flags(argc, argv, &flags);
    

   
    
    if(pattern_pos < 0 || pattern_pos >= argc - 1)
    {
        fprintf(stderr, "Usage: grep [-n] PATTERN FILE...\n");
        return 1;
    }

    const char *pattern = argv[pattern_pos];

   
    for(int i = pattern_pos + 1; i < argc; i++)
    {


        FILE *fo = io_open(argv[i]);
        if(fo == NULL)
        {
           
            continue;
        }

        grep_strem(fo, pattern, &flags);
    

        fclose(fo);
    }
     

    return 0;
}



int grep_strem(FILE *in, const char *pattern, grep_options_t *flag)
{
    char line[MAX_LINE];
    int line_num = 1;
    


    while(fgets(line, sizeof(line), in))
    {
        if(strstr(line, pattern))
        {
            if(flag && flag->show_line_numbers)
            {
                printf("%d %s", line_num, line);
            }
            else
            {
                printf("%s", line);
            }
        }

        line_num++;
    }

    return 0;
}



static int parse_flags(int argc, char **argv, grep_options_t *flag)
{
    flag->show_line_numbers = 0;
    
    int i = 1;

    while(i < argc && argv[i][0] == '-' && strcmp(argv[i], "--") != 0)
    {
        if (strcmp(argv[i], "--") == 0)
        {
            i++;
            break;
        }
        else if(strcmp(argv[i], "-n") == 0)
        {
            flag->show_line_numbers = 1;
        }
        else
        {
            fprintf(stderr, "grep: unknown option %s\n", argv[i]);
            return -1;
        }

        i++;
    }

    return i;
}