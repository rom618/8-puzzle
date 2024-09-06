#include <stdio.h>
int main() {
    int goal_state[3][3] = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};
}

typedef struct node {
    int state[3][3] = NULL;
    int blank_index = NULL;
    char *moves[4] = NULL;
    struct node *parent;
}

node
legal_moves(node node) {
    if (node.blank_index < 2) {
        node.moves[0] = 'up';
    }
    if (node.blank_index >= 6) {
        node.moves[0] = 'down';
    }
    if (node.blank_index % 3 == 2) {
        node.moves[0] = 'right';
    }
    if (node.blank_index % 3 == 0) {
        node.moves[0] = 'left';
    }
    return node;
}

action(node node, char *direction) {
}

expand(node node) {
    char *direction in node.moves
}
