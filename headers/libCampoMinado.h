#ifndef LIB_CAMPO_MINADO
#define LIB_CAMPO_MINADO

#include "./Tile.h";

    void generateField();

    void generateBombs();

    void showField( Tile** field );//recebe matriz de tiles

    void showRevealedField( Tile** field );

    bool checkGameOver(); //se usuário clicou em uma bomba

    bool checkVictory(); //se usuário revelou todas as posições sem bomba


#endif