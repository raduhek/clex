#ifndef NODE_HG
#define NODE_HG

#include "token.h"

#define NEXT_HASH_MOD 7
#define REACHERS_LIMIT 7

typedef struct reach {
    char c;
    int node_index;
} reach_t;

typedef struct node {
    int index; // used only for debug
    int *next[NEXT_HASH_MOD];
    token_type_t type;

    int reachers_count;
    reach_t reachers[REACHERS_LIMIT];

    // Use this too keep track of array length
    int sizes[NEXT_HASH_MOD];
} node_t;

extern node_t **nodes;
void add_transition(int state, char c, int next);
node_t* get_next(node_t *current_node, char c); 

#endif
