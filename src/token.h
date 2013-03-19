#ifndef TOKEN_HG
#define TOKEN_HG

extern char *types_array[5];

typedef enum {
    IDENTIFIER,
    KEYWORD,
    OPERATOR,
    COMMENT,
} token_type_t;

char *get_token_type(token_type_t t);
#endif
