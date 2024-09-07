#ifndef NODE_H_
#define NODE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "direction.h"

// Define constants for the puzzle dimensions
#define PUZZLE_SIZE 3
#define PUZZLE_DIMENSION (PUZZLE_SIZE * PUZZLE_SIZE)
#define MAX_QUEUE_SIZE 1000

// Define the node structure
typedef struct node {
    // 2D array to represent the puzzle state
    int state[PUZZLE_DIMENSION];
    int blank_index;      // Index of the blank (zero) tile
    Direction moves[4];   // Array to store possible moves
    struct node *parent;  // Pointer to the parent node
    int cost;             // Cost (priority)
} node;

// Priority Queue structure
typedef struct {
    node *nodes[MAX_QUEUE_SIZE];
    int size;
} PriorityQueue;

// Function prototypes
int calculate_manhattan_distance(const int state[PUZZLE_DIMENSION]);
int calculate_misplaced_tiles(const int state[PUZZLE_DIMENSION]);
int compare_nodes(const node *a, const node *b);  // Comparison function for priority
node *remove_min(PriorityQueue *pq);
node *remove_with_priority(PriorityQueue *pq);
void action(node *n, const Direction dir);
void expand(node *n, PriorityQueue *pq, const char *heuristic);
void heapify_up(PriorityQueue *pq, int index);
void heapify_down(PriorityQueue *pq, int index);
void insert_with_priority(PriorityQueue *pq, node *new_node);
void legal_moves(node *n);
void print_legal_moves(const Direction moves[4]);
void print_state(node *n);
void swap(int *a, int *b);
int compare_nodes(const node *a, const node *b);

#endif  // NODE_H_
