/**
** @file cprocess.h
*/

#ifndef _CPROCESS_H_
#define _CPROCESS_H_

#include <stdio.h>

typedef struct
{
    int flags;

    struct
    {
        FILE * fp;
        const char * abs_path;
    }cfile;

    FILE * ofile;
}CompileProcess;


#define CompileProcess(...)(CompileProcess) {__VA_ARGS__}


CompileProcess *
compile_process_new(
    const char * filename
    , const char * filename_out
    , int flags);


#endif
