#ifndef LIB_CAMPO_MINADO
#define LIB_CAMPO_MINADO

#include "./Field.h"
#include "./Tile.h"

    void init();

    void generateField( Field** field ); //inicializa a matriz de tiles

    void generateBombs();

    void showField( Tile** field );//recebe matriz de tiles

    void showRevealedField( Tile** field );

    bool checkGameOver(); //se usuário clicou em uma bomba

    bool checkVictory(); //se usuário revelou todas as posições sem bomba


#endif
