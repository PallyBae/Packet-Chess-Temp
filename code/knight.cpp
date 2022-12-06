#include "Knight.h"
#include "ChessPiece.h"

using namespace sf;
using namespace std;

Knight::Knight(Vector2f pos, int passedColor, Sprite sprite) : ChessPiece(pos, passedColor){
    prevPos = pos; 
    position = pos;
    color = passedColor;
    value = 3;
    chessSprite = sprite;
}
bool Knight::isLegal(Vector2f testPos){
    if (abs(testPos.x - getLastPos().x == 2) && abs(testPos.y - getLastPos().y == 1) || (abs(testPos.x - getLastPos().x) == 1) && (abs(testPos.y - getLastPos().y) == 2)){
        return true;
    }
    else{
        return false;
    }
}

