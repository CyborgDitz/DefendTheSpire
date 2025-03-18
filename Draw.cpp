#include "Draw.h"
#include "Raylib.h"
#include "globals.h"
#include "Creeps.h"
void DrawTiles() {
  for (int y = 0; y < GRID_HEIGHT; y++) {
    for (int x = 0; x < GRID_WIDTH; x++) {
      const Rectangle tileRect = { (x * TILE_SIZE), (y * TILE_SIZE), TILE_SIZE, TILE_SIZE };

      Color tileColor;
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
        case CREEP:
          tileColor = RED;
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
bool isBGCleared;
void DrawGame() {
  BeginDrawing();
  if (!isBGCleared) {
    ClearBackground(RAYWHITE);
    std::cout<<"BG cleared!" <<std::endl;
   isBGCleared = true;
  }
  DrawTiles();
  EndDrawing();
}