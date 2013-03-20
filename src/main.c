#include <stdio.h>
#include <stdlib.h>
#include "reader.h"
#include "node.h"
#include "automata.h"
#include "utils.h"
#include "lexer.h"
#include "token.h"

int main() {
    token_t *t = (token_t*)malloc(sizeof(token_t));
    build_automata();
    
    prepare_lexer("test");

    *t = get_token();

    if(t) {
        printf("cool\n");
    } else {
        printf("oops\n");
    }

    return 0;
}
