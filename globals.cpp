#include "globals.h"

Tile grid[GRID_WIDTH][GRID_HEIGHT];
void initializeGrid() {


    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            grid[y][x] =
            grid[y][x] = {EMPTY, {y, x}};
        }
    }
}