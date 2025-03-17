#include "globals.h"
std::vector<std::vector<Tile>> grid;

void initializeGrid() {
    grid.resize(MAP_HEIGHT, std::vector<Tile>(MAP_WIDTH));

    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            grid[y][x] = {EMPTY, {x, y}};  // Set each tile as EMPTY with correct coordinates
        }
    }
}