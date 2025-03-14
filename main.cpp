#include <iostream>
#include "globals.h"
#include "Draw.h"


int main() {

    InitWindow(MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE, "Defend The Spire");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawGrid();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}