#pragma once
#include "ChessPiece.h"

class Rook : public ChessPiece
{
    private:
    bool moved;

    public:
    Rook(Vector2f pos, int color, Sprite sprite);
    bool isLegal(Vector2f testPos); //Try the override keyword later
    bool hasMoved();
};