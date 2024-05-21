#include <token.h>
#include <keywords.h>

Token getNextToken(FILE* source){
    Token token;
    char buffer[256];

    if (fscanf(source,"%s",buffer) == EOF){
        token.type = TOKEN_EOF;
    }
    if (strcmp(buffer,BEGIN_FILE) == 0){
        token.type = TOKEN_BEGIN;
    } else if (strcmp(buffer,END_FILE) == 0){
        token.type = TOKEN_END;
    } else {
        token.type = TOKEN_IDENTIFIER;
        strcpy(token.value, buffer);
    }
    return token;
}