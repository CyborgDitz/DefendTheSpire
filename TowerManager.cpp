#include "globals.h"
#include "raylib.h"

void ToggleTowerTile(Position& position)
{
 if (!InBounds(position))
  {
   return;
  }

 Tile& tile = grid[position.y][position.x];
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

}
void ClickTile() {
 Vector2 mousePosition = GetMousePosition();
 int x = mousePosition.x / (GetScreenWidth() / GRID_WIDTH);
 int y = mousePosition.y / (GetScreenHeight() / GRID_HEIGHT);

 Position clickedPosition = {x, y};


 if (InBounds(clickedPosition)) {

  ToggleTowerTile(clickedPosition);
 }
}
