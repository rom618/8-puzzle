#include <time.h>

#include "node.h"
#include "random_sequence.h"

int locate_blank_index(const int puzzle[PUZZLE_DIMENSION]);

int main(int argc, char *argv[]) {
    // - * - * - * - * - * -* - * - * - * - * -* - * - * - * - * -* - * - * - *
    // Command-line arguments
    // - * - * - * - * - * -* - * - * - * - * -* - * - * - * - * -* - * - * - *
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

    // - * - * - * - * - * -* - * - * - * - * -* - * - * - * - * -* - * - * - *
    // Puzzle initialization
    // - * - * - * - * - * -* - * - * - * - * -* - * - * - * - * -* - * - * - *

    srand(time(NULL));  // Seed the random number generator

    const int goal_state[PUZZLE_DIMENSION] = {1, 2, 3, 8, 0, 4, 7, 6, 5};

    // Generate a random puzzle
    int initial_puzzle[PUZZLE_DIMENSION];
    random_number_sequence(initial_puzzle, PUZZLE_DIMENSION);

    // Initialize root node
    int blank_index = locate_blank_index(initial_puzzle);
    node root = {{0}, blank_index, {}, NULL};
    memcpy(root.state, initial_puzzle, sizeof(initial_puzzle));

    // Print the initial state and legal moves
    print_state(&root);
    expand(&root);
    return 0;
}

int locate_blank_index(const int puzzle[PUZZLE_DIMENSION]) {
    for (int i = 0; i < PUZZLE_DIMENSION; i++) {
        if (puzzle[i] == 0) {
            return i;
        }
    }
    return -1;  // Blank not found
}
