#include <iostream>
#include <cstring>
#include <queue>
#include "Card.h"
#include "Deck.h"
#include "Dice.h"
#include "Dealer.h"
using namespace std;

Dealer::Dealer(){
    pointValue = 0;
}

void Dealer::drawCard(Deck *deck){
    Card temp = deck->draw();
    if(temp.getCategory().substr(0, 3) == "Ace"){
        temp.setValue(11);
    }
    pointValue += temp.getValue();
    hand.push(temp);
}

int Dealer::totalPoints(){
    return pointValue;
}

void Dealer::printHand(){
    queue<Card> temp = hand;
    for(int i = 0; i <= temp.size(); i++){
        Card first = temp.front();
        first.print();
        temp.pop();
    }
    cout << "Total Points: " << pointValue << endl;
}

void Dealer::resetHand(Deck *deck){
    for(int i = 0; i <= hand.size(); i++){
        deck->putBackCard(hand.front());
        hand.pop();
    }
    pointValue = 0;
}