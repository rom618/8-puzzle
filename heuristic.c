#include "heuristic.h"

#include <stdlib.h>

// Function to calculate Manhattan distance
int calculate_manhattan_distance(const int state[PUZZLE_DIMENSION]) {
    if (is_goal_state(state)) return 0;

    int distance = 0;
    for (int i = 0; i < PUZZLE_DIMENSION; i++) {
        if (state[i] != 0) {  // Skip the blank tile
            int target_x = (state[i] - 1) / PUZZLE_SIZE;
            int target_y = (state[i] - 1) % PUZZLE_SIZE;
            int current_x = i / PUZZLE_SIZE;
            int current_y = i % PUZZLE_SIZE;
            distance += abs(target_x - current_x) + abs(target_y - current_y);
        }
    }
    return distance;
}

// Function to calculate the number of misplaced tiles
int calculate_misplaced_tiles(const int state[PUZZLE_DIMENSION]) {
    if (is_goal_state(state)) return 0;

    int misplaced = 0;
    for (int i = 0; i < PUZZLE_DIMENSION; i++) {
        if (state[i] != 0 && state[i] != i + 1) {  // Skip the blank tile and correct positions
            misplaced++;
        }
    }
    return misplaced;
}

// Modified is_goal_state to work with a unidimensional array
int is_goal_state(const int state[PUZZLE_DIMENSION]) {
    const int goal_state[PUZZLE_DIMENSION] = {
        1, 2, 3,
        8, 0, 4,
        7, 6, 5};

    for (int i = 0; i < PUZZLE_DIMENSION; i++) {
        if (state[i] != goal_state[i]) {
            return 0;
        }
    }

    return 1;
}
