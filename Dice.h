#ifndef DICE_H
#define DICE_H
#include "GamePiece.h"
using namespace std;

// The dice class is a super blackjack feature where instead of drawing a card
// from the deck, the player can instead choose to roll a die for additional points
class Dice : public GamePiece{
    public:
        int diceRoll();
        void print();
};

#endif