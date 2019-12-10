#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Dice.h"
using namespace std;

// Rolls a die that returns a point value between 1 to 6
int Dice::diceRoll(){
    value = rand()%6 + 1;
    value = rand()%6 + 1;
    return value;
}

// Displays the physical dice roll and its value
void Dice::print(){
    if(value == 1){
        cout << "+------------+" << endl;
        cout << "|            |" << endl;
        cout << "|      *     |" << endl;
        cout << "|            |" << endl;
        cout << "+------------+" << endl;
    }
    if(value == 2){
        cout << "+------------+" << endl;
        cout << "| *          |" << endl;
        cout << "|            |" << endl;
        cout << "|          * |" << endl;
        cout << "+------------+" << endl;
    }
    if(value == 3){
        cout << "+------------+" << endl;
        cout << "| *          |" << endl;
        cout << "|      *     |" << endl;
        cout << "|          * |" << endl;
        cout << "+------------+" << endl;
    }
    if(value == 4){
        cout << "+------------+" << endl;
        cout << "| *        * |" << endl;
        cout << "|            |" << endl;
        cout << "| *        * |" << endl;
        cout << "+------------+" << endl;
    }
    if(value == 5){
        cout << "+------------+" << endl;
        cout << "| *        * |" << endl;
        cout << "|      *     |" << endl;
        cout << "| *        * |" << endl;
        cout << "+------------+" << endl;
    }
    if(value == 6){
        cout << "+------------+" << endl;
        cout << "| *        * |" << endl;
        cout << "| *        * |" << endl;
        cout << "| *        * |" << endl;
        cout << "+------------+" << endl;
    }
}