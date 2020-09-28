#ifndef GAME_H
#define GAME_H
#include "./Field.h"

struct Game{
    int playsAmount = 0;
    bool endGame = false;
    Field field;
};

#endif
