#include "Pawn.h"
#include "ChessPiece.h"

using namespace sf;
using namespace std;


bool Pawn::hasMoved(){
    if (moved == true || (getPosition() != getLastPos())){
        return true;
    }
    else{
        return false;
    }
}
bool Pawn::isLegal(Vector2f testPos){
    if (abs(testPos.x - getLastPos().x) > 1 || (abs(testPos.y - getLastPos().y) > 2 ||abs(testPos.y - getLastPos().y) < 1)){
        return false;
    }
    else if (abs(testPos.x - getLastPos().x) >= 0 && abs(testPos.x - getLastPos().x) <= 1 && (abs(testPos.y - getLastPos().y) == 1 || (abs(testPos.y - getLastPos().y) == 2 && moved == false))){
        return true;
    }
}

Pawn::Pawn(Vector2f pos, int passedColor, Sprite sprite) : ChessPiece(pos, passedColor){
    prevPos = pos;
    color = passedColor;
    position == pos;
    value = 1;
    chessSprite = sprite;
}

bool Pawn::hasDoubleMoved(){
    if (position.y - prevPos.y == 2){
        doublemoved = true;
        return true;
    }
    else{
        return false;
    }
}