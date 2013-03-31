#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "reader.h"

char *_file_path;
FILE *_source_file;

void open_file() {
    if (_source_file) {
        // File is already open. Please close it
        return;
    }
    _source_file = fopen(_file_path, "r");

    if (!_source_file) {
        printf("could not open file '%s'\n", _file_path);
        printf("please chect that it exits or is not being opened by orther process (reader.c)\n");
        exit(1);
    }

    row_number = 1;
    column_number = 0;
}

void set_source(char *file) {
    if (!_file_path) {
        free(_file_path);
    }
    if (_source_file) {
        fclose(_source_file);
    }

    _file_path = (char*)malloc( strlen(file) * sizeof(char) );
    if (!_file_path) {
        printf("could not allocate memory for _file_path (reader.c)\n");
        exit(2);
    }

    strcpy(_file_path, file);
}

char get_char() {
    char c;
    if (!_source_file) {
        open_file();
    }

    c = fgetc(_source_file);

    if (c == '\n') {
        row_number++;
        column_number = 0;
    } else {
        column_number++;
    }

    return c;
}

