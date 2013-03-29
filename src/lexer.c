#include <stdlib.h>
#include <stdio.h>

#include "token.h"
#include "reader.h"
#include "node.h"
#include "utils.h"


node_t *current_state;
node_t *previous_state;
/*
    prepare_lexer takes care of the setup, decoupling
    specific setup from the main() function
*/
void prepare_lexer(char* file_name) {
    set_source(file_name);
    open_file();
    current_state = nodes[0];
    previous_state = NULL;
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
int get_token(token_t *tok) {
    char c;

    while (c != EOF) {
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
            } else {
                // Don't get here please
                tok->type = ROOT_T;
            }
            return 1;
        }
    }

    return 0;
}
