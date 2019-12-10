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

string Card::getCardType(){
    return cardType;
}

void Card::setValue(int value){
    this->value = value;
}

void Card::setCategory(string category){
    this->category = category;
}

void Card::setCardType(string cardType){
    this->cardType = cardType;
}

void Card::print(){
    cout << "+---------------+" << endl; //15 dashes
    if(cardType == "Number"){
        cout << "| " << value << "             |" << endl;
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

        cout << "|             " << value << " |"  << endl;
        cout << "+---------------+" << endl;
        cout << getValue() << " of" << getCategory() << endl;
    }

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