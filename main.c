#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "random_sequence.h"

// Define the node structure
typedef struct node {
    int state[3][3];      // 2D array to represent the puzzle state
    int blank_index;      // Index of the blank (zero) tile
    char moves[4][10];    // Array to store possible moves ("up", "down", "right", "left")
    struct node *parent;  // Pointer to the parent node
} node;

// Function to determine legal moves based on the position of the blank tile
void legal_moves(node *n) {
    // Initialize moves to empty strings
    strcpy(n->moves[0], "");
    strcpy(n->moves[1], "");
    strcpy(n->moves[2], "");
    strcpy(n->moves[3], "");

    // Determine legal moves
    if (n->blank_index > 2) {  // If blank is not in the top row, "up" is a valid move
        strcpy(n->moves[0], "up");
    }
    if (n->blank_index < 6) {  // If blank is not in the bottom row, "down" is a valid move
        strcpy(n->moves[1], "down");
    }
    if (n->blank_index % 3 < 2) {  // If blank is not in the rightmost column, "right" is a valid move
        strcpy(n->moves[2], "right");
    }
    if (n->blank_index % 3 > 0) {  // If blank is not in the leftmost column, "left" is a valid move
        strcpy(n->moves[3], "left");
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

int main() {
    srand(time(NULL));  // Seed the random number generator

    int goal_state[3][3] = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};

    // Example of initializing a node
    node root = {{{1, 2, 3}, {8, 0, 4}, {7, 6, 5}}, 4, {}, NULL};

    // Determine legal moves for the initial state
    legal_moves(&root);

    // Test the legal moves by printing them
    for (int i = 0; i < 4; i++) {
        if (root.moves[i][0] != '\0') {  // Print only if the move is not an empty string
            printf("Move %d: %s\n", i, root.moves[i]);
        }
    }

    int sequence_size = 9;
    int *array = (int *)malloc(sequence_size * sizeof(int));

    random_number_sequence(array, sequence_size);  // Random number sequence usage example

    // Print the shuffled array
    for (int i = 0; i < sequence_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);  // Free allocated memory

    return 0;
}
