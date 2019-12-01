#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include "Card.h"
using namespace std;

class Deck{
    public:
        Deck();
        void shuffle();
        void print();
        Card draw();
        void putBackCard(Card putBack);
    private:
        queue<Card> deck;
};

#endif