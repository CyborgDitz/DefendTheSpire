#include "gameInit.h"
#include "globals.h"
#include "raylib.h"
#include "TowerManager.h"
#include "Draw.h"
#include "Creeps.h"

int main() {
    InitWindow(GRID_WIDTH * TILE_SIZE, GRID_HEIGHT * TILE_SIZE, "Defend The Spire");
    SetTargetFPS(60);  // Set to 60 FPS

    InitializeGrid();
    Position startPosition{1, 1};


   // SpawnCreep(startPosition);

    float spawnTimer = 0.0f;
    const float SPAWN_INTERVAL = 5.0f;

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        MoveCreeps(deltaTime);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            ClickTile();
        }

        spawnTimer += deltaTime;
        if (spawnTimer >= SPAWN_INTERVAL) {
            SpawnCreep(startPosition);
            spawnTimer = 0.0f;
        }

        if (IsKeyPressed(KEY_SPACE)) {
            BreadthFirstPath(startPosition);
        }

        DrawGame();
    }

    CloseWindow();
    return 0;
}