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
    int ret;
    ret = (c - '0' >= 0) && (c - '0' <= 9);
    ret = ret && (c >= 'a' && c <= 'f');
    ret = ret && (c >= 'A' && c <= 'F');

    if (ret) {
        return '@';
    }
    return c;
}

