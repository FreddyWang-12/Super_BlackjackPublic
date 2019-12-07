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
/*    if(temp.getCategory().substr(0, 3) == "Ace"){
        temp.setValue(11);
    }*/
    pointValue += temp.getValue();
    hand.push(temp);
}

int Dealer::totalPoints(){
    return pointValue;
}

void Dealer::printHand(){
    stack<Card> temp = hand;
    int size = temp.size();
    for(int i = 0; i < size; i++){
        Card first = temp.top();
        first.print();
        temp.pop();
    }
    cout << "Dealer's Hand Value: " << pointValue << endl;
}

void Dealer::showFirstCard(){
    Card first = hand.top();
    first.print();
    cout << endl;
}

void Dealer::resetHand(Deck *deck){
    for(int i = 0; i <= hand.size() + 1; i++){
        deck->putBackCard(hand.top());
        hand.pop();
    }
    pointValue = 0;
}