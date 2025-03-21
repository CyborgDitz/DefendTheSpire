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
        MoveCreeps(deltaTime);
        
        DrawGame();
    }
}