#include "keywords.h"

char *C_keywords[NUMBER_OF_KEYWORDS] = {
    "auto",
    "break",
    "case",
    "char",
    "const",
    "continue",
    "default",
    "do",
    "double",
    "else",
    "enum",
    "extern",
    "float",
    "for",
    "goto",
    "if",
    "int",
    "long",
    "register",
    "return",
    "short",
    "signed",
    "sizeof",
    "static",
    "struct",
    "switch",
    "typedef",
    "union",
    "unsigned",
    "void",
    "volatile",
    "while",
    };

int is_keyword(char *o) {
    int i, j;
    for (i = NUMBER_OF_KEYWORDS - 1; i >= 0 ; --i) {
        j = 0;
        while(C_keywords[i][j] != '\0' && o[j] != '\0') {
            if (C_keywords[i][j] == o[j]) j++;
            else break;
        }
        if (C_keywords[i][j] == '\0' && o[j] == '\0') return 1;
    }
    return 0;
}

