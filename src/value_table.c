#include <stdlib.h>
#include <stdio.h>
#include "value_table.h"

void prepare_value_table() {
    vt_len = 0;
    value_table = (char**)malloc(vt_len * sizeof(char*));
}

void free_value_table() {
    int i;
    for (i = vt_len - 1; i >= 0; --i) {
        free(value_table[i]);
    }
    free(value_table);
}

char *get_value(int idx) {
    char *str;
    int vl = 9, i = 0;
    if (idx > vt_len) {
        return '\0';
    } else {
        while (value_table[idx][vl] != '\0') {
            vl++;
        }
        vl++;
        str = (char*)malloc(vl * sizeof(char));
        while (value_table[idx][i] != '\0') {
            str[i] = value_table[idx][i];
            i++;
        }
        str[i] = '\0';
    }
    return str;
}

int get_or_create_entry(char *o, int len) {
    char **temp;
    int i, j;
    for (i = vt_len - 1; i >= 0 ; --i) {
        j = 0;
        while(value_table[i][j] != '\0' && o[j] != '\0') {
            if (value_table[i][j] == o[j]) j++;
            else break;
        }
        if (value_table[i][j] == '\0' && o[j] == '\0') return i;
    }

    // Getting here means the value has not been found
    // So let's insert it
    temp = (char**) realloc(value_table, (vt_len + 1)  * sizeof(char*));
    if (!temp) {
        printf("Could not reallocate memory for value_table\n");
        exit(15);
    }
    value_table = temp;
    value_table[vt_len] = (char*)malloc(len * sizeof(char));
    i = 0;
    while (o[i] != '\0') {
        value_table[vt_len][i] = o[i];
        i++;
    }
    value_table[vt_len][i] = '\0';
    vt_len ++;

    return vt_len - 1;
}
