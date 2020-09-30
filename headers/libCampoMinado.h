#ifndef LIB_CAMPO_MINADO
#define LIB_CAMPO_MINADO

#include "./Field.h"
#include "./Tile.h"
#include "./Game.h"
#include "./Position.h"
#include <iostream>
#include <time.h>
#include <string>

using namespace std;


    void init(Game &game);

    void startMainLoop(Game &game);
    
    void showFinalMessage(Game game,  string message);

    void generateField( Field &field );

    void generateBombs( Field &field );

    void setCoordinatesBombsAroundAmount( Field &field );

    void showField( Field field );

    void showRevealedField( Field field );

    void getUserInput(Position &position, Game game);

    bool validateUserInput(Position position, Game game);

    bool checkGameOver( Field field, Position position ); //se usuário clicou em uma bomba

    bool checkVictory(Game game); //se usuário revelou todas as posições sem bomba


#endif