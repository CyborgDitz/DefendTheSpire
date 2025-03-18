#include <iostream>
#include <vector>
#include "globals.h"
#include "Draw.h"
#include "Creeps.h"
#include "gameInit.h"

void InitializeTileSwitch(const Tile& tile) {
    for (int y = tile.startY; y < tile.startY + tile.sizeY && y < GRID_HEIGHT; ++y) {
        for (int x = tile.startX; x < tile.startX + tile.sizeX && x < GRID_WIDTH; ++x) {
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
                    creeps.emplace_back(Position{x, y}, 1, RED);
                grid[y][x] = {CREEP};
                break;
                default:
                    break;
            }
        }
    }
}

void InitializeGrid() {
    constexpr Tile emptyTile = {EMPTY, 0, GRID_HEIGHT, 0, GRID_WIDTH};
    constexpr Tile wallTile = {WALL, 4, 7, 0, 11};
    constexpr Tile spireTile = {SPIRE, 13, 2, 0, 2};
    constexpr Tile creepTile = {CREEP, 1, 1, 1, 1};

    InitializeTileSwitch(emptyTile);
    InitializeTileSwitch(wallTile);
    InitializeTileSwitch(spireTile);
    InitializeTileSwitch(creepTile);
}
