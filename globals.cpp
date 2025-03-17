#include "globals.h"

Tile grid[GRID_HEIGHT][GRID_WIDTH];

void initializeGrid() {
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            if (x<11 && y<11 && y>4) {
                grid[y][x] = {WALL, {y, x}};
            }
            else if (y>=13 && y<=14 && x<=1)
                grid[y][x] = {SPIRE, {y, x}};
            else {
                grid[y][x] = {EMPTY, {y, x}};
            }
        }
    }
}
