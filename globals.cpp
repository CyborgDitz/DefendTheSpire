#include "globals.h"

Tile grid[GRID_HEIGHT][GRID_WIDTH];

bool InBounds(const Position position) {
    return (position.y >= 0 && position.y < GRID_HEIGHT && position.x >= 0 && position.x < GRID_WIDTH);
}