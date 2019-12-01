#include "Card.h"
#include "Deck.h"
#include "Dice.h"
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    Deck demo;
    demo.shuffle();
    demo.print();

    Dice two;
    for(int x = 0; x < 5; x++){
        cout << two.diceRoll() << endl;
    }

    return 0;
}