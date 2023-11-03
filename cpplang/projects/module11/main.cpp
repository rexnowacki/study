#include <iostream>
#include <string>
#include <array>
#include <random>
#include <ctime>
#include "card.h"
#include "deck.h"

// Main function
int main() {
    DeckOfCards deckOfCards;
    deckOfCards.shuffle();

    while (deckOfCards.moreCards()) {
        std::cout << deckOfCards.dealCard().toString() << std::endl;
    }

    return 0;
}
