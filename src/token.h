#ifndef TOKEN_H
#define TOKEN_h

char *types_array[5] = {"BLANK", "IDENTIFIER", "KEYWORD", "OPERATOR", "COMMENT"};

typedef enum {
    IDENTIFIER,
    KEYWORD,
    OPERATOR,
    COMMENT,
} token_type_t;

char *get_token_type(token_type_t t) {
    return types_array[t];
}

#endif
