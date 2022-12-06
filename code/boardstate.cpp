#include "boardstate.h"
#include "ChessPiece.h"

using namespace sf;
using namespace std;

int BoardState::getBoardValue(){
    for (int i = 0; i < 63; i++){
        boardValue += Board[i]->getValue(); 
    }
    return boardValue;
}
int BoardState::getTurn(){
    return turn;
}
