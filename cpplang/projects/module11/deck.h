
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
