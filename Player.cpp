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

void Player::setBankAccount(int bankBalance){
    this->bankBalance = bankBalance;
}

int Player::getBankAccount(){
    return bankBalance;
}

void Player::bet(){
    cout << "How much do you want to bet? ";
    cin >> betValue;
    cout << endl;
}

void Player::drawCard(Deck *deck){
    Card temp = deck->draw();
    pointValue += temp.getValue();
    hand.push(temp);
}

int Player::totalPoints(){
    return pointValue;
}

void Player::rollDice(){
    int diceRoll = dice.diceRoll();
    cout << "Dice Roll: " << endl;
    dice.print();
    pointValue += diceRoll;
    cout << "Your Point Value: " << pointValue << endl;
}

void Player::win(Deck *deck){
    cout << "You Win!" << endl;
    bankBalance += betValue;

    int size = hand.size();
    for(int i = 0; i < size; i++){
        deck->putBackCard(hand.top());
        hand.pop();
    }
    pointValue = 0;
    cout << "Bank Balance: " << bankBalance << endl;
}

void Player::lose(Deck *deck){
    cout << "You Lose" << endl;
    bankBalance -= betValue;

    int size = hand.size();
    for(int i = 0; i < size; i++){
        deck->putBackCard(hand.top());
        hand.pop();
    }
    pointValue = 0;
    cout << "Bank Balance: " << bankBalance << endl;
}

void Player::tie(Deck *deck){
    cout << "You Tied" << endl;

    int size = hand.size();
    for(int i = 0; i < size; i++){
        deck->putBackCard(hand.top());
        hand.pop();
    }
    pointValue = 0;
    cout << "Bank Balance: " << bankBalance << endl;
}

void Player::printHand(){
    stack<Card> temp = hand;
    int size = temp.size();
    for(int i = 0; i < size; i++){
        Card first = temp.top();
        first.print();
        temp.pop();
    }
    cout << "Your Hand Value: " << pointValue << endl;
}