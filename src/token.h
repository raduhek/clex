#ifndef TOKEN_HG
#define TOKEN_HG

// Define first two state types for comparison
#define ROOT_T 0
#define BLANK_T 1

// ROOT_I = index of root node
#define ROOT_I 0

// Define KEYWORD_T to be used in lexer
#define KEYWORD_T 3

// Define COMMENT_T to be used in lexer
#define COMMENT_T 5

#define _NUMBER_OF_TOKENS 9

extern char *types_array[_NUMBER_OF_TOKENS];

typedef enum {
    ROOT,           // 0
    BLANK,          // 1
    IDENTIFIER,     // 2
    KEYWORD,        // 3
    OPERATOR,       // 4
    COMMENT,        // 5
    VALUE,          // 6
    STRING,         // 7
    CHAR            // 8
} token_type_t;

typedef struct token_struct {
    token_type_t type;
    int value;
} token_t;

char *get_token_type(token_type_t t);
#endif
