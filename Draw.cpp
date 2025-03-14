#include "Draw.h"


void DrawGrid() {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      Rectangle tileRect = { (x * TILE_SIZE), (y * TILE_SIZE), TILE_SIZE, TILE_SIZE };

      Color tileColor;
      switch (grid[y][x].type) {
        case EMPTY:
          tileColor = RAYWHITE;
        break;
        case TOWER:
          tileColor = BLUE;
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