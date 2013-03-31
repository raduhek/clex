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
