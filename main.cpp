#include "Card.h"
#include "Deck.h"
#include "Dice.h"
#include "Player.h"
#include "Dealer.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

// Creates a game of super blackjack
int main(){
    Deck deck;
    bool cont = true;
    ofstream historyFile;
    int roundCounter = 0;

    Player player;
    Dealer dealer;

    // Opening up the bank balance 
    cout << "\nLoading bank balance..." << endl;
    ifstream bankAccount("bankAccount.txt");
    string bankMoney;
    getline(bankAccount, bankMoney);
    int totalMoney = stoi(bankMoney.substr(14));
    player.setBankAccount(totalMoney);
    bankAccount.close();
    cout << "Bank Balance = " << player.getBankAccount() << "\n" << endl;

    // Opening a new game history file
    historyFile.open("history.txt");
    while(cont){
        // A new round starts as the deck is shuffled and the player calls in a bet
        roundCounter++;    
        deck.shuffle();
        player.bet();

        // The cards are drawn between the player and the dealer
        cout << "Dealing Cards: \n" << endl;
        dealer.drawCard(&deck);
        player.drawCard(&deck);
        dealer.drawCard(&deck);
        player.drawCard(&deck);

        // The player's hand and the dealer's first card are shown
        cout << "Dealer Shows: " << endl;
        dealer.showFirstCard();
        cout << endl;
        cout << "Player's Hand: " << endl;
        player.printHand();
        cout << endl;

        // The player can choose to stay, hit a card, or hit a dice
        char response;
        while(cont){
            cout << "Enter 's' to stay, 'h' to hit on a card, or 'd' to hit on a dice: ";
            cin >> response;
            cout << endl;

            // The player can draw as many cards as he/she likes until he/she stays
            if(response == 'h'){
                player.drawCard(&deck);
                player.printHand();
                cout << endl;
            }
            // The player can roll the dice as he/she likes until he/she stays
            else if(response == 'd'){
                player.rollDice();
                player.printHand();
                cout << endl;
            }
            // The player is satisfied with his/her hand and will wait for the dealer
            // to finish drawing cards
            else{
                cont = false;
            }
        }

        // The dealer continuously draw cards until the dealer's point value is
        // equal to or higher than 17
        while(dealer.totalPoints() < 17){
            cout << "Dealer hits:" << endl;
            dealer.drawCard(&deck);
            dealer.showFirstCard();
        }

        // The player's and the dealer's final hands are shown and their point values are displayed
        cout << "Player's Hand: " << endl;
        player.printHand();
        cout << endl;
        cout << "Dealer's Hand: " << endl;
        dealer.printHand();
        cout << endl;

        // The game history is updated with the information of this round
        historyFile << "Hand: " << to_string(roundCounter); 
        historyFile << " Player: " << to_string(player.totalPoints());
        historyFile << "\tDealer: " << to_string(dealer.totalPoints());
        cout << "You had " << player.totalPoints() << " and the dealer had " << dealer.totalPoints() << "." << endl;

        // If both players have an equal amount of points, they will tie and no exchange of money is made
        if(player.totalPoints() == dealer.totalPoints()){
            player.tie(&deck);
            dealer.resetHand(&deck);
            historyFile << "\tResult: Player Tied with Dealer\n";
        }
        // If both players go beyond 21 and bust, they will tie and no exchange of money is made
        else if(player.totalPoints() > 21 && dealer.totalPoints() > 21){
            player.tie(&deck);
            dealer.resetHand(&deck);
            historyFile << "\tResult: Both Player and Dealer Bust\n";
        }
        // If only the player goes beyond 21 and busts, the player will lose
        else if(player.totalPoints() > 21){
            player.lose(&deck);
            dealer.resetHand(&deck);
            historyFile << "\tResult: Player Lost, Player Busts\n";
        }
        // If only the dealer goes beyond 21 and busts, the player will win
        else if(dealer.totalPoints() > 21){
            player.win(&deck);
            dealer.resetHand(&deck);
            historyFile << "\tResult: Player Won, Dealer Busts\n";
        }
        // If the player scores below the dealer without busting, the player will lose
        else if(player.totalPoints() < dealer.totalPoints()){
            player.lose(&deck);
            dealer.resetHand(&deck);
            historyFile << "\tResult: Player Lost, Score Below Dealer\n";
        }
        // If the player scores below the dealer without busting, the player will lose
        else if(player.totalPoints() == 21){
            player.win(&deck);
            dealer.resetHand(&deck);
            historyFile << "\tResult: Player Won, Blackjack on Deal\n";
        }
        else if(dealer.totalPoints() == 21){
            player.lose(&deck);
            dealer.resetHand(&deck);
            historyFile << "\tResult: Player Lose, Dealer Blackjack on Deal\n";
        }
        // If the player scores above the dealer without busting, the player will win
        else{
            player.win(&deck);
            dealer.resetHand(&deck);
            historyFile << "\tResult: Player Won, Score Above Dealer\n";
        }

        // The player will be asked whether he/she wants to play another round
        cout << "Do you want to continue? (y for Yes, n for No) ";
        cin >> response;
        cout << endl;

        if(response == 'y'){
            cont = true;
        }
        else{
            cont = false;
        }
    }
    // The game ends

    // The file of the player's bank account is opened
    ofstream bank;
    bank.open("bankAccount.txt");

    // From here, the player's bank balance will be updated
    cout << "Saving Bank Balance..." << endl;
    historyFile << "Bank Balance: " << to_string(player.getBankAccount());
    bank << "Bank Balance: " << to_string(player.getBankAccount());
    cout << "Bank Balance Saved \n" << endl;
    historyFile.close();
    bank.close();
    
    // The player's game history from the previously played game is displayed
    ifstream displayedHistory("history.txt");

    cout << "Displaying History: " << endl;
    for(string line; getline(displayedHistory, line);){
        cout << line << endl;
    }
    cout << endl;

    displayedHistory.close();

    return 0;
}