#include <exceptions.h>
#include <keywords.h>
#include <token.h>
#include <parse.h>


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
    for (int i = 0; i < keywordList.count; i++) {
        if (strcmp(keywordList.keywords[i],"IF") == 0){
            printf("if found\n");
        }
        printf("%s\n", keywordList.keywords[i]);
    }

    return 0;
}
