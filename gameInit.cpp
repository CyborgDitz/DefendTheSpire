//
// Created by sebba on 2025-03-14.
//
#include <iostream>
#include "globals.h"
#include "Draw.h"
#include "TowerManager.h"
#include "gameInit.h"
void initializeEmpty() {
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            grid[y][x] = {EMPTY};
        }
    }
}
void initializeSpire() {
    for (int y = 13; y <15; y++)
        for (int x = 0; x < 2; x++)
            grid[y][x]=  {SPIRE};
}
void initializeWall() {
    for (int y = 4; y < 11; ++y) {
        for (int x = 0; x < 11; ++x) {
            grid[y][x] = {WALL};
        }
    }
}
void initializeEnemies() {
    std::vector<Enemy> enemies;
    enemies.emplace_back(Position{2, 2}, 1, RED);
}

void initializeGrid() {
    initializeEmpty();
    initializeWall();
    initializeSpire();
    initializeEnemies();
}




