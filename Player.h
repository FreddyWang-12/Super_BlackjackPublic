#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <cstring>
#include <queue>
#include "Card.h"
#include "Deck.h"
#include "Dice.h"
using namespace std;

class Player{
    public:
        Player();
        void bet();
        void drawCard(Deck *deck);
        int totalPoints();
        void rollDice();
        void win();
        void lose();
        void printHand();
    private:
        queue<Card> hand;
        int pointValue;
        int betValue;
        double bankBalance;
        Dice dice;
};

#endif
