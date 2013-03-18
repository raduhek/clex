#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *_file_path;
FILE *_source_file;

void open_file() {
    if (_source_file) {
        // File is already open. Please close it
        return;
    }
    _source_file = fopen(_file_path, "r");

    if (!_source_file) {
        exit(1);
    }
}

void set_source(char *file) {
    char *ff;
    if (!_file_path) {
        free(_file_path);
    }
    if (_source_file) {
        fclose(_source_file);
    }

    _file_path = malloc( strlen(file) * sizeof(char) );
    strcpy(_file_path, file);
}

char get_char() {
    if (!_source_file) {
        open_file();
    }

    return fgetc(_source_file);
}

