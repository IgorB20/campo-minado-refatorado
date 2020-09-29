#ifndef LIB_CAMPO_MINADO
#define LIB_CAMPO_MINADO

#include "./Field.h"
#include "./Tile.h"
#include "./Game.h"
#include "./Position.h"

    void init(Game &game);

    void startMainLoop(Game &game);

    void generateField( Field &field );

    void generateBombs( Field &field );

    void setCoordinatesBombsAroundAmount( Field &field );

    void showField( Field field );

    void showRevealedField( Field field );

    void getUserInput();

    bool checkGameOver(); //se usuário clicou em uma bomba

    bool checkVictory(); //se usuário revelou todas as posições sem bomba


#endif