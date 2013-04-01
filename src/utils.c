#include "utils.h"
#include "node.h"
#include <stdio.h>

char decode(char c) {
    switch (c) {
        case 'n': return '\n';
        case 'r': return '\r';
        case 's': return ' ';
        default:  return c;
    }
}

int expand(char c, int from_state, int to_state) {
    int i;
    char weird[] = "~!@#$%^&()_+[{]}\\|;:,<.>/?";
    int W_L = 27;
    switch (c) {
        case 'o':
            for (i = '7'; i >= '0'; --i) {
                add_transition(from_state, i, to_state);
            }
            return 1;
        case 'd':
            for (i = '9'; i >= '0'; --i) {
                add_transition(from_state, i, to_state);
            }
            return 1;
        case 'h':
            for (i = '9'; i >= '0'; --i) {
                add_transition(from_state, i, to_state);
            }
            for (i = 'f'; i >= 'a'; --i) {
                add_transition(from_state, i, to_state);
            }
            for (i = 'F'; i >= 'A'; --i) {
                add_transition(from_state, i, to_state);
            }
            return 1;
        case 'c':
            for (i = 'z'; i >= 'a'; --i) {
                add_transition(from_state, i, to_state);
            }
            for (i = 'Z'; i >= 'A'; --i) {
                add_transition(from_state, i, to_state);
            }
            return 1;
        case 'w':
            for (i = W_L; i >= 0; i --) {
                add_transition(from_state, weird[i], to_state);
            }
        default:
            return 0;
    }
}

