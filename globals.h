#ifndef GLOBALS_H
#define GLOBALS_H

#define GRID_WIDTH 17
#define GRID_HEIGHT 17
#define TILE_SIZE 32.0f
#include <vector>

enum TileType
 {
  EMPTY = 0,
  TOWER = 1,
    WALL = 2,
     SPIRE = 3,
      CREEP = 4,
  };

struct Tile
  {
  TileType type;
    int startY; int sizeY; int startX; int sizeX;
  };

extern Tile grid[GRID_HEIGHT][GRID_WIDTH];
bool InBounds (int y, int x);
#endif //GLOBALS_H
