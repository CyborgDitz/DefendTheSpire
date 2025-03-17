#include "globals.h"

Tile grid[GRID_HEIGHT][GRID_WIDTH];

bool InBounds(int y, int x) {
    return (y >= 0 && y < GRID_HEIGHT && x >= 0 && x < GRID_WIDTH);
}