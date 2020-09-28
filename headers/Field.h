#ifndef FIELD_H
#define FIELD_H
#include "./Tile.h"

struct Field{
   int lines;
   int columns;
   Tile** tiles; //matriz de Tiles
};

#endif