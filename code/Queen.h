#pragma once
#include "ChessPiece.h"

class Queen : public ChessPiece
{
    public:
    Queen(Vector2f pos, int color, Sprite sprite);
    bool isLegal(Vector2f testPos); //Try the override keyword later
};