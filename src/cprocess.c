/**
** @file cprocess.c
*/

#include "cprocess.h"

#include <stdlib.h>
#include <string.h>


CompileProcess *
compile_process_new(
    const char * filename
    , const char * filename_out
    , int flags)
{

    FILE * file = fopen(filename, "r");

    if(file == NULL) return NULL;

    FILE * output = NULL;

    if(filename_out != NULL)
    {
        output = fopen(filename_out, "w");
            
        if(output == NULL)
            return NULL;
    }

    CompileProcess * self = malloc(sizeof(CompileProcess));

    if(self != NULL)
    {
        *self = CompileProcess(
                        .cfile.fp = file
                        , .cfile.abs_path = filename
                        , .ofile = output
                        , .flags = flags);
    }

    return self;
}
