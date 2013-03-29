#ifndef TOKEN_HG
#define TOKEN_HG

// Define first two state types for comparison
#define ROOT_T 0
#define BLANK_T 1

// ROOT_I = index of root node
#define ROOT_I 0

#define _NUMBER_OF_TOKENS 7

extern char *types_array[_NUMBER_OF_TOKENS];

typedef enum {
    ROOT,
    BLANK,
    IDENTIFIER,
    KEYWORD,
    OPERATOR,
    COMMENT,
    VALUE
} token_type_t;

typedef struct token_struct {
    token_type_t type;
    char *value;
} token_t;

char *get_token_type(token_type_t t);
#endif
