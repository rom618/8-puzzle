#include "node.h"

// Function to perform an action based on the direction
void action(node *n, const Direction dir) {
    // Change the blank tile position based on the direction
    switch (dir) {
        case UP:
            swap(&n->state[n->blank_index], &n->state[n->blank_index - PUZZLE_SIZE]);
            n->blank_index -= PUZZLE_SIZE;
            break;
        case DOWN:
            swap(&n->state[n->blank_index], &n->state[n->blank_index + PUZZLE_SIZE]);
            n->blank_index += PUZZLE_SIZE;
            break;
        case LEFT:
            swap(&n->state[n->blank_index], &n->state[n->blank_index - 1]);
            n->blank_index -= 1;
            break;
        case RIGHT:
            swap(&n->state[n->blank_index], &n->state[n->blank_index + 1]);
            n->blank_index += 1;
            break;
        default:
            break;
    }
}

// Function to expand the node to generate its children
void expand(node *n) {
    // Generate children nodes based on legal moves
    legal_moves(n);
    print_legal_moves(n->moves);

    // Create child nodes for each valid move
    for (int i = 0; i < 4; i++) {
        if (n->moves[i] != NONE) {
            node *child = (node *)malloc(sizeof(node));
            memcpy(child->state, n->state, sizeof(n->state));
            child->blank_index = n->blank_index;
            child->parent = n;
            action(child, n->moves[i]);
            printf("Child state after %s:\n", direction_to_string(n->moves[i]));
            print_state(child);
        }
    }
}

// Function to determine legal moves based on the position of the blank tile
void legal_moves(node *n) {
    // Initialize moves to NONE
    for (int i = 0; i < 4; i++) {
        n->moves[i] = NONE;
    }

    // Determine legal moves
    // If blank is not in the top row, "up" is a valid move
    if (n->blank_index > 2) {
        n->moves[0] = UP;
    }
    // If blank is not in the bottom row, "down" is a valid move
    if (n->blank_index < 6) {
        n->moves[1] = DOWN;
    }
    // If blank is not in the rightmost column, "right" is a valid move
    if (n->blank_index % PUZZLE_SIZE < 2) {
        n->moves[2] = RIGHT;
    }
    // If blank is not in the leftmost column, "left" is a valid move
    if (n->blank_index % PUZZLE_SIZE > 0) {
        n->moves[PUZZLE_SIZE] = LEFT;
    }
}

void print_legal_moves(const Direction moves[4]) {
    for (int i = 0; i < 4; i++) {
        if (moves[i] != NONE) {
            printf("Can move: %s\n", direction_to_string(moves[i]));
        }
    }
}

void print_state(node *n) {
    for (int i = 0; i < PUZZLE_DIMENSION; i++) {
        printf("%d ", n->state[i]);

        if (i % 3 == 2) printf("\n");
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
