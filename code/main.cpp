// Packet Chess Game
// Creators: Matthew Craig, Yousif Alnomani
// CISP 400


#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "boardstate.h"
#include "ChessPiece.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Sprites.h"
#include "Tile.h"
using namespace sf;
using namespace std;

void boardLoaderBlack(vector<ChessPiece*> &CHPV )
{
    // Row One
    Rook* RookBlackLeft = new Rook(Vector2f(0,0), 1, BlackRookSprite);
    Knight* KnightBlackLeft = new Knight(Vector2f(1,0), 1, BlackKnightSprite);
    Bishop* BishopBlackLeft = new Bishop(Vector2f(2,0), 1, BlackBishopSprite);
    Queen* QueenBlack = new Queen(Vector2f(3,0), 1, BlackQueenSprite);
    King* KingBlack = new King(Vector2f(4,0), 1, BlackKingSprite);
    Bishop* BishopBlackRight = new Bishop(Vector2f(5,0), 1, BlackBishopSprite);
    Knight* KnightBlackRight = new Knight(Vector2f(6,0), 1, BlackKnightSprite);
    Rook* RookBlackRight = new Rook(Vector2f(7,0), 1, BlackRookSprite);
    // Row Two
    Pawn* PawnBlackZero = new Pawn(Vector2f(0,1), 1, BlackPawnSprite);
    Pawn* PawnBlackOne = new Pawn(Vector2f(1,1), 1, BlackPawnSprite);
    Pawn* PawnBlackTwo = new Pawn(Vector2f(2,1), 1, BlackPawnSprite);
    Pawn* PawnBlackThree = new Pawn(Vector2f(3,1), 1, BlackPawnSprite);
    Pawn* PawnBlackFour = new Pawn(Vector2f(4,1), 1, BlackPawnSprite);
    Pawn* PawnBlackFive = new Pawn(Vector2f(5,1), 1, BlackPawnSprite);
    Pawn* PawnBlackSix = new Pawn(Vector2f(6,1), 1, BlackPawnSprite);
    Pawn* PawnBlackSeven = new Pawn(Vector2f(7,1), 1, BlackPawnSprite);
    // Add To Vector
    CHPV.push_back(RookBlackLeft);
    CHPV.push_back(KnightBlackLeft);
    CHPV.push_back(BishopBlackLeft);
    CHPV.push_back(QueenBlack);
    CHPV.push_back(KingBlack);
    CHPV.push_back(BishopBlackRight);
    CHPV.push_back(KnightBlackRight);
    CHPV.push_back(RookBlackRight);
    CHPV.push_back(PawnBlackZero);
    CHPV.push_back(PawnBlackOne);
    CHPV.push_back(PawnBlackTwo);
    CHPV.push_back(PawnBlackThree);
    CHPV.push_back(PawnBlackFour);
    CHPV.push_back(PawnBlackFive);
    CHPV.push_back(PawnBlackSix);
    CHPV.push_back(PawnBlackSeven);
}

void boardLoaderWhite(vector<ChessPiece*> &CHPV )
{
    // Row Seven
    Rook* RookWhiteLeft = new Rook(Vector2f(0,7), 0, WhiteRookSprite);
    Knight* KnightWhiteLeft = new Knight(Vector2f(1,7), 0, WhiteKnightSprite);
    Bishop* BishopWhiteLeft = new Bishop(Vector2f(2,7), 0, WhiteBishopSprite);
    Queen* QueenWhite = new Queen(Vector2f(3,7), 0, WhiteQueenSprite);
    King* KingWhite = new King(Vector2f(4,7), 0, WhiteKingSprite);
    Bishop* BishopWhiteRight = new Bishop(Vector2f(5,7), 0, WhiteBishopSprite);
    Knight* KnightWhiteRight = new Knight(Vector2f(6,7), 0, WhiteKnightSprite);
    Rook* RookWhiteRight = new Rook(Vector2f(7,7), 0, WhiteRookSprite);
    // Row Eight
    Pawn* PawnWhiteZero = new Pawn(Vector2f(0,6), 0, WhitePawnSprite);
    Pawn* PawnWhiteOne = new Pawn(Vector2f(1,6), 0, WhitePawnSprite);
    Pawn* PawnWhiteTwo = new Pawn(Vector2f(2,6), 0, WhitePawnSprite);
    Pawn* PawnWhiteThree = new Pawn(Vector2f(3,6), 0, WhitePawnSprite);
    Pawn* PawnWhiteFour = new Pawn(Vector2f(4,6), 0, WhitePawnSprite);
    Pawn* PawnWhiteFive = new Pawn(Vector2f(5,6), 0, WhitePawnSprite);
    Pawn* PawnWhiteSix = new Pawn(Vector2f(6,6), 0, WhitePawnSprite);
    Pawn* PawnWhiteSeven = new Pawn(Vector2f(7,6), 0, WhitePawnSprite);
    // Add To Vector
    CHPV.push_back(RookWhiteLeft);
    CHPV.push_back(KnightWhiteLeft);
    CHPV.push_back(BishopWhiteLeft);
    CHPV.push_back(QueenWhite);
    CHPV.push_back(KingWhite);
    CHPV.push_back(BishopWhiteRight);
    CHPV.push_back(KnightWhiteRight);
    CHPV.push_back(RookWhiteRight);
    CHPV.push_back(PawnWhiteZero);
    CHPV.push_back(PawnWhiteOne);
    CHPV.push_back(PawnWhiteTwo);
    CHPV.push_back(PawnWhiteThree);
    CHPV.push_back(PawnWhiteFour);
    CHPV.push_back(PawnWhiteFive);
    CHPV.push_back(PawnWhiteSix);
    CHPV.push_back(PawnWhiteSeven);
}

void boardLoader(vector<ChessPiece*> &CHPV)
{
    boardLoaderBlack(CHPV);
    boardLoaderWhite(CHPV);
}

void tileLoaderTopQuarter(vector<Tile*> &TV)
{
    float windowScale = 0.8f;
    int windowWidth = VideoMode::getDesktopMode().width*windowScale;
    int windowHeight = VideoMode::getDesktopMode().height*windowScale;
    int distBoardMidToTopLeft = 376;
    int tileSideLength = 93;

    //First Justfies to the center of the screen which is the center of the chess board, then to the top left of the chess board, then to the necessary positions of the tiles. This is done to keep tile size and position consistant because the chess board sprite will also always be consistant and in the center of the screen.
    Tile* t0 = new Tile(Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*0, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*0), Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*1, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*1));// Tile (0,0)
    Tile* t1 = new Tile(Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*1, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*0), Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*2, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*1));// Tile (1,0)
    Tile* t2 = new Tile(Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*2, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*0), Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*3, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*1));// Tile (2,0)
    Tile* t3 = new Tile(Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*3, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*0), Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*4, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*1));// Tile (3,0)
    Tile* t4 = new Tile(Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*4, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*0), Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*5, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*1));// Tile (4,0)
    Tile* t5 = new Tile(Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*5, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*0), Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*6, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*1));// Tile (5,0)
    Tile* t6 = new Tile(Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*6, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*0), Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*7, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*1));// Tile (6,0)
    Tile* t7 = new Tile(Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*7, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*0), Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*8, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*1));// Tile (7,0)
    Tile* t8 = new Tile(Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*0, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*0), Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*1, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*3));// Tile (0,1)
    Tile* t9 = new Tile(Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*1, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*0), Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*2, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*3));// Tile (1,1)
    Tile* t10 = new Tile(Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*2, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*0), Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*3, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*3));// Tile (2,1)
    Tile* t11 = new Tile(Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*3, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*0), Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*4, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*3));// Tile (3,1)
    Tile* t12 = new Tile(Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*4, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*0), Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*5, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*3));// Tile (4,1)
    Tile* t13 = new Tile(Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*5, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*0), Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*6, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*3));// Tile (5,1)
    Tile* t14 = new Tile(Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*6, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*0), Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*7, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*3));// Tile (6,1)
    Tile* t15 = new Tile(Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*7, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*0), Vector2f(windowWidth*0.5f - distBoardMidToTopLeft + tileSideLength*8, windowHeight*0.5f - distBoardMidToTopLeft + tileSideLength*3));// Tile (7,1)

    TV.push_back(t0);
    TV.push_back(t1);
    TV.push_back(t2);
    TV.push_back(t3);
    TV.push_back(t4);
    TV.push_back(t5);
    TV.push_back(t6);
    TV.push_back(t7);
    TV.push_back(t8);
    TV.push_back(t9);
    TV.push_back(t10);
    TV.push_back(t11);
    TV.push_back(t12);
    TV.push_back(t13);
    TV.push_back(t14);
    TV.push_back(t15);
}

void boardDestroyer(vector<ChessPiece*> &CHPV)
{
    for(int i = 0; i < CHPV.size(); i++)
    {
        delete CHPV.at(i);
        CHPV.erase(CHPV.begin() + i);
    }
}

int closestTileCalculator(vector<Tile*> TV, vector<ChessPiece*> ChessVect, int chessPieceNum)
{
    int closestTile = 0;
    float distanceSquare = 0;
    float smallestSquare = 0;
    for (int i = 1; i < TV.size(); i++)
    {
        // Finds the Square of the distance between the sprite and the center of the Tile
        distanceSquare = (pow((ChessVect[chessPieceNum]->chessSprite.getPosition().x - TV[i]->getCenter().x), 2) + pow((ChessVect[chessPieceNum]->chessSprite.getPosition().y - TV[i]->getCenter().y), 2));
        smallestSquare = (pow((ChessVect[chessPieceNum]->chessSprite.getPosition().x - TV[closestTile]->getCenter().x), 2) + pow((ChessVect[chessPieceNum]->chessSprite.getPosition().y - TV[closestTile]->getCenter().y), 2));
        if(distanceSquare < smallestSquare)
        {
            closestTile = i;
        }
    }

    return closestTile;
}

int main(){

    // Window Management
    float windowScale = 1.0f;
    int currentWindowWidth = VideoMode::getDesktopMode().width*windowScale;
    int currentWindowHeight = VideoMode::getDesktopMode().height*windowScale;
    VideoMode desktop(currentWindowWidth, currentWindowHeight);
    float aspect_ratio = currentWindowHeight / static_cast<float>(currentWindowWidth);
    RenderWindow window(desktop, "Packet Chess", Style::Default);

    // Text Management
    const int TB_Align_W = 2;
    const int TB_Align_H = 7;

    Font font;
    font.loadFromFile("fonts/SebastianSerifNbp-7weB.ttf");
    Text titleScreen;
    titleScreen.setFont(font);
    titleScreen.setPosition({currentWindowWidth*0.5f, currentWindowHeight*0.4f});
    const int TB_BackBorder = 5;
    RectangleShape textBoxBg;
    textBoxBg.setFillColor(Color(0,0,0,127));
    textBoxBg.setPosition({titleScreen.getPosition().x - TB_Align_W - TB_BackBorder, titleScreen.getPosition().y + TB_Align_H - TB_BackBorder });

    //Chess Board
    Texture ChessBoardTexture;
    ChessBoardTexture.loadFromFile("packet Chess Sprites/Chess Board.png");
    Sprite ChessBoardSprite;
    ChessBoardSprite.setTexture(ChessBoardTexture);
    const int chessBoardScale = 1;
    ChessBoardSprite.setOrigin((ChessBoardSprite.getLocalBounds().width)/2, (ChessBoardSprite.getLocalBounds().height)/2);
    ChessBoardSprite.setPosition({currentWindowWidth*0.5f, currentWindowHeight*0.5f});
    ChessBoardSprite.setScale(chessBoardScale, chessBoardScale);

    WhiteKingTexture.loadFromFile("packet Chess Sprites/White_King.png");
    BlackKingTexture.loadFromFile("packet Chess Sprites/Black_King.png");
    WhiteQueenTexture.loadFromFile("packet Chess Sprites/White_Queen.png");
    BlackQueenTexture.loadFromFile("packet Chess Sprites/Black_Queen.png");
    WhiteBishopTexture.loadFromFile("packet Chess Sprites/White_Bishop.png");
    BlackBishopTexture.loadFromFile("packet Chess Sprites/Black_Bishop.png");
    WhiteKnightTexture.loadFromFile("packet Chess Sprites/White_Knight.png");
    BlackKnightTexture.loadFromFile("packet Chess Sprites/Black_Knight.png");
    WhiteRookTexture.loadFromFile("packet Chess Sprites/White_Rook.png");
    BlackRookTexture.loadFromFile("packet Chess Sprites/Black_Rook.png");
    WhitePawnTexture.loadFromFile("packet Chess Sprites/White_Pawn.png");
    WhitePawnTexture.loadFromFile("packet Chess Sprites/Black_Pawn.png");

    WhiteKingSprite.setTexture(WhiteKingTexture);
    BlackKingSprite.setTexture(BlackKingTexture);
    WhiteQueenSprite.setTexture(WhiteQueenTexture);
    BlackQueenSprite.setTexture(BlackQueenTexture);
    WhiteBishopSprite.setTexture(WhiteBishopTexture);
    BlackBishopSprite.setTexture(BlackBishopTexture);
    WhiteKnightSprite.setTexture(WhiteKnightTexture);
    BlackKnightSprite.setTexture(BlackKnightTexture);
    WhiteRookSprite.setTexture(WhiteRookTexture);
    BlackRookSprite.setTexture(BlackRookTexture);
    WhitePawnSprite.setTexture(WhitePawnTexture);
    BlackPawnSprite.setTexture(BlackPawnTexture);

    const int chessPieceScale = 2;

    WhiteKingSprite.setScale(chessPieceScale, chessPieceScale);
    BlackKingSprite.setScale(chessPieceScale, chessPieceScale);
    WhiteQueenSprite.setScale(chessPieceScale, chessPieceScale);
    BlackQueenSprite.setScale(chessPieceScale, chessPieceScale);
    WhiteBishopSprite.setScale(chessPieceScale, chessPieceScale);
    BlackBishopSprite.setScale(chessPieceScale, chessPieceScale);
    WhiteKnightSprite.setScale(chessPieceScale, chessPieceScale);
    BlackKnightSprite.setScale(chessPieceScale, chessPieceScale);
    WhiteRookSprite.setScale(chessPieceScale, chessPieceScale);
    BlackRookSprite.setScale(chessPieceScale, chessPieceScale);
    WhitePawnSprite.setScale(chessPieceScale, chessPieceScale);
    BlackPawnSprite.setScale(chessPieceScale, chessPieceScale);




    /*----------------------------------*\
    **************************************
    |___|****                    ****|___|
    !!!!!***                      ***!!!!!
    |___|**     Main Game Loop     **|___|
    !!!!!***                      ***!!!!!
    |___|****                    ****|___|
    **************************************
    \*----------------------------------*/

    while(window.isOpen())
    {

        /*----------------------------------------*\
        ********************************************
        |___|****                          ****|___|
        !!!!!***                            ***!!!!!
        |___|**     Update Scene Segment     **|___|
        !!!!!***                            ***!!!!!
        |___|****                          ****|___|
        ********************************************
        \*----------------------------------------*/

        enum Mode
        {
            TITLE, MULTIPLAYER, SINGLEPLAYER, PUZZLE, ONLINE_MP
        };

        enum State
        {
            PLAYING, PAUSED, END
        };

        enum MouseState
        {
            Holding, Released
        };

        Mode gameMode = MULTIPLAYER;
        State gameState = PLAYING;

        while(gameMode == MULTIPLAYER && window.isOpen())
        {
            titleScreen.setString("Packet Chess!!");

            Event event;

            // TITLE
            const int titleSizeMult = 2;
            titleScreen.setPosition({currentWindowWidth*0.5f, currentWindowHeight*0.05f});
            titleScreen.setOrigin({(titleScreen.getLocalBounds().width)/2, (titleScreen.getLocalBounds().height)/2 });
            titleScreen.setScale(titleSizeMult, titleSizeMult);
            textBoxBg.setPosition({titleScreen.getPosition().x - TB_Align_W - TB_BackBorder, titleScreen.getPosition().y + TB_Align_H - TB_BackBorder });
            textBoxBg.setSize({titleScreen.getLocalBounds().width + TB_BackBorder*2 , titleScreen.getLocalBounds().height + TB_BackBorder*2});
            textBoxBg.setOrigin({(titleScreen.getLocalBounds().width)/2, (titleScreen.getLocalBounds().height)/2});
            textBoxBg.setScale(titleSizeMult, titleSizeMult);

            // GAME INITIALIZATION
            BoardState BoardZero;
            boardLoader(BoardZero.Board);
            Vector2i mousePosition;
            bool mouseButtonHolding = false;
            bool clipTime = false;
            int chessPieceLocation = 0;
            vector <Tile*> boardTiles;
            tileLoaderTopQuarter(boardTiles);

            // Sound
            Music music;
            if (!music.openFromFile("sounds/packetchessbanger.wav"))
                return -1;
            music.setVolume(50);
            music.play();

            // TEST TRASH
            BoardZero.Board[0]->chessSprite.setPosition(50,50);
            
            
            while(gameState == PLAYING && window.isOpen())
            {

                while(window.pollEvent(event))
                {
                    switch(event.type)
                    {
                        case Event::Closed:
                        {
                            window.close();
                            break;

                        }

                        case Event::KeyPressed:
                        {
                            if (Keyboard::isKeyPressed(Keyboard::Escape))
                                window.close();
                            break;
                        }

                        //Mouse Button Press Event Stuff
                        
                        case Event::MouseButtonPressed:
                        {
                            if(event.mouseButton.button == Mouse::Left)
                            {
                                mouseButtonHolding = true;
                            }
                            
                            for(int i = 0; i < BoardZero.Board.size() - 1; i++)
                            {
                                if(Mouse::getPosition().x >= (BoardZero.Board[i]->chessSprite.getPosition().x + 25) && Mouse::getPosition().x < (BoardZero.Board[i]->chessSprite.getPosition().x + BoardZero.Board[i]->chessSprite.getLocalBounds().width + 25))
                                {
                                    if(Mouse::getPosition().y >= ((BoardZero.Board[i]->chessSprite.getPosition().y) + 90) && Mouse::getPosition().y < ((BoardZero.Board[i]->chessSprite.getPosition().y + BoardZero.Board[i]->chessSprite.getLocalBounds().height) + 90))
                                    {
                                        chessPieceLocation = i;
                                    }
                                }
                            }
                            //mousePosition = Mouse::getPosition();
                            break;
                        }

                        case Event::MouseButtonReleased:
                        {
                            if(event.mouseButton.button == Mouse::Left)
                            {
                                mouseButtonHolding = false;
                                clipTime = true;
                            }                            
                        }


                        

                        //Mouse Move Event Stuff

                        default:
                            break;
                    }
                }

                /*----------------------------------------*\
                ********************************************
                |___|****                          ****|___|
                !!!!!***                            ***!!!!!
                |___|**     Update Scene Segment     **|___|
                !!!!!***                            ***!!!!!
                |___|****                          ****|___|
                ********************************************
                \*----------------------------------------*/
                
                //!!!!!!!!
                //!!!!!!!!
                //!!!!!!!!
                //!!!!!!!! SWAP CHESS PIECE LOCATION != -1 FOR A DISTANCE CHECKER TO SEE IF THE DISTANCE IS ABSURD
                //!!!!!!!!
                //!!!!!!!!
                //!!!!!!!!
                if(mouseButtonHolding == true && chessPieceLocation != -1)
                {
                    BoardZero.Board[chessPieceLocation]->chessSprite.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);
                    BoardZero.Board[0]->chessSprite.setPosition(BoardZero.Board[0]->chessSprite.getPosition().x - 50, BoardZero.Board[0]->chessSprite.getPosition().y - 100);
                }
                else if(mouseButtonHolding == false && clipTime == true)
                {
                    // Clip the ChessPiece position to the nearest board tile
                    // Find Closest Tile
                    int nearestTile = closestTileCalculator(boardTiles, BoardZero.Board, chessPieceLocation);
                    // Set Sprite to Tile Position
                    BoardZero.Board[chessPieceLocation]->chessSprite.setPosition(boardTiles[nearestTile]->getCenter().x - 50, boardTiles[nearestTile]->getCenter().y - 50);
                    // BoardZero.Board[0]->chessSprite.setPosition()
                    //cleanup
                    chessPieceLocation = 0;
                    clipTime = false;
                }

                /*--------------------------------------*\
                ******************************************
                |___|****                        ****|___|
                !!!!!***                          ***!!!!!
                |___|**     Draw Scene Segment     **|___|
                !!!!!***                          ***!!!!!
                |___|****                        ****|___|
                ******************************************
                \*--------------------------------------*/

                window.clear(sf::Color(50, 50, 50, 255));

                window.draw(textBoxBg);
                window.draw(titleScreen);

                // Board
                window.draw(ChessBoardSprite);
                window.draw(BoardZero.Board[0]->chessSprite);

                RectangleShape tempRect(Vector2f(5,5));
                tempRect.setFillColor(Color::Blue);
                for (int i = 0; i < 16; i++)
                {
                    tempRect.setPosition(Vector2f(boardTiles[i]->getCenter().x, boardTiles[i]->getCenter().y));
                    window.draw(tempRect);
                }
                

                // Display
                window.display();
            }
            
            boardDestroyer(BoardZero.Board);
        }
    }

    return 0;

}