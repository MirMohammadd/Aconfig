#include <statements.h>
#include <stdbool.h>

bool implementIfStatementNumbers(KeywordList *keywordLists,char* operator_1,int num1,int num2){
    if (strcmp(operator_1,"==") == 0){
        if (num1 == num2){
            return true;
        }
    }
}