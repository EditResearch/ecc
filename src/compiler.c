/**
** @file compiler.c
*/

#include "compiler.h"
#include "cprocess.h"



CompileStatus
compile_file(
    const char * filename
    , const char * out_filename
    , int flags)
{
    CompileProcess * cprocess = 
        compile_process_new(
            filename
            , out_filename
            , flags);

    if(cprocess == NULL)
        return COMPILER_FAILED_WITH_ERRORS;

    //perform lexical analysis

    //perform parsing

    //perform code generation

    return COMPILER_FILE_COMPILE_OK;
}
