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

struct Position {
    int x, y;

    bool operator<(const Position& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }

    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};
struct Tile {
    TileType type;
    Position position;
    int rows;
    int columns;
};



extern Tile grid[GRID_HEIGHT][GRID_WIDTH];
bool InBounds (Position position);
#endif //GLOBALS_H
