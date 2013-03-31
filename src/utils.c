#include "utils.h"
#include <stdio.h>

char to_digit(char c) {
    if (c - '0' >= 0 && c - '0' <= 9) {
        
        return '#';
    } 
    return c;
}

char to_octa(char c) {
    if (c - '0' >= 0 && c - '0' <= 7) {
        return '$';
    }
    return c;
}


char to_hexa(char c) {
    if (to_digit(c) == '#') return '@';
    if ((c < 'a' || c > 'f') && (c < 'A' || c > 'F')) return c;

    return '@';
}

char to_letter(char c) {
    if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) return c;

    return '~';
}
