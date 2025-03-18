#include "gameInit.h"
#include "globals.h"
#include "raylib.h"
#include "TowerManager.h"
#include "Draw.h"
#include "Creeps.h"

int main() {
    InitWindow(GRID_WIDTH * TILE_SIZE, GRID_HEIGHT * TILE_SIZE, "Defend The Spire");
    initializeGrid();

    Position* startPosition = nullptr;

    if (!enemies.empty()) {
        startPosition = &enemies.front().position;  // Get the first enemy's position
    }

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            ClickTile();
        }

        DrawGame();
        BreathFirst(*startPosition);
    }

    CloseWindow();
    return 0;
}
