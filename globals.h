#ifndef GLOBALS_H
#define GLOBALS_H

#define GRID_WIDTH 32
#define GRID_HEIGHT 32
#define TILE_SIZE 30.0f
#include <vector>
enum TileType //4b even with 5+ enums
 {
  EMPTY = 0,
  TOWER = 1,
    WALL = 2,
     SPIRE = 3,
      CREEP = 4,
  };

struct Position {
    int x; //4b
    int y;//4b

    bool operator<(const Position& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
//not members, no nytes
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};
struct Tile { //64b cacheline
    TileType type; // 4 b
    Position position; // 8b
    int rows;
    int columns;
};

extern Tile grid[GRID_HEIGHT][GRID_WIDTH];
bool InBounds (Position position);
#endif //GLOBALS_H
