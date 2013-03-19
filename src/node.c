#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

node_t **nodes;

void add_transition(node_t *n, char c, int next) {
    int rc_limit;
    int next_index = (int)c % NEXT_HASH_MOD;

    rc_limit = strlen(nodes[next]->reaching_chars);
    // Do we have room for reaching characters?
    if (rc_limit == REACH_CHAR_LIMIT ) {
        printf(
            "Node reaching_chars limit exceeded for node: %d with char %c from node %d (limit %d | chars %s)\n",
            next,
            c,
            n->index,
            rc_limit,
            nodes[next]->reaching_chars
        );
        exit(10);
    }

    // No transition for this character yet
    if (n->next[next_index] == NULL) {
        n->next[next_index] = (int*)malloc(1 * sizeof(int));
        if (n->next[next_index] == NULL) {
            printf("Failed to allocate memory for transition: %d %c -> %d", n->index, c, next);
            exit(11);
        }
        n->next[next_index][0] = next;
        n->sizes[next_index] = 1;
    } else {
        // A transition has been added before
        // Increase the size of @next array
        int nodes_size = n->sizes[next_index] + 1;
        int *temp = (int*)realloc(n->next[next_index], nodes_size * sizeof(int));
        if (temp) {
            n->next[next_index] = temp;
            n->sizes[next_index] = nodes_size;
        } else {
            printf("Failed to reallocate memory for transition: %d %c -> %d", n->index, c, next);
            exit(12);
        }
    }
    
    nodes[next]->reaching_chars[rc_limit] = c;
    printf("%d\n", rc_limit);
}
