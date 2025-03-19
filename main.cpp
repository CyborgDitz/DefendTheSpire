#include "gameInit.h"
#include "globals.h"
#include "raylib.h"
#include "TowerManager.h"
#include "Draw.h"
#include "Creeps.h"

int main() {
    InitWindow(GRID_WIDTH * TILE_SIZE, GRID_HEIGHT * TILE_SIZE, "Defend The Spire");
    InitializeGrid();
    Position start(2,2);

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            ClickTile();
        }
        if (IsKeyPressed(KEY_UP))    MoveCreeps(0, -1);
        if (IsKeyPressed(KEY_DOWN))  MoveCreeps(0, 1);
        if (IsKeyPressed(KEY_LEFT))  MoveCreeps(-1, 0);
        if (IsKeyPressed(KEY_RIGHT)) MoveCreeps(1, 0);
        if (IsKeyDown(KEY_SPACE)){
            BreadthFirst(start);
        }
        DrawGame();
    }
    CloseWindow();
    return 0;
}
