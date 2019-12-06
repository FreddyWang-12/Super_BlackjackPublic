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
    int roundCounter;

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
        cout << "Dealer's Hand: " << endl;
        demoDealer.showFirstCard();
        cout << endl; 

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
            }
            else{
                cont = false;
            }
        }

        while(demoDealer.totalPoints() < 17){
            demoDealer.drawCard(&demoDeck);
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

        if(demoDealer.totalPoints() > 21){
            demoPlayer.win(&demoDeck);
            demoDealer.resetHand(&demoDeck);
            historyFile << "\tResult: Player Won\n";
        }
        else if(demoPlayer.totalPoints() > 21 || demoPlayer.totalPoints() <= demoDealer.totalPoints()){
            demoPlayer.lose(&demoDeck);
            demoDealer.resetHand(&demoDeck);
            historyFile << "\tResult: Player Lost\n";
        }
        else{
            demoPlayer.win(&demoDeck);
            demoDealer.resetHand(&demoDeck);
            historyFile << "\tResult: Player Won\n";
        }


        cout << "Do you want to continue? (y for Yes, n for No) ";
        cin >> response;
        cout << endl;

        if(response == 'n'){
            cont = false;
        }
        else{
            cont = true;
        }
    }
    historyFile.close();
    return 0;
}