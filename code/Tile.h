#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "ChessPiece.h"
using namespace sf;
using namespace std;

class Tile
{
    protected:
    Vector2f upperLeft;
    Vector2f lowerRight;
    Vector2f center;

    public:
    vector <ChessPiece> Defenders;
    Tile(Vector2f topLeft, Vector2f botRight);
};