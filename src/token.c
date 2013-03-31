#include "token.h"

char *types_array[_NUMBER_OF_TOKENS] = {
		"ROOT",
		"BLANK",
		"IDENTIFIER",
		"KEYWORD",
		"OPERATOR",
		"COMMENT",
        "VALUE",
        "STRING",
        "CHAR"
	};

char *get_token_type(token_type_t t) {
    return types_array[t];
}
