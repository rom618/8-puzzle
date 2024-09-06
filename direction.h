#ifndef DIRECTION_H
#define DIRECTION_H

// Define the directions for the puzzle
typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE  // Used to indicate no move
} Direction;

// Function prototypes
const char *direction_to_string(Direction dir);

#endif  // DIRECTION_H
