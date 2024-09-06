// Copyright [2024] <Roms & Vianpyro>
#ifndef NODE_H_
#define NODE_H_

#include "direction.h"

// Define the node structure
typedef struct node {
    int state[3][3];      // 2D array to represent the puzzle state
    int blank_index;      // Index of the blank (zero) tile
    Direction moves[4];   // Array to store possible moves
    struct node *parent;  // Pointer to the parent node
} node;

// Function prototypes
void legal_moves(node *n);
void action(node *n, const char *direction);
void expand(node *n);

#endif  // NODE_H_
