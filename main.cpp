#include "gameInit.h"
#include "globals.h"
#include "raylib.h"
#include "TowerManager.h"
#include "Draw.h"
#include "Creeps.h"

int main() {
    InitWindow(GRID_WIDTH * TILE_SIZE, GRID_HEIGHT * TILE_SIZE, "Defend The Spire");
    InitializeGrid();

    Position* startPosition;

    if (!creeps.empty()) {
        startPosition = &creeps.front().position;
    }

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            ClickTile();
        }

        DrawGame();
        if (startPosition) {
            BreathFirst(*startPosition);
        }

    }

    CloseWindow();
    return 0;
}
