#include "Draw.h"

#include <chrono>

#include "Raylib.h"
#include "globals.h"
#include "Creeps.h"
Color tileColor;
void DrawTiles() {
  for (int y = 0; y < GRID_HEIGHT; y++) {
    for (int x = 0; x < GRID_WIDTH; x++) {
      const Rectangle tileRect = { (x * TILE_SIZE), (y * TILE_SIZE), TILE_SIZE, TILE_SIZE };

      switch (grid[y][x].type) {
        case EMPTY:
          tileColor = RAYWHITE;
        break;
        case TOWER:
          tileColor = BLUE;
        break;
        case WALL:
          tileColor = BLACK;
        break;
        case SPIRE:
          tileColor = PINK;
        break;

        default:
          tileColor = RAYWHITE;
        break;
      }

      DrawRectangle(tileRect.x, tileRect.y, tileRect.width, tileRect.height, tileColor);

      DrawRectangleLines(tileRect.x, tileRect.y, tileRect.width, tileRect.height, LIGHTGRAY);
    }
  }
}
void DrawCreeps() {
  for (const Creep& creep : creeps) {
    DrawRectangle(creep.position.x * TILE_SIZE, creep.position.y * TILE_SIZE, TILE_SIZE, TILE_SIZE, RED);
  }
}
void DrawGame() {
  BeginDrawing();
  ClearBackground(RAYWHITE);
  DrawTiles();
  DrawCreeps();
  EndDrawing();

}