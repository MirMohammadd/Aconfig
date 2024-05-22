#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <token.h>
#include <keywords.h>




#define MAX_KEYWORDS 100


void inline implement(KeywordList* keywordList){
    int i;
    int j;

    for (i = 0;i < keywordList->count;i++){
        if (strcmp(keywordList->keywords[i][i], "if") == 0){
            
        }
    }
}

Token getNextToken(FILE* source) {
    Token token;
    char buffer[256];

    if (fscanf(source, "%s", buffer) == EOF) {
        token.type = TOKEN_EOF;
        return token;
    }

    if (strcmp(buffer, BEGIN_FILE) == 0) {
        token.type = TOKEN_BEGIN;
    } else if (strcmp(buffer, END_FILE) == 0) {
        token.type = TOKEN_END;
    } else {
        token.type = TOKEN_IDENTIFIER;
        strcpy(token.value, buffer);
    }
    return token;
}

void readKeywordsBetweenBeginAndEnd(FILE* source, KeywordList* keywordList) {
    bool beginFound = false;
    bool endFound = false;

    while (!endFound) {
        Token token = getNextToken(source);

        if (token.type == TOKEN_BEGIN) {
            beginFound = true;
        } else if (token.type == TOKEN_END) {
            endFound = true;
        } else if (beginFound && !endFound && token.type == TOKEN_IDENTIFIER) {
            if (keywordList->count < MAX_KEYWORDS) {
                strcpy(keywordList->keywords[keywordList->count], token.value);
                keywordList->count++;
            }
        } else if (token.type == TOKEN_EOF) {
            break;
        }
    }


}


