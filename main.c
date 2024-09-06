#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "node.h"
#include "random_sequence.h"

// This should be enough to trigger the GitHub action

int main(int argc, char *argv[]) {
    srand(time(NULL));  // Seed the random number generator

    // Default settings
    char *mode = "bruteforce";      // Default mode
    char *heuristic = "manhattan";  // Default heuristic

    // Parse command-line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--mode") == 0 && i + 1 < argc) {
            mode = argv[++i];  // Get the mode value
        } else if (strcmp(argv[i], "--heuristic") == 0 && i + 1 < argc) {
            heuristic = argv[++i];  // Get the heuristic value
        } else {
            printf("Unknown argument: %s\n", argv[i]);
            return 1;  // Exit with error code
        }
    }

    // Display the selected mode and heuristic
    printf("Selected mode: %s\n", mode);
    if (strcmp(mode, "heuristic") == 0) {
        printf("Selected heuristic: %s\n", heuristic);
    }

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
    int *array = malloc(sequence_size * sizeof(int));

    random_number_sequence(array, sequence_size);  // Usage example

    // Print the shuffled array
    for (int i = 0; i < sequence_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);  // Free allocated memory

    return 0;
}
