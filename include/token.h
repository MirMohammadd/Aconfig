#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum TokenType{
    TOKEN_BEGIN,
    TOKEN_END,
    TOKEN_IDENTIFIER,
    TOKEN_UNKNOWN,
    TOKEN_EOF,
    TOKEN_PLUS,
    TOKEN_MINUS
} ;


typedef struct {
    enum TokenType type;
    char value[256];
} Token;



void parseToken();