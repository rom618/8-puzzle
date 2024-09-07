#ifndef NODE_H_
#define NODE_H_

#include "direction.h"

#define PUZZLE_SIZE 3
#define PUZZLE_DIMENSION (PUZZLE_SIZE * PUZZLE_SIZE)

typedef struct Node {
    int state[PUZZLE_DIMENSION];
    int blank_index;
    int cost;
    struct Node* parent;
    Direction moves[4];
} Node;

const char* direction_to_string(Direction dir);

#endif  // NODE_H_
