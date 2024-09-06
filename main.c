#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "node.h"
#include "random_sequence.h"

int locate_blank_index(const int puzzle[PUZZLE_SIZE][PUZZLE_SIZE]);
void list_to_puzzle(const int *shuffled_list, int puzzle[PUZZLE_SIZE][PUZZLE_SIZE]);

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

    const int goal_state[PUZZLE_SIZE][PUZZLE_SIZE] = {
        {1, 2, 3}, {8, 0, 4}, {7, 6, 5}};

    // Generate a random puzzle
    int *shuffled_puzzle = malloc(PUZZLE_DIMENSION * sizeof(int));
    int initial_puzzle[PUZZLE_SIZE][PUZZLE_SIZE];
    random_number_sequence(shuffled_puzzle, PUZZLE_DIMENSION);
    list_to_puzzle(shuffled_puzzle, initial_puzzle);
    free(shuffled_puzzle);  // Free allocated memory

    // Example of initializing a node
    int blank_index = locate_blank_index(initial_puzzle);
    node root = {{{0}}, blank_index, {}, NULL};
    memcpy(root.state, initial_puzzle, sizeof(initial_puzzle));

    // Print the initial state and legal moves
    print_node_state(&root);
    legal_moves(&root);

    // Print the legal moves
    for (int i = 0; i < 4; i++) {
        if (root.moves[i] != NONE) {
            printf("Move %d: %s\n", i, direction_to_string(root.moves[i]));
        }
    }

    return 0;
}

void list_to_puzzle(const int *shuffled_list, int puzzle[PUZZLE_SIZE][PUZZLE_SIZE]) {
    for (int i = 0; i < PUZZLE_SIZE; i++) {
        for (int j = 0; j < PUZZLE_SIZE; j++) {
            puzzle[i][j] = shuffled_list[i * PUZZLE_SIZE + j];
        }
    }
}

int locate_blank_index(const int puzzle[PUZZLE_SIZE][PUZZLE_SIZE]) {
    for (int i = 0; i < PUZZLE_SIZE; i++) {
        for (int j = 0; j < PUZZLE_SIZE; j++) {
            if (puzzle[i][j] == 0) {
                return i * PUZZLE_SIZE + j;
            }
        }
    }
    return -1;  // Blank not found
}
