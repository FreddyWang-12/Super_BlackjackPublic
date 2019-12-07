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

    Player demoPlayer;
    Dealer demoDealer;

    historyFile.open("history.txt");
    while(cont){
        roundCounter++;    
        demoDeck.shuffle();
        demoPlayer.bet();

        cout << "Dealing Cards: \n" << endl;
        demoDealer.drawCard(&demoDeck);
        demoPlayer.drawCard(&demoDeck);
        demoDealer.drawCard(&demoDeck);
        demoPlayer.drawCard(&demoDeck);

        cout << "Player's Hand: " << endl;
        demoPlayer.printHand();
        cout << endl;
        cout << "Dealer Shows: " << endl;
        demoDealer.showFirstCard();

        char response;
        while(cont){
            cout << "Enter 's' to stay, 'h' to hit on a card, or 'd' to hit on a dice: ";
            cin >> response;
            cout << endl;

            if(response == 'h'){
                demoPlayer.drawCard(&demoDeck);
                demoPlayer.printHand();
            }
            else if(response == 'd'){
                demoPlayer.rollDice();
                demoPlayer.printHand();
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
        demoPlayer.printHand();
        cout << endl;
        cout << "Dealer's Hand: " << endl;
        demoDealer.printHand();
        cout << endl;

        historyFile << "Hand: " << to_string(roundCounter); 
        historyFile << " Player: " << to_string(demoPlayer.totalPoints());
        historyFile << "\tDealer: " << to_string(demoDealer.totalPoints());

        if(demoPlayer.totalPoints() == demoDealer.totalPoints() || (demoPlayer.totalPoints() > 21 && demoDealer.totalPoints() > 21)){
            demoPlayer.tie(&demoDeck);
            demoDealer.resetHand(&demoDeck);
            historyFile << "\tResult: Player Tied with Dealer\n";
        }
        else if(demoPlayer.totalPoints() > 21){
            demoPlayer.lose(&demoDeck);
            demoDealer.resetHand(&demoDeck);
            historyFile << "\tResult: Player Lost, Player Busts\n";
        }
        else if(demoDealer.totalPoints() > 21){
            demoPlayer.win(&demoDeck);
            demoDealer.resetHand(&demoDeck);
            historyFile << "\tResult: Player Won, Dealer Busts\n";
        }
        else if(demoPlayer.totalPoints() < demoDealer.totalPoints()){
            demoPlayer.lose(&demoDeck);
            demoDealer.resetHand(&demoDeck);
            historyFile << "\tResult: Player Lost, Score Below Dealer\n";
        }
        else{
            demoPlayer.win(&demoDeck);
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
    historyFile.close();

    ifstream displayedHistory("history.txt");

    cout << "Displaying History: " << endl;
    for(string line; getline(displayedHistory, line);){
        cout << line << endl;
    }
    displayedHistory.close();

    return 0;
}