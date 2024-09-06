#include "node.h"

// Function to determine legal moves based on the position of the blank tile
void legal_moves(node *n) {
    // Initialize moves to NONE
    for (int i = 0; i < 4; i++) {
        n->moves[i] = NONE;
    }

    // Determine legal moves
    if (n->blank_index > 2) {  // If blank is not in the top row, "up" is a valid move
        n->moves[0] = UP;
    }
    if (n->blank_index < 6) {  // If blank is not in the bottom row, "down" is a valid move
        n->moves[1] = DOWN;
    }
    if (n->blank_index % 3 < 2) {  // If blank is not in the rightmost column, "right" is a valid move
        n->moves[2] = RIGHT;
    }
    if (n->blank_index % 3 > 0) {  // If blank is not in the leftmost column, "left" is a valid move
        n->moves[3] = LEFT;
    }
}

// Function to perform an action based on the direction
void action(node *n, const char *direction) {
    // Implement the action function here
}

// Function to expand the node to generate its children
void expand(node *n) {
    // Implement the expand function here
}
