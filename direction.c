#include "direction.h"

const char *direction_to_string(Direction dir) {
    switch (dir) {
        case UP:
            return "up";
        case DOWN:
            return "down";
        case LEFT:
            return "left";
        case RIGHT:
            return "right";
        default:
            return "";
    }
}
