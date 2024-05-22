#include <exceptions.h>
#include <keywords.h>
#include <token.h>
#include <ctype.h>
#include <parse.h>
#include <stdbool.h>

bool isNumeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return false;
        }
        str++;
    }
    return true;
}


int main() {
    FILE* source = fopen("Aconfig", "r");
    if (!source) {
        perror("Failed to open file");
        return 1;
    }
    KeywordList keywordList = { .count = 0 };
    Token Kwrd = getTokenKeyword(&keywordList);
    readKeywordsBetweenBeginAndEnd(source, &keywordList);

    if (Kwrd.type == IF_STATEMENT){
        printf("if statement\n");
    }

    fclose(source);

    printf("Keywords before END:\n");
    for (int i = 0; i < keywordList.count && *(keywordList.keywords[i]); i++) {
        if (isNumeric(keywordList.keywords[i])){
            printf("%s\n", keywordList.keywords[i]);
        }
        if (isdigit(keywordList.keywords[2])){
            printf("%d",keywordList.keywords[i]);
        }
        // printf("%s\n", keywordList.keywords[1]);
    }

    return 0;
}
