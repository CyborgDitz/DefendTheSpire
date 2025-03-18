#include <iostream>
#include <vector>
#include "globals.h"
#include "Draw.h"
#include "TowerManager.h"
#include "gameInit.h"

void initializeEmpty(int startY, int sizeY, int startX, int sizeX) {
    for (int y = startY; y < startY + sizeY && y < GRID_HEIGHT; ++y) {
        for (int x = startX; x < startX + sizeX && x < GRID_WIDTH; ++x) {
            grid[y][x] ={ EMPTY};
        }
    }
}

void initializeSpire(int startY, int sizeY, int startX, int sizeX) {
    for (int y = startY; y < startY + sizeY && y < GRID_HEIGHT; ++y) {
        for (int x = startX; x < startX + sizeX && x < GRID_WIDTH; ++x) {
            grid[y][x] = {SPIRE};
        }
    }
}

void initializeWall(int startY, int sizeY, int startX, int sizeX) {
    for (int y = startY; y < startY + sizeY && y < GRID_HEIGHT; ++y) {
        for (int x = startX; x < startX + sizeX && x < GRID_WIDTH; ++x) {
            grid[y][x] ={ WALL};
        }
    }
}

void initializeEnemies(int startY, int sizeY, int startX, int sizeX) {
    std::vector<Enemy> enemies;
    for (int y = startY; y < startY + sizeY && y < GRID_HEIGHT; ++y) {
        for (int x = startX; x < startX + sizeX && x < GRID_WIDTH; ++x) {
            enemies.emplace_back(Position{x, y}, 1, RED);
            grid[y][x] = {CREEP};
        }
    }
}

void initializeGrid() {
    initializeEmpty(0, GRID_HEIGHT, 0, GRID_WIDTH);
    initializeWall(4, 7, 0, 11);
    initializeSpire(13, 2, 0, 2);
    initializeEnemies(1, 1, 1, 1);
}
