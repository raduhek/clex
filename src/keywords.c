#include "keywords.h"

int is_keyword(char *o) {
    int i, j;
    for (i = NUMBER_OF_KEYWORDS - 1; i >= 0 ; --i) {
        j = 0;
        while(keywords[i][j] != '\0' && o[j] != '\0') {
            if (keywords[i][j] == o[j]) j++;
            else break;
        }
        if (keywords[i][j] == '\0' && o[j] == '\0') return 1;
    }
    return 0;
}

