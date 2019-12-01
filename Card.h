#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <cstring>
using namespace std;

class Card{
    public:
        int getValue();
        string getCategory();
        void setValue(int value);
        void setCategory(string category);
        void print();
    private:
        int value;
        string category;
};

#endif