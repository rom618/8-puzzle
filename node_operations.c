#include "node_operations.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void action(Node *n, const Direction dir) {
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

void expand(Node *n, PriorityQueue *pq, const char *heuristic) {
    legal_moves(n);
    print_legal_moves(n->moves);

    for (int i = 0; i < 4; i++) {
        if (n->moves[i] != NONE) {
            Node *child = (Node *)malloc(sizeof(Node));
            memcpy(child->state, n->state, sizeof(n->state));
            child->blank_index = n->blank_index;
            child->parent = n;
            child->cost = n->cost + 1;

            action(child, n->moves[i]);

            int heuristic_cost = 0;
            if (strcmp(heuristic, "manhattan") == 0) {
                heuristic_cost = calculate_manhattan_distance(child->state);
            } else if (strcmp(heuristic, "misplaced") == 0) {
                heuristic_cost = calculate_misplaced_tiles(child->state);
            }

            child->cost += heuristic_cost;

            insert_with_priority(pq, child);
        }
    }
}

void legal_moves(Node *n) {
    for (int i = 0; i < 4; i++) {
        n->moves[i] = NONE;
    }

    if (n->blank_index > 2) {
        n->moves[0] = UP;
    }
    if (n->blank_index < 6) {
        n->moves[1] = DOWN;
    }
    if (n->blank_index % PUZZLE_SIZE < 2) {
        n->moves[2] = RIGHT;
    }
    if (n->blank_index % PUZZLE_SIZE > 0) {
        n->moves[3] = LEFT;
    }
}

void print_legal_moves(const Direction moves[4]) {
    for (int i = 0; i < 4; i++) {
        if (moves[i] != NONE) {
            printf("Can move: %s\n", direction_to_string(moves[i]));
        }
    }
}

void print_state(Node *n) {
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
