#include "gameInit.h"
#include "globals.h"
#include "raylib.h"
#include "TowerManager.h"
#include "Draw.h"
#include "Creeps.h"
int main() {
    InitWindow(GRID_WIDTH * TILE_SIZE, GRID_HEIGHT * TILE_SIZE, "Defend The Spire");
    SetTargetFPS(60);

    InitializeGrid();
    Position startPosition{1, 1};

    float moveTimer = 0.0f;
    const float MOVE_TIMER = 1.0f; // Add this to define a move interval (e.g., 1 second)

    float spawnTimer = 0.0f;
    const float SPAWN_INTERVAL = 5.0f;

    float inputTimer = 0.0f;
    const float INPUT_INTERVAL = 0.5f;

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        inputTimer += deltaTime;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && inputTimer >= INPUT_INTERVAL) {
            ClickTile();
            inputTimer = 0.0f;
            // Update creeps' path after clicking on a tile
            for (auto& creep : creeps) {
                creep.path = BreadthFirstPath(creep.position);
                creep.pathStep = 0;
            }
        }

        spawnTimer += deltaTime;
        if (spawnTimer >= SPAWN_INTERVAL) {
            SpawnCreep(startPosition);
            spawnTimer = 0.0f;
        }

        // Update moveTimer to accumulate time and call MoveCreeps when the time exceeds MOVE_TIMER
        moveTimer += deltaTime;
        if (moveTimer >= MOVE_TIMER) {
            MoveCreeps(deltaTime); // Move creeps only once per MOVE_TIMER seconds
            moveTimer = 0.0f; // Reset the move timer after calling MoveCreeps
        }

        DrawGame();
    }

    CloseWindow(); // Close window properly
}
