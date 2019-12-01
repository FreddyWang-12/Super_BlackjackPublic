#include "Card.h"
#include "Deck.h"
#include "Dice.h"
#include "Player.h"
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    Deck demoDeck;
    demoDeck.shuffle();

    Player demoPlayer;
    Player demoDealer;

    demoPlayer.bet();
    demoPlayer.drawCard(&demoDeck);
    demoDealer.drawCard(&demoDeck);
    demoPlayer.drawCard(&demoDeck);
    demoDealer.drawCard(&demoDeck);

    demoPlayer.printHand();
    cout << endl;
    demoDealer.printHand();
    cout << endl;

    if(demoPlayer.totalPoints() > 21 || demoPlayer.totalPoints() <= demoDealer.totalPoints()){
        demoPlayer.lose();
    }
    else{
        demoPlayer.win();
    }

    return 0;
}