#ifndef HEURISTIC_H_
#define HEURISTIC_H_

#include "node.h"

int calculate_manhattan_distance(const int state[PUZZLE_DIMENSION]);
int calculate_misplaced_tiles(const int state[PUZZLE_DIMENSION]);

#endif  // HEURISTIC_H_
