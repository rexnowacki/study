// Christopher Nowacki
// CIS 278
// Card Class
#include <string>

using namespace std;

// Card class definition
class Card {
public:
    // Simplified enums for faces and suits
    enum Face {
        TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING, ACE, MAX_FACES
    };

    enum Suit {
        HEARTS, DIAMONDS, CLUBS, SPADES, MAX_SUITS
    };

    // Constructor that initializes a card with a face and suit
    Card(Face f = TWO, Suit s = HEARTS) {
        face = f;
        suit = s;
    }

    // Converts a card to a string ex:  "Ace of Spades"
    string toString() const {
        return string(faceStrings[face]) + " of " + string(suitStrings[suit]);
    }

    // Public variables (fields) for face and suit
    Face face;
    Suit suit;

    // Strings for faces and suits
    static const char* faceStrings[MAX_FACES];
    static const char* suitStrings[MAX_SUITS];
};

// Initialize arrays of strings representing the faces and suits
const char* Card::faceStrings[Card::MAX_FACES] = {
    "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
    "Jack", "Queen", "King", "Ace"
};

const char* Card::suitStrings[Card::MAX_SUITS] = {
    "Hearts", "Diamonds", "Clubs", "Spades"
};
