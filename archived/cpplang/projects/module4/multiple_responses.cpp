// Christopher Nowacki
// CIS 278 
// Elementary Multiplication Program w/ Multiple Responses 

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
  int random_correct;
  int random_wrong;

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
    // Uses another random integer and switch statements to vary 
    // positive feedback
    if (answer == number1 * number2) {
      int random_feedback = (rand() % 4) + 1;
      switch (random_feedback) {
        case 1:
          cout << "Very good!" << endl;
          break;
        case 2:
          cout << "Excellent!" << endl;
          break;
        case 3:
          cout << "Nice work!" << endl;
          break;
        case 4:
          cout << "Keep up the good work!" << endl;
          break;
      }
      cout << "Try another, or enter '-1' to exit." << endl;
      generate_question();
    }
    else if (answer == -1) {
      cout << "Goodbye." << endl;
      exit(0);
    }
    // If answer is incorrect, have them try again
    // Uses another random integer and switch statements to vary
    // feedback to try again
    else {
      int random_feedback = (rand() % 4) + 1;
      switch (random_feedback) {
        case 1:
          cout << "No. Please try again." << endl;
          break;
        case 2:
          cout << "Wrong. Try once more." << endl;
          break;
        case 3:
          cout << "Don't give up!" << endl;
          break;
        case 4:
          cout << "No, keep trying." << endl;
          break;
      }
    }
  }
}

int main() {
  srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
  generate_question(); // Generate question
  return 0; 
}
