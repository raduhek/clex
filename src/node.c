#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

node_t **nodes;

void add_transition(int state, char c, int next) {
    int i, j;
    int next_index = (int)c % NEXT_HASH_MOD;
    node_t *n = nodes[state];
    int fuck_fix[NEXT_HASH_MOD];

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
        // Do we have room for reaching characters?
        if (nodes[next]->reachers_count == REACHERS_LIMIT) {
            exit(10);
        }

        // A transition has been added before
        // Increase the size of @next array
        int nodes_size = n->sizes[next_index] + 1;
        int *temp = (int*)realloc(n->next[next_index], nodes_size * sizeof(int));
        if (temp) {
            n->next[next_index] = temp;
            n->next[next_index][nodes_size - 1] = next;
            n->sizes[next_index] = nodes_size;
        } else {
            printf("Failed to reallocate memory for transition: %d %c -> %d", n->index, c, next);
            exit(12);
        }
    }
    
    for (i = 0; i < nodes[next]->reachers_count; ++i) {
        if (nodes[next]->reachers[i].node_index == n->index && nodes[next]->reachers[i].c == c) {
            return;
        }
    }

    // this weird (fuck_fix) is here because
    // when adding transition 19 P -> 4
    // nodes[4]->sizes[1] changes from 1 to 19 (don't ask why
    for (j = 0; j < NEXT_HASH_MOD; ++j) {
        fuck_fix[j] = nodes[next]->sizes[j];
    }

    nodes[next]->reachers[i].node_index = n->index;
    nodes[next]->reachers[i].c = c;;
    nodes[next]->reachers_count++;

    for (j = 0; j < NEXT_HASH_MOD; ++j) {
        nodes[next]->sizes[j] = fuck_fix[j];
    }
}

node_t* get_next(node_t *current_node, char c) {
    int i, j, k;
    int rc_size; 
    int next_index = (int)c % NEXT_HASH_MOD;


    // We know the bucket of nodes possible to be reached with char
    // Find the node that can actually be reached
    for (i = 0, k = current_node->sizes[next_index]; i < k; ++i) {
        rc_size = nodes[current_node->next[next_index][i]]->reachers_count;

        // WTF??
        if (rc_size == 0 && current_node->next[next_index][i] != 0) {
            printf("Unreachable node: %d\n", current_node->next[next_index][i]);
        }
        for (j = 0; j < rc_size; ++j) {
            if (nodes[current_node->next[next_index][i]]->reachers[j].node_index == current_node->index
                && nodes[current_node->next[next_index][i]]->reachers[j].c == c) {
                // Found it! Return it
                return nodes[current_node->next[next_index][i]];
            }
        }
    }

    // Return root
    return nodes[0];
}

