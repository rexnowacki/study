
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

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

    // Data validation
    if (!cin) {
      cout << "Please enter an integer." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    if (answer == number1 * number2) {
      int random_correct = (rand() % 4) + 1;
      switch (random_correct) {
        case 1:
          cout << "Very good!" << endl;
          break;
        case 2:
          cout << "How nice!" << endl;
          break;
        case 3:
          cout << "Super job!" << endl;
          break;
        case 4:
          cout << "Well done steakboy!" << endl;
          break;
      }
      cout << "Try another, or enter '-1' to exit." << endl;
      generate_question();
    }
    else if (answer == -1) {
      cout << "Goodbye." << endl;
      exit(0);
    }
    else {
      int random_wrong = (rand() % 4) + 1;
      switch (random_wrong) {
        case 1:
          cout << "No. Please try again." << endl;
          break;
        case 2:
          cout << "Be smart man!" << endl;
          break;
        case 3:
          cout << "Ohh so close!" << endl;
          break;
        case 4:
          cout << "Shoulda had the lasagna!" << endl;
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
