#pragma once
#include "ChessPiece.h"

class Pawn : public ChessPiece
{
    private:
    bool moved;
    bool doublemoved;

    public:
    Pawn(Vector2f pos, int color, Sprite sprite);
    bool hasMoved();
    bool hasDoubleMoved();
    bool isLegal(Vector2f testPos); //Try the override keyword later
};