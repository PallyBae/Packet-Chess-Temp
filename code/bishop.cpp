#include "Bishop.h"
#include "ChessPiece.h"

using namespace sf;
using namespace std;

Bishop::Bishop(Vector2f pos, int passedColor, Sprite sprite) : ChessPiece(pos, passedColor){
    prevPos = pos;
    color = passedColor;
    position = pos;
    value = 3;
    chessSprite = sprite;

}

bool Bishop::isLegal(Vector2f testPos){
    if (abs(testPos.x) == abs(testPos.y)){
        return true;
    }
    else{
        return false;
    }
}