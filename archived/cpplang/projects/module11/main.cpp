// Christopher Nowacki
// CIS 278 
// Deck Dealer

#include <iostream>
#include <string>
#include <array>
#include <random>
#include <ctime>
#include "card.h"
#include "deck.h"

using namespace std;

// Main function
int main() {
    DeckOfCards deckOfCards;
    deckOfCards.shuffle();

    while (deckOfCards.moreCards()) {
        cout << deckOfCards.dealCard().toString() << endl;
    }

    return 0;
}
