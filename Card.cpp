#include <iostream>
#include <cstring>
#include "Card.h"
using namespace std;

int Card::getValue(){
    return value;
}

string Card::getCategory(){
    return category;
}

void Card::setValue(int value){
    this->value = value;
}

void Card::setCategory(string category){
    this->category = category;
}

void Card::print(){
    cout << getCategory() << ": " << getValue() << endl;
}