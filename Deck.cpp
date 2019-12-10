#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <array>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "Deck.h"
using namespace std;

Deck::Deck(){
    int i;
    int j;
    string category;

    queue<string> categories;
    categories.push(" Spades");
    categories.push(" Hearts");
    categories.push(" Diamonds");
    categories.push(" Clubs");

    for(i = 0; i < 4; i++){
        category = categories.front();
        for(j = 2; j <= 10; j++){
            Card standard;
            standard.setValue(j);
            standard.setCardType("Number");
            standard.setCategory(category);
            deck.push(standard);
        }

        Card king;
        king.setValue(10);
        king.setCardType("King");
        king.setCategory(category);
        deck.push(king);


        Card queen;
        queen.setValue(10);
        queen.setCardType("Queen");
        queen.setCategory(category);
        deck.push(queen);

        Card jack;
        jack.setValue(10);
        jack.setCardType("Jack");
        jack.setCategory(category);
        deck.push(jack);

        Card ace;
        ace.setValue(11);
        ace.setCardType("Ace");
        ace.setCategory(category);
        deck.push(ace);

        category.erase();
        categories.pop();
    }
}
void Deck::shuffle(){
    Card tempArray[52];
    for(int i = 0; i < 52; i++){
        Card temp = deck.front();
        tempArray[i] = temp;
        deck.pop();
    }

    srand(time(0));
    for(int i = 0; i < 52; i++){
        int r = i + (rand() % (52 - i));
        swap(tempArray[i], tempArray[r]);
    }

    for(int i = 0; i < 52; i++){
        Card temp = tempArray[i];
        deck.push(temp);
    }
}

void Deck::print(){
    queue<Card> temp = deck;
    cout << temp.size() << endl;
    for(int i = 0; i < 52; i++){
        Card x = temp.front();
        x.print();
        temp.pop();
    }
//    cout << deck.size() << endl;
}

Card Deck::draw(){
    Card drawn = deck.front();
    deck.pop();
    return drawn;
}

void Deck::putBackCard(Card putBack){
    deck.push(putBack);
}