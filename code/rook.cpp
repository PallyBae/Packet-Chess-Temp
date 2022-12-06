#include "Rook.h"
#include "ChessPiece.h"

using namespace sf;
using namespace std;


bool Rook::hasMoved(){
    if (moved == true || (getPosition() != getLastPos())){
        moved = true;
        return true;
    }
    else{
        return false;
    }
}

bool Rook::isLegal(Vector2f testPos){
    if (getLastPos().x == testPos.x || getLastPos().y == testPos.y){
        return true;
    }
}
Rook::Rook(Vector2f pos, int passedColor, Sprite sprite)  : ChessPiece(pos, passedColor){
    prevPos = pos;
    position = pos;
    color = passedColor;
    value = 5;
    chessSprite = sprite;
}