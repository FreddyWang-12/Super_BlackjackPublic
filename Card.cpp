#include <iostream>
#include <cstring>
#include <stdio.h>
#include "Card.h"
using namespace std;

// Returns the value of the card
int Card::getValue(){
    return value;
}

// Returns the category of the card
// (Spades, Clubs, Diamonds, Hearts)
string Card::getCategory(){
    return category;
}

// Returns the card type of the card
// (Numbers, Kings, Queens, Jacks, Aces)
string Card::getCardType(){
    return cardType;
}

// Sets the value of the card
void Card::setValue(int value){
    this->value = value;
}

// Sets the category of the card
void Card::setCategory(string category){
    this->category = category;
}

// Sets the card type of the card
void Card::setCardType(string cardType){
    this->cardType = cardType;
}

// Prints a visual display of the given card, its 
// point value, and its information
void Card::print(){
    cout << "+---------------+" << endl; //15 dashes

    // If the card is a regular number card
    if(cardType == "Number"){
        printf("|%2i             |\n", value);
        if(category == " Spades"){
            cout << "|       *       |" << endl;
            cout << "|     * * *     |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|    * * * *    |" << endl;
            cout << "|      * *      |" << endl;
            cout << "|    * * * *    |" << endl;
        }
        else if(category == " Hearts"){
            cout << "|     *   *     |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|    * * * *    |" << endl;
            cout << "|      * *      |" << endl;
            cout << "|       *       |" << endl;
        }
        else if(category == " Diamonds"){
            cout << "|       *       |" << endl;
            cout << "|     * * *     |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|    * * * *    |" << endl;
            cout << "|      * *      |" << endl;
            cout << "|       *       |" << endl;
        }
        else if(category == " Clubs"){
            cout << "|   * * * * *   |" << endl;
            cout << "| * *   *   * * |" << endl;
            cout << "| * * * * * * * |" << endl;
            cout << "| * *   *   * * |" << endl;
            cout << "|       *       |" << endl;
            cout << "|   * * * * *   |" << endl;
        }

        printf("|             %2i|\n", value);
        cout << "+---------------+" << endl;
        cout << getValue() << " of" << getCategory() << endl;
    }

    // If the card is a king card
    if(cardType == "King"){
        cout << "| K             |" << endl;
        if(category == " Spades"){
            cout << "|       *       |" << endl;
            cout << "|     * * *     |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|    * * * *    |" << endl;
            cout << "|      * *      |" << endl;
            cout << "|    * * * *    |" << endl;
        }
        else if(category == " Hearts"){
            cout << "|     *   *     |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|    * * * *    |" << endl;
            cout << "|      * *      |" << endl;
            cout << "|       *       |" << endl;
        }
        else if(category == " Diamonds"){
            cout << "|       *       |" << endl;
            cout << "|     * * *     |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|    * * * *    |" << endl;
            cout << "|      * *      |" << endl;
            cout << "|       *       |" << endl;
        }
        else if(category == " Clubs"){
            cout << "|   * * * * *   |" << endl;
            cout << "| * *   *   * * |" << endl;
            cout << "| * * * * * * * |" << endl;
            cout << "| * *   *   * * |" << endl;
            cout << "|       *       |" << endl;
            cout << "|   * * * * *   |" << endl;
        }

        cout << "|             K |"  << endl;
        cout << "+---------------+" << endl;
        cout << getCardType() << " of" << getCategory() << ": " << getValue() << endl;
    }

    // If the card is a queen card
    if(cardType == "Queen"){
        cout << "| Q             |" << endl;
        if(category == " Spades"){
            cout << "|       *       |" << endl;
            cout << "|     * * *     |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|    * * * *    |" << endl;
            cout << "|      * *      |" << endl;
            cout << "|    * * * *    |" << endl;
        }
        else if(category == " Hearts"){
            cout << "|     *   *     |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|    * * * *    |" << endl;
            cout << "|      * *      |" << endl;
            cout << "|       *       |" << endl;
        }
        else if(category == " Diamonds"){
            cout << "|       *       |" << endl;
            cout << "|     * * *     |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|    * * * *    |" << endl;
            cout << "|      * *      |" << endl;
            cout << "|       *       |" << endl;
        }
        else if(category == " Clubs"){
            cout << "|   * * * * *   |" << endl;
            cout << "| * *   *   * * |" << endl;
            cout << "| * * * * * * * |" << endl;
            cout << "| * *   *   * * |" << endl;
            cout << "|       *       |" << endl;
            cout << "|   * * * * *   |" << endl;
        }

        cout << "|             Q |"  << endl;
        cout << "+---------------+" << endl;
        cout << getCardType() << " of" << getCategory() << ": " << getValue() << endl;
    }

    // If the card is a jack card
    if(cardType == "Jack"){
        cout << "| J             |" << endl;
        if(category == " Spades"){
            cout << "|       *       |" << endl;
            cout << "|     * * *     |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|    * * * *    |" << endl;
            cout << "|      * *      |" << endl;
            cout << "|    * * * *    |" << endl;
        }
        else if(category == " Hearts"){
            cout << "|     *   *     |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|    * * * *    |" << endl;
            cout << "|      * *      |" << endl;
            cout << "|       *       |" << endl;
        }
        else if(category == " Diamonds"){
            cout << "|       *       |" << endl;
            cout << "|     * * *     |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|    * * * *    |" << endl;
            cout << "|      * *      |" << endl;
            cout << "|       *       |" << endl;
        }
        else if(category == " Clubs"){
            cout << "|   * * * * *   |" << endl;
            cout << "| * *   *   * * |" << endl;
            cout << "| * * * * * * * |" << endl;
            cout << "| * *   *   * * |" << endl;
            cout << "|       *       |" << endl;
            cout << "|   * * * * *   |" << endl;
        }

        cout << "|             J |"  << endl;
        cout << "+---------------+" << endl;
        cout << getCardType() << " of" << getCategory() << ": " << getValue() << endl;
    }

    // If the card is a ace card
    if(cardType == "Ace"){
        cout << "| A             |" << endl;
        if(category == " Spades"){
            cout << "|       *       |" << endl;
            cout << "|     * * *     |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|    * * * *    |" << endl;
            cout << "|      * *      |" << endl;
            cout << "|    * * * *    |" << endl;
        }
        else if(category == " Hearts"){
            cout << "|     *   *     |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|    * * * *    |" << endl;
            cout << "|      * *      |" << endl;
            cout << "|       *       |" << endl;
        }
        else if(category == " Diamonds"){
            cout << "|       *       |" << endl;
            cout << "|     * * *     |" << endl;
            cout << "|   * * * * *   |" << endl;
            cout << "|    * * * *    |" << endl;
            cout << "|      * *      |" << endl;
            cout << "|       *       |" << endl;
        }
        else if(category == " Clubs"){
            cout << "|   * * * * *   |" << endl;
            cout << "| * *   *   * * |" << endl;
            cout << "| * * * * * * * |" << endl;
            cout << "| * *   *   * * |" << endl;
            cout << "|       *       |" << endl;
            cout << "|   * * * * *   |" << endl;
        }

        cout << "|             A |"  << endl;
        cout << "+---------------+" << endl;
        cout << getCardType() << " of" << getCategory() << ": " << getValue() << endl;
    }
//    cout << getCategory() << ": " << getValue() << endl;
}