#ifndef NODE_H_
#define NODE_H_

#include <stdio.h>
#include <stdlib.h>

#include "direction.h"

// Define constants for the puzzle dimensions
#define PUZZLE_SIZE 3
#define PUZZLE_DIMENSION (PUZZLE_SIZE * PUZZLE_SIZE)

// Define the node structure
typedef struct node {
    // 2D array to represent the puzzle state
    int state[PUZZLE_DIMENSION];
    int blank_index;      // Index of the blank (zero) tile
    Direction moves[4];   // Array to store possible moves
    struct node *parent;  // Pointer to the parent node
} node;

// Function prototypes
void action(node *n, const Direction dir);
void expand(node *n);
void legal_moves(node *n);
void swap(int *a, int *b);

#endif  // NODE_H_
