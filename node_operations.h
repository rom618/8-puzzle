#ifndef NODE_OPERATIONS_H
#define NODE_OPERATIONS_H

#include "heuristic.h"
#include "priority_queue.h"

void action(Node *n, const Direction dir);
void expand(Node *n, PriorityQueue *pq, const char *heuristic);
void legal_moves(Node *n);
void print_legal_moves(const Direction moves[4]);
void print_state(Node *n);
void swap(int *a, int *b);

#endif  // NODE_OPERATIONS_H
