#ifndef GAMEPIECE_H
#define GAMEPIECE_H
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

// Represents the dice and card game pieces
class GamePiece{
    public:
        void print();
    protected:
        int value;
};

#endif