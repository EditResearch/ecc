/**
** @file compiler.h
*/

#ifndef _COMPILER_H_
#define _COMPILER_H_ 


typedef enum
{
    COMPILER_FILE_COMPILE_OK
    , COMPILER_FAILED_WITH_ERRORS
}CompileStatus;


CompileStatus
compile_file(
    const char * filename
    , const char * out_filename
    , int flags);

#endif
