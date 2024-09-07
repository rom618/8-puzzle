#include "node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

node *remove_min(PriorityQueue *pq) {
    if (pq->size == 0) return NULL;
    node *min_node = pq->nodes[0];
    pq->nodes[0] = pq->nodes[pq->size - 1];
    pq->size--;
    heapify_down(pq, 0);
    return min_node;
}

node *remove_with_priority(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority queue is empty.\n");
        return NULL;
    }

    // Find the node with the lowest cost
    int minIndex = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->nodes[i]->cost < pq->nodes[minIndex]->cost) {
            minIndex = i;
        }
    }

    // Remove the node with the lowest cost
    node *minNode = pq->nodes[minIndex];

    // Shift the remaining nodes in the queue to fill the gap
    for (int i = minIndex; i < pq->size - 1; i++) {
        pq->nodes[i] = pq->nodes[i + 1];
    }

    pq->size--;  // Decrease the size of the queue
    return minNode;
}

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

// Function to expand the node to generate its children and add them to the priority queue
void expand(node *n, PriorityQueue *pq, const char *heuristic) {
    // Generate children nodes based on legal moves
    legal_moves(n);
    print_legal_moves(n->moves);

    // Create child nodes for each valid move
    for (int i = 0; i < 4; i++) {
        if (n->moves[i] != NONE) {
            // Allocate memory for the new child node
            node *child = (node *)malloc(sizeof(node));
            memcpy(child->state, n->state, sizeof(n->state));
            child->blank_index = n->blank_index;
            child->parent = n;
            child->cost = n->cost + 1;  // g(n) part of the cost

            // Perform the action to create the child's new state
            action(child, n->moves[i]);

            // Calculate the heuristic cost (h(n))
            int heuristic_cost = 0;
            if (strcmp(heuristic, "manhattan") == 0) {
                heuristic_cost = calculate_manhattan_distance(child->state);
            } else if (strcmp(heuristic, "misplaced") == 0) {
                heuristic_cost = calculate_misplaced_tiles(child->state);
            }

            // Total cost f(n) = g(n) + h(n)
            child->cost += heuristic_cost;

            // Add child to the priority queue
            insert_with_priority(pq, child);
        }
    }
}

void heapify_up(PriorityQueue *pq, int index) {
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (compare_nodes(pq->nodes[index], pq->nodes[parent]) < 0) {
        node *temp = pq->nodes[index];
        pq->nodes[index] = pq->nodes[parent];
        pq->nodes[parent] = temp;
        heapify_up(pq, parent);
    }
}

void heapify_down(PriorityQueue *pq, int index) {
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    int smallest = index;

    if (left_child < pq->size && compare_nodes(pq->nodes[left_child], pq->nodes[smallest]) < 0) {
        smallest = left_child;
    }
    if (right_child < pq->size && compare_nodes(pq->nodes[right_child], pq->nodes[smallest]) < 0) {
        smallest = right_child;
    }

    if (smallest != index) {
        node *temp = pq->nodes[index];
        pq->nodes[index] = pq->nodes[smallest];
        pq->nodes[smallest] = temp;
        heapify_down(pq, smallest);
    }
}

// Priority Queue Functions
void insert_with_priority(PriorityQueue *pq, node *new_node) {
    if (pq->size >= MAX_QUEUE_SIZE) {
        printf("Priority queue is full!\n");
        return;
    }
    pq->nodes[pq->size] = new_node;
    heapify_up(pq, pq->size);
    pq->size++;
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

int compare_nodes(const node *a, const node *b) {
    return a->cost - b->cost;
}
