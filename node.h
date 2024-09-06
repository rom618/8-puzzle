#ifndef NODE_H_
#define NODE_H_

#include <stdio.h>

#include "direction.h"

// Define the node structure
typedef struct node {
    const int state[3][3];  // 2D array to represent the puzzle state
    int blank_index;        // Index of the blank (zero) tile
    Direction moves[4];     // Array to store possible moves
    struct node *parent;    // Pointer to the parent node
} node;

// Function prototypes
void action(node *n, const char *direction);
void expand(node *n);
void legal_moves(node *n);
void print_node_state(node *n);

#endif  // NODE_H_
