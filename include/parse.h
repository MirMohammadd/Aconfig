#ifndef __A_CONFIG_PARSE_H
#define __A_CONFIG_PARSE_H

#include <token.h>
#include <stdlib.h>

Token getMathOperationalCharacters(FILE *src);
void readKeywordsBetweenBeginAndEnd(FILE* source, KeywordList* keywordList);
#endif