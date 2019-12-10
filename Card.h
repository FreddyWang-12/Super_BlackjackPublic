#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <cstring>
#include "GamePiece.h"
using namespace std;

class Card : public GamePiece{
    public:
        int getValue();
        string getCategory();
        string getCardType();
        void setValue(int value);
        void setCategory(string category);
        void setCardType(string cardType);
        void print();
    private:
        string cardType;
        string category;
};

#endif