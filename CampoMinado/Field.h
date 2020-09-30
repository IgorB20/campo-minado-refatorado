#ifndef FIELD_H
#define FIELD_H
#include "./Tile.h"

struct Field{
   int lines;
   int columns;
   int bombsAmount;
   Tile tiles[100][100]; //matriz de Tiles
};

#endif
