#include <chrono>

#include "gameInit.h"
#include "globals.h"
#include "raylib.h"
#include "TowerManager.h"
#include "Draw.h"
#include "Creeps.h"
int main() {
    double startTime = GetTime();
    InitWindow(GRID_WIDTH * TILE_SIZE, GRID_HEIGHT * TILE_SIZE, "Defend The Spire");

    InitializeGrid();
    Position startPosition{1, 1};

    float moveTimer = 0.0f;
    const float MOVE_TIMER = 0.1f; // Add this to define a move interval (e.g., 1 second)

    float spawnTimer = 1.0f;
    const float SPAWN_INTERVAL = .0f;

    float inputTimer = 0.0f;
    const float INPUT_INTERVAL = 0.0f;
    double endTime = GetTime();  // End timing
    printf("Game start execution time: %.6f seconds \n", endTime - startTime);
    while (!WindowShouldClose()) {
        double startTime = GetTime();  // Start timing
        float deltaTime = GetFrameTime();

        inputTimer += deltaTime;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && inputTimer >= INPUT_INTERVAL) {
            ClickTile();
            inputTimer = 0.0f;
            // Update creeps' path after clicking on a tile
            for (auto& creep : creeps) {
                for (int i = 0; i < 100; i++) {
                    BreadthFirstPath(creep.position);
                    creep.pathStep = 0;
                }
            }
        }

        if (spawnTimer >= SPAWN_INTERVAL) {
               for (int i = 0; i < 100; i++) {
                   /*
                   Gamestart execution time: 1.102305 seconds
                   Main execution time: 7.017532 seconds
                   Main execution time: 12.236588 seconds
                   Main execution time: 0.075890 seconds
                   */

                   /* trial 2: path move
                   Game start execution time: 1.053674 seconds
                   Main execution time: 9.559365 seconds
                   Main execution time: 8.857198 seconds
                   Main execution time: 0.121200 seconds
                   */

                   /* trial 3 : 50k spawns
                   Game start execution time: 1.055147 seconds
                   Main execution time: 46.627085 seconds
                   Main execution time: 46.102448 seconds
                   Main execution time: 0.448100 seconds
                   */
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
