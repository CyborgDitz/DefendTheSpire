#ifndef GLOBALS_H
#define GLOBALS_H

#define MAP_WIDTH 16
#define MAP_HEIGHT 16
#define TILE_SIZE 32.0f
#include <vector>
//todo tilemap 0 is empty, 1 is tower
//todo 1 click on tile to change to 1

//todo functions: draw tilemap, place tower(bool is occupied), get mouse click on tile
struct Position
 {
    int x, y;
 };
struct Node
 {
  Position position;
  };
enum TileType
 {
  EMPTY = 0,
  TOWER = 1,
    WALL = 2,
     SPIRE = 3,
  };

struct Tile
  {
  TileType type;
  Position position;
  };
extern std::vector<std::vector<Tile>> grid;
void initializeGrid();
#endif //GLOBALS_H
