#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Dice.h"
using namespace std;

// Rolls a die that returns a point value between 1 to 6
int Dice::diceRoll(){
    return rand()%6 + 1;
}

// Displays the physical dice roll and its value
void Dice::print(int roll){
    if(roll == 1){
        cout << "+------------+" << endl;
        cout << "|            |" << endl;
        cout << "|      *     |" << endl;
        cout << "|            |" << endl;
        cout << "+------------+" << endl;
    }
    if(roll == 2){
        cout << "+------------+" << endl;
        cout << "| *          |" << endl;
        cout << "|            |" << endl;
        cout << "|          * |" << endl;
        cout << "+------------+" << endl;
    }
    if(roll == 3){
        cout << "+------------+" << endl;
        cout << "| *          |" << endl;
        cout << "|      *     |" << endl;
        cout << "|          * |" << endl;
        cout << "+------------+" << endl;
    }
    if(roll == 4){
        cout << "+------------+" << endl;
        cout << "| *        * |" << endl;
        cout << "|            |" << endl;
        cout << "| *        * |" << endl;
        cout << "+------------+" << endl;
    }
    if(roll == 5){
        cout << "+------------+" << endl;
        cout << "| *        * |" << endl;
        cout << "|      *     |" << endl;
        cout << "| *        * |" << endl;
        cout << "+------------+" << endl;
    }
    if(roll == 6){
        cout << "+------------+" << endl;
        cout << "| *        * |" << endl;
        cout << "| *        * |" << endl;
        cout << "| *        * |" << endl;
        cout << "+------------+" << endl;
    }
}