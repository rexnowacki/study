
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()


// Vector for possible words
const std::vector<std::string> words = {
    "rotting", "hologram", "burrito", "donkey", "brass",
    "fingers", "credit", "hammer", "graze", "stifle",
    "illicit", "program", "flimsy", "trained", "acoustic"
};

constexpr unsigned MAX_GUESSES = 7;

// Gives visual representation of hanging status
class Gallows {
    const std::vector<std::string> stages = {
        "  +---+\n  |\n  |\n  |\n  |\n__|__\n",
        "  +---+\n  |   O\n  |\n  |\n  |\n__|__\n",
        "  +---+\n  |   O\n  |   |\n  |\n  |\n__|__\n",
        "  +---+\n  |   O\n  |  /|\n  |\n  |\n__|__\n",
        "  +---+\n  |   O\n  |  /|\\\n  |\n  |\n__|__\n",
        "  +---+\n  |   O\n  |  /|\\\n  |  /\n  |\n__|__\n",
        "  +---+\n  |   O\n  |  /|\\\n  |  / \\\n  |\n__|__\n",
        "  +---+\n  |   O\n  |  /|\\\n  |  / \\\n  |   DEAD\n__|__\n"
    };

public:
    void show(int incorrectGuesses) const {
        if (incorrectGuesses < stages.size()) {
            std::cout << stages[incorrectGuesses] << "\n";
        }
    }
};

// Display hanging status, known letters, guessed letters
void displayGameState(const Gallows& gallows, int incorrectGuesses, const std::string& displayedWord, const std::vector<char>& guessedLetters) {
    gallows.show(incorrectGuesses);
    std::cout << "\nWord: " << displayedWord << "\n";
    
    // Sort and display guessed letters
    std::vector<char> sortedLetters = guessedLetters;  // Copy to avoid modifying original
    std::sort(sortedLetters.begin(), sortedLetters.end());
    std::cout << "Guessed letters: ";
    for (char letter : sortedLetters) {
        std::cout << letter << ' ';
    }
    std::cout << "\n\n";
}

// Get current guess
char handleGuess(const std::vector<char>& guessedLetters) {
    char guess;
    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        guess = std::tolower(guess);

        if (std::isalpha(guess) && std::find(guessedLetters.begin(), guessedLetters.end(), guess) == guessedLetters.end()) {
            return guess;
        }

        std::cout << "Invalid guess or you've already guessed that letter. Try again.\n";
    }
}

void updateGameState(const std::string& chosenWord, std::string& displayedWord, char guess, int& incorrectGuesses) {
    if (chosenWord.find(guess) == std::string::npos) {
        incorrectGuesses++;
    } else {
        for (size_t i = 0; i < chosenWord.size(); ++i) {
            if (chosenWord[i] == guess) {
                displayedWord[i] = guess;
            }
        }
    }
}

void playGame() {
    Gallows gallows;
    int randomIndex = rand() % words.size();
    std::string chosenWord = words[randomIndex];
    std::string displayedWord(chosenWord.size(), 'X');
    std::vector<char> guessedLetters;
    int incorrectGuesses = 0;

    while (incorrectGuesses < MAX_GUESSES && displayedWord != chosenWord) {
        displayGameState(gallows, incorrectGuesses, displayedWord, guessedLetters);
        
        char guess = handleGuess(guessedLetters);
        guessedLetters.push_back(guess);
        
        updateGameState(chosenWord, displayedWord, guess, incorrectGuesses);
    }

    displayGameState(gallows, incorrectGuesses, displayedWord, guessedLetters);
    
    if (displayedWord == chosenWord) {
        std::cout << "Congratulations! You guessed the word: " << chosenWord << "\n";
    } else {
        std::cout << "Sorry, you lost! The word was: " << chosenWord << "\n";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));  // Seed random number generator

    std::cout << "Let's play Hangman!\n";
    char choice;
    do {
        playGame();
        std::cout << "Play again? (y/n): ";
        std::cin >> choice;
    } while (std::tolower(choice) == 'y');

    return 0;
}
