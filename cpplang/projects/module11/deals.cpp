
#include <iostream>
#include <string>
#include <array>
#include <random>
#include <ctime>

// Card class
class Card {
public:
    enum class Face {
        TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING, ACE, MAX_FACES
    };
    enum class Suit {
        HEARTS, DIAMONDS, CLUBS, SPADES, MAX_SUITS
    };

private:
    Face face;
    Suit suit;
    static const std::array<std::string, static_cast<size_t>(Face::MAX_FACES)> faceStrings;
    static const std::array<std::string, static_cast<size_t>(Suit::MAX_SUITS)> suitStrings;

public:
    Card() : face(Face::TWO), suit(Suit::HEARTS) {} // Default constructor
    Card(Face f, Suit s) : face(f), suit(s) {}

    std::string toString() const {
        return faceStrings[static_cast<size_t>(face)] + " of " + suitStrings[static_cast<size_t>(suit)];
    }
};

// Static arrays initialization for Card class
const std::array<std::string, static_cast<size_t>(Card::Face::MAX_FACES)> Card::faceStrings {
    "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
    "Jack", "Queen", "King", "Ace"
};
const std::array<std::string, static_cast<size_t>(Card::Suit::MAX_SUITS)> Card::suitStrings {
    "Hearts", "Diamonds", "Clubs", "Spades"
};

// DeckOfCards class
class DeckOfCards {
private:
    std::array<Card, 52> deck;
    size_t currentCard;

public:
    DeckOfCards() : currentCard(0) {
        size_t card = 0;
        for (size_t suit = 0; suit < static_cast<size_t>(Card::Suit::MAX_SUITS); ++suit) {
            for (size_t face = 0; face < static_cast<size_t>(Card::Face::MAX_FACES); ++face) {
                deck[card++] = Card(static_cast<Card::Face>(face), static_cast<Card::Suit>(suit));
            }
        }
    }

    void shuffle() {
        std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
        std::uniform_int_distribution<size_t> dist(0, deck.size() - 1);
        for (size_t i = 0; i < deck.size(); ++i) {
            size_t swapIndex = dist(rng);
            std::swap(deck[i], deck[swapIndex]);
        }
    }

    Card dealCard() {
        if (currentCard < deck.size()) {
            return deck[currentCard++];
        } else {
            throw std::out_of_range("No more cards to deal.");
        }
    }

    bool moreCards() const {
        return currentCard < deck.size();
    }
};

// Main function
int main() {
    DeckOfCards deckOfCards;
    deckOfCards.shuffle();

    while (deckOfCards.moreCards()) {
        std::cout << deckOfCards.dealCard().toString() << std::endl;
    }

    return 0;
}

