#include "Tile.h"
#include "ChessPiece.h"

using namespace sf;
using namespace std;

Tile::Tile(Vector2f topLeft, Vector2f botRight)
{
    upperLeft = topLeft;
    lowerRight = botRight;
    Vector2f tempCenter((topLeft.x + botRight.x)/2, (topLeft.y + botRight.y)/2);
    center = tempCenter;
}