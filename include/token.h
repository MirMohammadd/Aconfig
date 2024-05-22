#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYWORDS 100

enum TokenType{
    TOKEN_BEGIN,
    TOKEN_END,
    TOKEN_IDENTIFIER,
    TOKEN_UNKNOWN,
    TOKEN_EOF,
    TOKEN_PLUS,
    TOKEN_MINUS,
    IF_STATEMENT
} ;
typedef struct {
    char* keywords[MAX_KEYWORDS][256];
    int count;
} KeywordList;

typedef struct {
    enum TokenType type;
    char value[256];
} Token;



void parseToken();

Token getNextToken(FILE *source);
Token  getTokenKeyword(KeywordList* keywordList);