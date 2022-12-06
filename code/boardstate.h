#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "ChessPiece.h"
using namespace sf;
using namespace std;

class BoardState{
    public:
    vector<ChessPiece*> Board;
    int getTurn();
    int getBoardValue();
    private:
    int boardValue = 0;
    int turn = 0;
};
