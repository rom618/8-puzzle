#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "node.h"
#include "random_sequence.h"

int main() {
    srand(time(NULL));  // Seed the random number generator

    int goal_state[3][3] = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};

    // Example of initializing a node
    node root = {{{1, 2, 3}, {8, 0, 4}, {7, 6, 5}}, 4, {}, NULL};

    // Determine legal moves for the initial state
    legal_moves(&root);

    // Test the legal moves by printing them
    for (int i = 0; i < 4; i++) {
        if (root.moves[i] != NONE) {
            printf("Move %d: %s\n", i, direction_to_string(root.moves[i]));
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
