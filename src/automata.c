#include "token.h"
#include <stdio.h>
#include <stdlib.h>

#define NEXT_HASH_MOD 7

typedef struct node {
    int index; // used only for debug
    int *next[NEXT_HASH_MOD];
    token_type_t type;

    // Use this too keep track of array length
    int sizes[NEXT_HASH_MOD];
} node_t;

node_t root;

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


void build_automata() {
    char line[128];
    int k, j, number_of_states;
    int i, state_index, next_state_index, token_type;
    char transition_char;
    FILE *spec_file = fopen("automata.data", "r");

    if (!spec_file) {
        printf("automata.data not found\n");
        exit(2);
    }

    do {
        fgets(line, sizeof(line), spec_file);
    } while ((line != NULL) && line[0] == '!');

    if (!line) {
        printf("automata.data is not properly formatted\n");
        exit (3);
    }

    // Get the number of states
    sscanf(line, "%d", &number_of_states);
    // Initialize the nodes array
    nodes =  malloc(number_of_states * sizeof (node_t*));

    // Read other empty lines of comment lines
    do {
        fgets(line, sizeof(line), spec_file);
    } while ((line != NULL) && line[0] == '!');
    // Did we get to end of file already
    if (!line) {
        printf("automata.data is not properly formatted\n");
        exit (4);
    }

    // Next follow the states
    for (i = 0; i <= number_of_states; ++i) {
        node_t *n = (node_t*)malloc(sizeof(node_t));
        sscanf(line, "%d : %d", &state_index, &token_type);
        fgets(line, sizeof line, spec_file);

        n->type = token_type;
        n->index = state_index;
        nodes[state_index] = n;
    }

    // Here we have created our array of nodes
    // From here 'till EOF come transitions

    while (fgets(line, sizeof(line), spec_file) != NULL) {
        // Skip comments
        if (line[0] == '!') continue;
        sscanf(line, "%d %c -> %d", &state_index, &transition_char, &next_state_index);

        add_transition(nodes[state_index], transition_char, next_state_index); 
    } 

    /*
        Leave this here just for debug
    for (i = 0; i < number_of_states; ++i) {
        printf("Node: %d\n", i);
        for (j = 0; j < 7; ++j) {
            printf("child: %d\n", j);
            k = nodes[i]->sizes[j];
            printf("size(%d, %d) = %d\n", i, j, k);
            while(k) {
                k--;
                printf("next[%d][%d] = %d \n", j, k, nodes[i]->next[j][k]);
            }
            printf("\n");
        }
    }
    */
}

int main() {
    build_automata();
    return 0;
}
