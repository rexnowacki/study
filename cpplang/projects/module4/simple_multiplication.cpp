
#include <iostream>
#include <cstdlib> // Used for exit()
#include <ctime>
#include <limits> // Used for numeric_limits in data validation codeblock

using namespace std;

// Prototypes 
void ask_question(int number1, int number2);
void generate_question();

// Generates question and calls function that handles ask/answer
void generate_question() {
  int number1 = rand() % 10;
  int number2 = rand() % 10;
  ask_question(number1, number2);
}

// Asks and grades question
void ask_question(int number1, int number2) {
  int answer;
  while (true) {
    cout << "What is " << number1 << " times " << number2 << "? ";
    cin >> answer;
    
    // Attempted data validation
    // via: https://www.codespeedy.com/taking-only-integer-input-in-cpp/
    if (!cin) {
      cout << "Please enter an integer." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    // If answer is correct, offer another question or optiont to exit
    if (answer == number1 * number2) {
      cout << "Very good!" << endl;
      cout << "Try another, or enter '-1' to exit." << endl;
      generate_question();
    }
    else if (answer == -1) {
      cout << "Goodbye." << endl;
      exit(0);
    }
    // If wrong, do nothing (continues loop)
    else {
      cout << "No. Please try again." << endl;
    }
  }
}

int main() {
  srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
  generate_question(); // Generate question
  return 0;
}
