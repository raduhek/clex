#include "token.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

void build_automata() {
    char line[128];
    // int i, k, j;
    int number_of_states;
    int state_index, next_state_index, token_type;
    char transition_char;
    FILE *spec_file = fopen("automata.data", "r");

    if (!spec_file) {
        printf("automata.data not found\n");
        exit(2);
    }

    do {
        fgets(line, sizeof(line), spec_file);
    } while ((line != NULL) && (line[0] == '\n' || line[0] == '!'));

    if (line == NULL) {
        printf("automata.data is not properly formatted before reading number of states\n");
        exit (3);
    }

    // Get the number of states
    sscanf(line, "%d", &number_of_states);

    // Initialize the nodes array
    nodes = malloc(number_of_states * sizeof (node_t));

    if (!nodes) {
        printf("could not allocate memory for nodes\n");
        exit(8);
    }

    // Next follow the states
    do {
        fgets(line, sizeof line, spec_file);
        node_t *n;
        if (line == NULL) {
            printf("Could not read %d states from automata.data\n", number_of_states);
            exit(5);
        }
        // Skip empty lines or comments
        if (*line == '\n' || *line == '!') {
            continue;
        }
        n = malloc(sizeof(node_t));
        sscanf(line, "%d : %d", &state_index, &token_type);

        n->type = token_type;
        n->index = state_index;
        nodes[state_index] = n;
        number_of_states--;
    } while(number_of_states != 0); 

    // Here we have created our array of nodes
    // From here 'till EOF come transitions
    while (fgets(line, sizeof(line), spec_file) != NULL) {
        // Skip comments
        if (*line == '\n' || *line == '!' ) continue;
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

