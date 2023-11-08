// Christopher Nowacki
// CIS 278
// Deck Class

using namespace std;

class DeckOfCards {
private:
    array<Card, 52> deck; // array for 52 cards in a deck
    size_t currentCard; // index of next card dealt

public:
    // Inits deck of cards
    DeckOfCards() : currentCard(0) {
        size_t card = 0;
        // Loops through all suits and faces
        for (size_t suit = 0; suit < static_cast<size_t>(Card::Suit::MAX_SUITS); ++suit) {
            for (size_t face = 0; face < static_cast<size_t>(Card::Face::MAX_FACES); ++face) {
                // Initializes card at current counter with face and suit
                deck[card++] = Card(static_cast<Card::Face>(face), static_cast<Card::Suit>(suit));
            }
        }
    }

    void shuffle() {
        // Random number generator
        mt19937 rng(static_cast<unsigned int>(time(nullptr)));
        uniform_int_distribution<size_t> dist(0, deck.size() - 1);
        // Shuffles the deck by swapping each card with a random one
        for (size_t i = 0; i < deck.size(); ++i) {
            size_t swapIndex = dist(rng);
            swap(deck[i], deck[swapIndex]);
        }
    }

    Card dealCard() {
        // Checks for more cards
        if (currentCard < deck.size()) {
            return deck[currentCard++];
        } else {
            // If no more cards 
            throw out_of_range("No more cards to deal.");
        }
    }

    // Check if there are mroe cards to deal
    bool moreCards() const {
        return currentCard < deck.size();
    }
};
