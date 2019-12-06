#include "Card.h"
#include "Deck.h"
#include "Dice.h"
#include "Player.h"
#include "Dealer.h"
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    Deck demoDeck;
    bool cont = true;

    Player demoPlayer;
    Dealer demoDealer;

    while(cont){    
        demoDeck.shuffle();
        demoPlayer.bet();

        cout << "Dealing Cards: " << endl;
        demoDealer.drawCard(&demoDeck);
        demoPlayer.drawCard(&demoDeck);
        demoPlayer.drawCard(&demoDeck);

        demoPlayer.printHand();
        cout << endl;
        demoDealer.printHand();
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

        demoPlayer.printHand();
        cout << endl;
        demoDealer.printHand();
        cout << endl;

        if(demoDealer.totalPoints() > 21){
            demoPlayer.win(&demoDeck);
            demoDealer.resetHand(&demoDeck);
        }
        else if(demoPlayer.totalPoints() > 21 || demoPlayer.totalPoints() <= demoDealer.totalPoints()){
            demoPlayer.lose(&demoDeck);
            demoDealer.resetHand(&demoDeck);
        }
        else{
            demoPlayer.win(&demoDeck);
            demoDealer.resetHand(&demoDeck);
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
    return 0;
}