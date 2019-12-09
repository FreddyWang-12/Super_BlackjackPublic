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
        void setBankAccount(int bankBalance);
        int getBankAccount();
        void bet();
        void drawCard(Deck *deck);
        int totalPoints();
        void rollDice();
        void win(Deck *deck);
        void lose(Deck *deck);
        void tie(Deck *deck);
        void printHand();
    private:
        stack<Card> hand;
        int pointValue;
        int betValue;
        double bankBalance;
        Dice dice;
};

#endif
