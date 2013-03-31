#include "utils.h"
#include "node.h"
#include <stdio.h>

char decode(char c) {
    switch (c) {
        case 'n': return '\n';
        case 's': return ' ';
        default:  return c;
    }
}

int expand(char c, int from_state, int to_state) {
    int i;
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
        case 'f':
            for (i = '9'; i >= '0'; --i) {
                add_transition(from_state, i, to_state);
            }
            for (i = 'a'; i >= 'f'; --i) {
                add_transition(from_state, i, to_state);
            }
            for (i = 'A'; i >= 'F'; --i) {
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
        default:
            return 0;
    }
}

