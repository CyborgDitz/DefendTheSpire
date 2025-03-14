#include "game.h"


int main() {

    InitWindow(MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE, "Defend The Spire");

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            ClickTile();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawGrid();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}