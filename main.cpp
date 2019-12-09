#include "Card.h"
#include "Deck.h"
#include "Dice.h"
#include "Player.h"
#include "Dealer.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main(){
    Deck demoDeck;
    bool cont = true;
    ofstream historyFile;
    int roundCounter = 0;

    Player player;
    Dealer demoDealer;

    ifstream bankAccount("bankAccount.txt");
    string bankMoney;
    getline(bankAccount, bankMoney);
    int totalMoney = stoi(bankMoney.substr(14));
    player.setBankAccount(totalMoney);
    bankAccount.close();

    historyFile.open("history.txt");
    while(cont){
        roundCounter++;    
        demoDeck.shuffle();
        player.bet();

        cout << "Dealing Cards: \n" << endl;
        demoDealer.drawCard(&demoDeck);
        player.drawCard(&demoDeck);
        demoDealer.drawCard(&demoDeck);
        player.drawCard(&demoDeck);

        cout << "Player's Hand: " << endl;
        player.printHand();
        cout << endl;
        cout << "Dealer Shows: " << endl;
        demoDealer.showFirstCard();

        char response;
        while(cont){
            cout << "Enter 's' to stay, 'h' to hit on a card, or 'd' to hit on a dice: ";
            cin >> response;
            cout << endl;

            if(response == 'h'){
                player.drawCard(&demoDeck);
                player.printHand();
            }
            else if(response == 'd'){
                player.rollDice();
                player.printHand();
            }
            else{
                cont = false;
            }
        }

        while(demoDealer.totalPoints() < 17){
            cout << "Dealer hits:" << endl;
            demoDealer.drawCard(&demoDeck);
            demoDealer.showFirstCard();
        }

        cout << "Player's Hand: " << endl;
        player.printHand();
        cout << endl;
        cout << "Dealer's Hand: " << endl;
        demoDealer.printHand();
        cout << endl;

        historyFile << "Hand: " << to_string(roundCounter); 
        historyFile << " Player: " << to_string(player.totalPoints());
        historyFile << "\tDealer: " << to_string(demoDealer.totalPoints());

        if(player.totalPoints() == demoDealer.totalPoints() || (player.totalPoints() > 21 && demoDealer.totalPoints() > 21)){
            player.tie(&demoDeck);
            demoDealer.resetHand(&demoDeck);
            historyFile << "\tResult: Player Tied with Dealer\n";
        }
        else if(player.totalPoints() > 21){
            player.lose(&demoDeck);
            demoDealer.resetHand(&demoDeck);
            historyFile << "\tResult: Player Lost, Player Busts\n";
        }
        else if(demoDealer.totalPoints() > 21){
            player.win(&demoDeck);
            demoDealer.resetHand(&demoDeck);
            historyFile << "\tResult: Player Won, Dealer Busts\n";
        }
        else if(player.totalPoints() < demoDealer.totalPoints()){
            player.lose(&demoDeck);
            demoDealer.resetHand(&demoDeck);
            historyFile << "\tResult: Player Lost, Score Below Dealer\n";
        }
        else{
            player.win(&demoDeck);
            demoDealer.resetHand(&demoDeck);
            historyFile << "\tResult: Player Won, Score Above Dealer\n";
        }

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

    ofstream bank;
    bank.open("bankAccount.txt");

    cout << "Saving Bank Balance..." << endl;
    historyFile << "Bank Balance: " << to_string(player.getBankAccount());
    bank << "Bank Balance: " << to_string(player.getBankAccount());
    cout << "Bank Balance Saved ";
    historyFile.close();
    bank.close();

    ifstream displayedHistory("history.txt");

    cout << "Displaying History: " << endl;
    for(string line; getline(displayedHistory, line);){
        cout << line << endl;
    }

    displayedHistory.close();

    return 0;
}