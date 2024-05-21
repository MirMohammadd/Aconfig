#include <token.h>
#include <keywords.h>

Token getNextToken(FILE* source){
    Token token;
    char buffer[256];

    if (fscanf(source,"%s",buffer) == EOF){
        token.type = TOKEN_EOF;
    }
}