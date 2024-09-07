#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "node.h"

#define MAX_QUEUE_SIZE 100

// Priority Queue structure
typedef struct PriorityQueue {
    Node *nodes[MAX_QUEUE_SIZE];
    int size;
} PriorityQueue;

void insert_with_priority(PriorityQueue *pq, Node *new_node);
Node *remove_min(PriorityQueue *pq);
Node *remove_with_priority(PriorityQueue *pq);
void heapify_up(PriorityQueue *pq, int index);
void heapify_down(PriorityQueue *pq, int index);
int compare_nodes(const Node *a, const Node *b);

#endif  // PRIORITY_QUEUE_H
