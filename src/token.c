#include "token.h"

char *types_array[5] = {"BLANK", "IDENTIFIER", "KEYWORD", "OPERATOR", "COMMENT"};

char *get_token_type(token_type_t t) {
    return types_array[t];
}
