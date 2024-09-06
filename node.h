#ifndef NODE_H_
#define NODE_H_

#include <stdio.h>

#include "direction.h"

// Define constants for the puzzle dimensions
#define PUZZLE_SIZE 3
#define PUZZLE_DIMENSION (PUZZLE_SIZE * PUZZLE_SIZE)

// Define the node structure
typedef struct node {
    // 2D array to represent the puzzle state
    const int state[PUZZLE_SIZE][PUZZLE_SIZE];
    int blank_index;      // Index of the blank (zero) tile
    Direction moves[4];   // Array to store possible moves
    struct node *parent;  // Pointer to the parent node
} node;

// Function prototypes
void action(node *n, const char *direction);
void expand(node *n);
void legal_moves(node *n);
void print_node_state(node *n);

#endif  // NODE_H_
