#include "Queen.h"
#include <cmath>

using namespace sf;


bool Queen::isLegal(Vector2f testPos){
    if (abs(testPos.x) == abs(testPos.y) || (getLastPos().x == testPos.x || getLastPos().y == testPos.y)){
        return true;
    }
    else{
        return false;
    }
}

Queen::Queen(Vector2f pos, int passedColor, Sprite sprite) : ChessPiece(pos, passedColor){
    prevPos = pos;
    position = pos;
    color = passedColor;
    value = 9;
    chessSprite = sprite;
}