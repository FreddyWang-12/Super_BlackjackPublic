#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Dice.h"
using namespace std;

int Dice::diceRoll(){
    return rand()%6 + 1;
}