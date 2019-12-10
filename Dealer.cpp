#include <iostream>
#include <cstring>
#include <queue>
#include "Card.h"
#include "Deck.h"
#include "Dice.h"
#include "Dealer.h"
using namespace std;

// The base constructor for the dealer
Dealer::Dealer(){
    pointValue = 0;
}

// Dealer is given the ability to draw a card from a deck
// and adds that card's point value to his/her current total
// points
void Dealer::drawCard(Deck *deck){
    Card temp = deck->draw();
    pointValue += temp.getValue();
    hand.push(temp);
}

// Returns the total amount of points the player has in his/her
// hand of cards
int Dealer::totalPoints(){
    return pointValue;
}

// Prints all of the cards in hand
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

// A seperate method that allows the dealer to reveal only 
// the first card in the dealer's hand
void Dealer::showFirstCard(){
    Card first = hand.top();
    first.print();
    cout << endl;
}

// Returns all of the cards in hand back into the original deck
// regardless if the player wins, loses, or ties
void Dealer::resetHand(Deck *deck){
    for(int i = 0; i <= hand.size() + 1; i++){
        deck->putBackCard(hand.top());
        hand.pop();
    }
    pointValue = 0;
}