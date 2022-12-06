#pragma once
#include "ChessPiece.h"

class King : public ChessPiece
{
    private:
    bool moved; //the king piece has moved only if current pos is different from lastPos
    bool inCheck = false;

    public:
    King(Vector2f pos, int color, Sprite sprite);
    bool isLegal(Vector2f testPos); //Try the override keyword later
    bool hasMoved();
};