#include <chrono>

#include "gameInit.h"
#include "globals.h"
#include "raylib.h"
#include "TowerManager.h"
#include "Draw.h"
#include "Creeps.h"
int main() {
    InitWindow(GRID_WIDTH * TILE_SIZE, GRID_HEIGHT * TILE_SIZE, "Defend The Spire");

    InitializeGrid();
    Position startPosition{1, 1};

    float moveTimer = 0.0f;
    const float MOVE_TIMER = 0.1f; // Add this to define a move interval (e.g., 1 second)

    float spawnTimer = 0.0f;
    const float SPAWN_INTERVAL = 0.0f;

    float inputTimer = 0.0f;
    const float INPUT_INTERVAL = 0.0f;

    while (!WindowShouldClose()) {
        double startTime = GetTime();  // Start timing
        float deltaTime = GetFrameTime();

        inputTimer += deltaTime;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && inputTimer >= INPUT_INTERVAL) {
            ClickTile();
            inputTimer = 0.0f;
            // Update creeps' path after clicking on a tile
            for (auto& creep : creeps) {
                BreadthFirstPath(creep.position);
                creep.pathStep = 0;
            }
        }

        if (spawnTimer >= SPAWN_INTERVAL) {
            for (int i = 0; i < 1000; i++) {   // Spawn 10k enemies per frame. Main execution time: 7.220024 seconds
                                                //   Main execution time: 10.894135 seconds, game cant be played until
                                                // Main execution time: 0.060903 seconds after game is playable
                                                //  Main execution time: 0.022677 seconds
                SpawnCreep(startPosition);
            }
            spawnTimer = 0.0f;
        }

        // Update moveTimer to accumulate time and call MoveCreeps when the time exceeds MOVE_TIMER
        moveTimer += deltaTime;
        if (moveTimer >= MOVE_TIMER) {

            MoveCreeps(deltaTime); // Move creeps only once per MOVE_TIMER seconds
            moveTimer = 0.0f; // Reset the move timer after calling MoveCreeps

        }

        DrawGame();
        double endTime = GetTime();  // End timing
         printf("Main execution time: %.6f seconds \n", endTime - startTime);
    }
    CloseWindow(); // Close window properly
}
