#include <iostream>
#include <cstring>
#include <queue>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Dice.h"
using namespace std;

Player::Player(){
    bankBalance = 0;
    pointValue = 0;
}

void Player::bet(){
    cout << "How much do you want to bet? ";
    cin >> betValue;
    cout << endl;
}

void Player::drawCard(Deck *deck){
    Card temp = deck->draw();
    if(temp.getCategory().substr(0, 3) == "Ace"){
        int value;
        cout << "What is the value of this Ace Card (1 or 11)? ";
        cin >> value;
        cout << endl;
        temp.setValue(value);
    }
    pointValue += temp.getValue();
    hand.push(temp);
}

int Player::totalPoints(){
    return pointValue;
}

void Player::rollDice(){
    int diceRoll = dice.diceRoll();
    cout << "Dice Roll: " << diceRoll << endl;
    pointValue += diceRoll;
}

void Player::win(Deck *deck){
    cout << "You Win!" << endl;
    bankBalance += betValue;
    for(int i = 0; i <= hand.size(); i++){
        deck->putBackCard(hand.front());
        hand.pop();
    }
    pointValue = 0;
    cout << "Bank Balance: " << bankBalance << endl;
}

void Player::lose(Deck *deck){
    cout << "You Lose" << endl;
    bankBalance -= betValue;
    for(int i = 0; i <= hand.size(); i++){
        deck->putBackCard(hand.front());
        hand.pop();
    }
    pointValue = 0;
    cout << "Bank Balance: " << bankBalance << endl;
}

void Player::printHand(){
    queue<Card> temp = hand;
    for(int i = 0; i <= temp.size() + 1; i++){
        Card first = temp.front();
        first.print();
        temp.pop();
    }
    cout << "Total Points: " << pointValue << endl;
}