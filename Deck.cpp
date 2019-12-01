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
    categories.push("of Spades");
    categories.push("of Hearts");
    categories.push("of Diamonds");
    categories.push("of Clubs");

    for(i = 0; i < 4; i++){
        category = categories.front();
        for(j = 2; j <= 10; j++){
            Card standard;
            standard.setValue(j);
            string temp = to_string(j) + category;
            standard.setCategory(temp);
            deck.push(standard);
        }

        Card king;
        king.setValue(10);
        string temp = "King " + category;
        king.setCategory(temp);
        deck.push(king);
        temp.erase();

        Card queen;
        king.setValue(10);
        temp = "Queen " + category;
        king.setCategory(temp);
        deck.push(king);
        temp.erase();

        Card jack;
        king.setValue(10);
        temp = "Jack " + category;
        king.setCategory(temp);
        deck.push(king);
        temp.erase();

        Card ace;
        king.setValue(0);
        temp = "Ace " + category;
        king.setCategory(temp);
        deck.push(king);
        temp.erase();

        category.erase();
        categories.pop();
    }
}
void Deck::shuffle(){
    Card tempArray[52];
    for(int i = 0; i < 52; i++){
        Card temp = deck.top();
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
    stack<Card> temp = deck;
    cout << temp.size() << endl;
    for(int i = 0; i < 52; i++){
        Card x = temp.top();
        x.print();
        temp.pop();
    }
}