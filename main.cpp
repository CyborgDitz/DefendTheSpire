#include "gameInit.h"
#include "globals.h"
#include "raylib.h"
#include "TowerManager.h"
#include "Draw.h"


int main() {

    InitWindow(GRID_WIDTH * TILE_SIZE, GRID_HEIGHT * TILE_SIZE, "Defend The Spire");
    initializeGrid();
    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            ClickTile();
        }

        DrawGame();
    }

    CloseWindow();
    return 0;
}
