#include <iostream>
#include <vector>
#include "globals.h"
#include "Draw.h"
#include "TowerManager.h"
#include "Creeps.h"
#include "gameInit.h"

void InitializeEmpty(int startY, int sizeY, int startX, int sizeX) {
    for (int y = startY; y < startY + sizeY && y < GRID_HEIGHT; ++y) {
        for (int x = startX; x < startX + sizeX && x < GRID_WIDTH; ++x) {
            grid[y][x] ={ EMPTY};
        }
    }
}

void InitializeSpire(int startY, int sizeY, int startX, int sizeX) {
    for (int y = startY; y < startY + sizeY && y < GRID_HEIGHT; ++y) {
        for (int x = startX; x < startX + sizeX && x < GRID_WIDTH; ++x) {
            grid[y][x] = {SPIRE};
        }
    }
}

void InitializeWall(int startY, int sizeY, int startX, int sizeX) {
    for (int y = startY; y < startY + sizeY && y < GRID_HEIGHT; ++y) {
        for (int x = startX; x < startX + sizeX && x < GRID_WIDTH; ++x) {
            grid[y][x] ={ WALL};
        }
    }
}

void InitializeEnemies(int startY, int sizeY, int startX, int sizeX) {
    for (int y = startY; y < startY + sizeY && y < GRID_HEIGHT; ++y) {
        for (int x = startX; x < startX + sizeX && x < GRID_WIDTH; ++x) {
            creeps.emplace_back(Position{x, y}, 1, RED);
            grid[y][x] = {CREEP};
        }
    }
}

void InitializeGrid() {
    InitializeEmpty(0, GRID_HEIGHT, 0, GRID_WIDTH);
    InitializeWall(4, 7, 0, 11);
    InitializeSpire(13, 2, 0, 2);
    InitializeEnemies(1, 1, 1, 1);
}
