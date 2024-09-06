#ifndef DIRECTION_H_
#define DIRECTION_H_

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

#endif  // DIRECTION_H_
