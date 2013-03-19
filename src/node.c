#include "node.h"
#include <stdlib.h>
#include <stdio.h>

node_t **nodes;

void add_transition(node_t *n, char c, int next) {
    int next_index = (int)c % NEXT_HASH_MOD;
    // No transition for this character yet
    if (n->next[next_index] == NULL) {
        n->next[next_index] = (int*)malloc(1 * sizeof(int));
        if (n->next[next_index] == NULL) {
            printf("Failed to allocate memory for transition: %d %c -> %d", n->index, c, next);
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
        }
    }
}
