#include <stdlib.h>
#include <stdio.h>

#include "token.h"
#include "reader.h"
#include "node.h"
#include "utils.h"


node_t *current_state;
node_t *previous_state;
token_t *tok;
/*
    prepare_lexer takes care of the setup, decoupling
    specific setup from the main() function
*/
void prepare_lexer(char* file_name) {
    set_source(file_name);
    open_file();
    current_state = nodes[0];
    previous_state = NULL;
    tok = (token_t*) malloc(sizeof(token_t));
}

/*
    get_token keeps reading characters and tries to match
    tokens given the automata

    A token is produced when the node is of type ROOT
    If previous node is BLANK, false is returned and
        the lexer has done his job so far
    otherwise
        the value of that node is returned along with the
        value of the token computed from chars read so far

*/
token_t *get_token() {
    char c;
    /*
        At first, previous_state is NULL
        Root node's index is 0
    */
    while (previous_state == NULL && current_state->index != ROOT_I) {
        c = get_char();
        previous_state = current_state;

        current_state = get_next(current_state, c);

        // If we got to root with the current caracter
        // try again converting it to hexa
        if (current_state->index == ROOT_I) {
            current_state = get_next(previous_state, to_hexa(c));
        }

        // If we got to root with the caracter as hexa
        // try again converting it to digit
        if (current_state->index == ROOT_I) {
            current_state = get_next(previous_state, to_digit(c));
        }
        
        // If we got to root with the caracter as digit 
        // try again converting it to octal
        if (current_state->index == ROOT_I) {
            current_state = get_next(previous_state, to_octa(c));
        }

        // If we got back to root
        if (current_state->index == ROOT_I) {
            // Let's see if the previous state was a final state
            if (previous_state->index != ROOT_I && previous_state->type != ROOT_T && previous_state->type != BLANK_T) {
                tok->type = previous_state->type;
                // We're done with this token
                break;
            } else {
                // Don't get here please
                return NULL;
            }
        }
    }


    /*
        Here, current_state is the root 
        so just set previous_state to NULL
        for next get_token() call
    */
    previous_state = NULL;

    // daca pun print aici, il printeaza
    return NULL;
}
