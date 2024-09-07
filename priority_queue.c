#include "priority_queue.h"

#include <stdio.h>
#include <stdlib.h>

void insert_with_priority(PriorityQueue *pq, Node *new_node) {
    if (pq->size >= MAX_QUEUE_SIZE) {
        printf("Priority queue is full!\n");
        return;
    }
    pq->nodes[pq->size] = new_node;
    heapify_up(pq, pq->size);
    pq->size++;
}

Node *remove_min(PriorityQueue *pq) {
    if (pq->size == 0) return NULL;
    Node *min_node = pq->nodes[0];
    pq->nodes[0] = pq->nodes[pq->size - 1];
    pq->size--;
    heapify_down(pq, 0);
    return min_node;
}

Node *remove_with_priority(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority queue is empty.\n");
        return NULL;
    }

    int minIndex = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->nodes[i]->cost < pq->nodes[minIndex]->cost) {
            minIndex = i;
        }
    }

    Node *minNode = pq->nodes[minIndex];

    for (int i = minIndex; i < pq->size - 1; i++) {
        pq->nodes[i] = pq->nodes[i + 1];
    }

    pq->size--;
    return minNode;
}

void heapify_up(PriorityQueue *pq, int index) {
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (compare_nodes(pq->nodes[index], pq->nodes[parent]) < 0) {
        Node *temp = pq->nodes[index];
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
        Node *temp = pq->nodes[index];
        pq->nodes[index] = pq->nodes[smallest];
        pq->nodes[smallest] = temp;
        heapify_down(pq, smallest);
    }
}

int compare_nodes(const Node *a, const Node *b) {
    return a->cost - b->cost;
}
