#ifndef DICE_H
#define DICE_H
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

// The dice class is a super blackjack feature where instead of drawing a card
// from the deck, the player can instead choose to roll a die for additional points
class Dice{
    public:
        int diceRoll();
        void print(int roll);
};

#endif