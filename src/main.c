#include <stdio.h>
#include <stdlib.h>
#include "reader.h"
#include "node.h"
#include "automata.h"
#include "utils.h"
#include "lexer.h"
#include "token.h"

int main() {
    token_t t;
    build_automata();
    
    prepare_lexer("e");

    while(get_token(&t) == 1) {
        if (t.type == ROOT_T) {
            // this is space
            ;
        } else if (t.type == BLANK_T) {
            // this is wrong
            printf("Lexical error found at line %d column %d: %s\n", row_number, column_number, t.value);
            return 2;
        } else {
            printf("%s: %s\n", get_token_type(t.type), t.value);
        }
    }
    return 0;
}
