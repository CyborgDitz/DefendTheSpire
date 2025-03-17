#include "globals.h"
#include "raylib.h"
bool InBounds(int x, int y) {
 return (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT);
}
void ToggleTowerTile(int x, int y)
{
 if (!InBounds(x,y))
  {
   return;
  }

 Tile& tile = grid[y][x];
 switch (tile.type)
 {
  case EMPTY:
   tile.type = TOWER;
  break;
  case TOWER:
   tile.type = EMPTY;
  break;
  default:
   break;
 }
// Draw updates tile color later in main
}

void ClickTile() {
 Vector2 mousePosition = GetMousePosition();
 int x = mousePosition.x / (GetScreenWidth() / GRID_WIDTH);
 int y = mousePosition.y / (GetScreenHeight() / GRID_HEIGHT);

 if (InBounds(x, y)) ToggleTowerTile(x, y);
}

