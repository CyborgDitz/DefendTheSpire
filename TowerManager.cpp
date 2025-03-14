#include "globals.h"
#include "raylib.h"
bool InBounds(int x, int y) {
 return (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT);

}
void ToggleTowerTile(int x, int y)
{
 if (!InBounds(x,y))
  {
   return;
  }

 Tile& tile = grid[x][y];
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
 if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
  {
   Vector2 mousePosition = GetMousePosition();
   int x = mousePosition.x / MAP_WIDTH;
   int y = mousePosition.y / MAP_HEIGHT;

   ToggleTowerTile(x, y);
  }
}