/**
** @file token.h
*/

#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <stdbool.h>
#include <stdint.h>


typedef struct
{
    uint32_t row;
    uint32_t column;
    const char * filename;
}FilePosition;


typedef enum
{
    TOKEN_ID
    , TOKEN_KEYWORD
    , TOKEN_OPERATOR
    , TOKEN_SYMBOL
    , TOKEN_NUMBER
    , TOKEN_STRING
    , TOKEN_COMMENT
    , TOKEN_NEWLINE
}TokenType;


typedef struct
{
    TokenType type;
    int flags;
    bool whitespace;
    const char * between_brackets;
}Token;


typedef struct
{
    Token parrent;
    char value[];
}TokenID;


typedef struct
{
    Token parrent;
    char value[];
}TokenKeyword;


typedef struct
{
    Token parrent;
    char value[];
}TokenOperator;


typedef struct
{
    Token parrent;
    char value[];
}TokenSymbol;


typedef struct
{
    Token parrent;
    char value[];
}TokenNumber;


typedef struct
{
    Token parrent;
    char value[];
}TokenString;


typedef struct
{
    Token parrent;
}TokenComment;


typedef struct
{
    Token parrent;
}TokenNewLine;


#endif



