#include <iostream>
#include <cstring>
#include <queue>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Dice.h"
using namespace std;

// The base bank balance for a player is 0
Player::Player(){
    bankBalance = 0;
    pointValue = 0;
}

// Allows the player to set their bank balance in game
// to their current bank balance in file
void Player::setBankAccount(int bankBalance){
    this->bankBalance = bankBalance;
}

// Returns the bank balance of the player
int Player::getBankAccount(){
    return bankBalance;
}

// Allows the player to bet for an amount of money 
void Player::bet(){
    cout << "How much do you want to bet? ";
    cin >> betValue;
    cout << endl;
}

// Player is given the ability to draw a card from a deck
// and adds that card's point value to his/her current total
// points
void Player::drawCard(Deck *deck){
    Card temp = deck->draw();
    pointValue += temp.getValue();
    hand.push(temp);
}

// Returns the total amount of points the player has in his/her
// hand of cards
int Player::totalPoints(){
    return pointValue;
}

// Allows the player to roll a dice object and add its value to
// the player's current total point pool
void Player::rollDice(){
    int diceRoll = dice.diceRoll();
    cout << "Dice Roll: " << endl;
    dice.print();
    pointValue += diceRoll;
    cout << "Your Point Value: " << pointValue << endl;
}

// Adds the betted value the player has setted and returns all cards 
// from hand back into the original deck if the player has won
void Player::win(Deck *deck){
    cout << "You Win!" << endl;
    bankBalance += betValue;
    cout << "You gained " << betValue << " dollars.\n" << endl;

    int size = hand.size();
    for(int i = 0; i < size; i++){
        deck->putBackCard(hand.top());
        hand.pop();
    }
    pointValue = 0;
    cout << "Bank Balance: " << bankBalance << endl;
}

// Subtracts the betted value the player has setted and returns all cards 
// from hand back into the original deck if the player has lost
void Player::lose(Deck *deck){
    cout << "You Lose" << endl;
    bankBalance -= betValue;
    cout << "You lost " << betValue << " dollars.\n" << endl;

    int size = hand.size();
    for(int i = 0; i < size; i++){
        deck->putBackCard(hand.top());
        hand.pop();
    }
    pointValue = 0;
    cout << "Bank Balance: " << bankBalance << endl;
}

// Simply returns all cards from hand back into the original deck if the player
// and the dealer tie 
void Player::tie(Deck *deck){
    cout << "You Tied" << endl;
    cout << "You neither gained nor lost any money.\n" << endl;

    int size = hand.size();
    for(int i = 0; i < size; i++){
        deck->putBackCard(hand.top());
        hand.pop();
    }
    pointValue = 0;
    cout << "Bank Balance: " << bankBalance << endl;
}

// Prints all of the cards in hand
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