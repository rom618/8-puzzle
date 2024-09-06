// Copyright [2024] <Roms & Vianpyro>
#include "node.h"

// Function to determine legal moves based on the position of the blank tile
void legal_moves(node *n) {
    // Initialize moves to NONE
    for (int i = 0; i < 4; i++) {
        n->moves[i] = NONE;
    }

    // Determine legal moves
    // If blank is not in the top row, "up" is a valid move
    if (n->blank_index > 2) {
        n->moves[0] = UP;
    }
    // If blank is not in the bottom row, "down" is a valid move
    if (n->blank_index < 6) {
        n->moves[1] = DOWN;
    }
    // If blank is not in the rightmost column, "right" is a valid move
    if (n->blank_index % 3 < 2) {
        n->moves[2] = RIGHT;
    }
    // If blank is not in the leftmost column, "left" is a valid move
    if (n->blank_index % 3 > 0) {
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
