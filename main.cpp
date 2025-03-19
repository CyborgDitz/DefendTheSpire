#include "gameInit.h"
#include "globals.h"
#include "raylib.h"
#include "TowerManager.h"
#include "Draw.h"
#include "Creeps.h"

int main() {
    InitWindow(GRID_WIDTH * TILE_SIZE, GRID_HEIGHT * TILE_SIZE, "Defend The Spire");
    InitializeGrid();

    Position *startPosition = &creeps.front().position;
    Position *endPosition = &creeps.back().position;


    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            ClickTile();
        }

        DrawGame();
        if (IsKeyDown(KEY_SPACE)&& endPosition !=nullptr && startPosition !=nullptr) {
            BreathFirst(*startPosition);
        }

    }

    CloseWindow();
    return 0;
}
