#include <iostream>
#include <vector>
#include "globals.h"
#include "Draw.h"
#include "Creeps.h"
#include "gameInit.h"
void InitializeTileSwitch(const Tile& tile) {
    for (int y = tile.position.y; y < tile.position.y + tile.columns && y < GRID_HEIGHT; ++y) {
        for (int x = tile.position.x; x < tile.position.x + tile.rows && x < GRID_WIDTH; ++x) {
            switch (tile.type) {
                case EMPTY:
                    grid[y][x] = {EMPTY};
                break;
                case SPIRE:
                    grid[y][x] = {SPIRE};
                break;
                case WALL:
                    grid[y][x] = {WALL};
                break;
                case CREEP:
                    creeps.emplace_back(Position{y, x}, 1, RED);
                grid[y][x] = {CREEP};
                break;
                default:
                    break;
            }
        }
    }
}



void InitializeGrid() {
    constexpr Tile emptyTile = {EMPTY, {0, 0}, GRID_HEIGHT, GRID_WIDTH};
    constexpr Tile spireTile = {SPIRE, {0, 13}, GRID_HEIGHT - 2, GRID_WIDTH - 2};
    constexpr Tile wallTile = {WALL, {0, 4}, GRID_HEIGHT - 11, GRID_WIDTH - 7};
    constexpr Tile creepTile = {CREEP, {1, 1}, 1, 1};

    InitializeTileSwitch(emptyTile);
    InitializeTileSwitch(spireTile);
    InitializeTileSwitch(wallTile);
    InitializeTileSwitch(creepTile);
}

