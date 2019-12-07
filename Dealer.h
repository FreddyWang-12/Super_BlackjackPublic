#ifndef DEALER_H
#define DEALER_H
#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include "Card.h"
#include "Deck.h"
#include "Dice.h"
using namespace std;

class Dealer{
    public:
        Dealer();
        void drawCard(Deck *deck);
        int totalPoints();
        void printHand();
        void showFirstCard();
        void resetHand(Deck *deck);
    private:
        stack<Card> hand;
        int pointValue;
};

#endif