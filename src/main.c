#include <stdio.h>
#include <stdlib.h>
#include "reader.h"
#include "node.h"
#include "automata.h"
#include "utils.h"
#include "lexer.h"
#include "token.h"
#include "value_table.h"

int main() {
    token_t t;
    char *t_val;
    build_automata();
    
    //prepare_lexer("tt/p1.c");
    //prepare_lexer("tt/aici.txt");
    //prepare_lexer("tt/test_c1.txt");
    prepare_lexer("tt/test_c2.txt");

    while(get_token(&t) == 1) {
        t_val = get_value(t.value);
        if (t.type == BLANK_T) {
            // this is wrong
            printf("Lexical error found at line %d column %d: %s\n", row_number, column_number, t_val);
            return 2;
        } else {
            printf("%s: %s (id: %d)\n", get_token_type(t.type), t_val, t.value);
        }
        free(t_val);
    }

    free_value_table();
    return 0;
}
