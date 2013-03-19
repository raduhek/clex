#ifndef NODE_HG
#define NODE_HG

#include "token.h"

#define NEXT_HASH_MOD 7

typedef struct node {
    int index; // used only for debug
    int *next[NEXT_HASH_MOD];
    token_type_t type;

    // Use this too keep track of array length
    int sizes[NEXT_HASH_MOD];
} node_t;

extern node_t **nodes;
void add_transition(node_t *n, char c, int next);

#endif
