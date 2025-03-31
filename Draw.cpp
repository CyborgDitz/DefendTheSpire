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

  auto drawGameStart = std::chrono::high_resolution_clock::now();

  auto beginDrawingStart = std::chrono::high_resolution_clock::now();
  BeginDrawing();
  auto beginDrawingEnd = std::chrono::high_resolution_clock::now();

  auto clearBgStart = std::chrono::high_resolution_clock::now();
  ClearBackground(RAYWHITE);
  auto clearBgEnd = std::chrono::high_resolution_clock::now();

  DrawTiles();
  DrawCreeps();

  auto endDrawingStart = std::chrono::high_resolution_clock::now();
  EndDrawing();
  auto endDrawingEnd = std::chrono::high_resolution_clock::now();

  auto drawGameEnd = std::chrono::high_resolution_clock::now();

  std::cout << "  BeginDrawing Time: "
            << std::chrono::duration<double, std::milli>(beginDrawingEnd - beginDrawingStart).count()
            << " ms\n";

  std::cout << "  ClearBackground Time: "
            << std::chrono::duration<double, std::milli>(clearBgEnd - clearBgStart).count()
            << " ms\n";

  std::cout << "  EndDrawing Time: "
            << std::chrono::duration<double, std::milli>(endDrawingEnd - endDrawingStart).count()
            << " ms\n";

  std::cout << "  DrawGame Total Time: "
            << std::chrono::duration<double, std::milli>(drawGameEnd - drawGameStart).count()
            << " ms\n";
}