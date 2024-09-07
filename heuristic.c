#include "heuristic.h"

#include <stdlib.h>

int calculate_manhattan_distance(const int state[PUZZLE_DIMENSION]) {
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

int calculate_misplaced_tiles(const int state[PUZZLE_DIMENSION]) {
    int misplaced = 0;
    for (int i = 0; i < PUZZLE_DIMENSION; i++) {
        if (state[i] != 0 && state[i] != i + 1) {  // Skip the blank tile and correct positions
            misplaced++;
        }
    }
    return misplaced;
}
