#ifndef TILE_H
#define TILE_H

struct Tile{
    bool isBomb = false;
    bool revealed = false;
    int bombsAroundAmount = 0;
};

#endif