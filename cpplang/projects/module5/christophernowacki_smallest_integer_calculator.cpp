// Christopher Nowacki
// CIS 278 -- Module 5
// Integer Comparison Tool

#include <iostream>
#include <limits>

using namespace std;

bool check_data();
int get_integer_count();
int get_integer_input(int integer);
int find_smallest(int total_ints);

int main() {
  // Calls function to get integer count and assigns to total_ints
  int total_ints = get_integer_count();
  if (total_ints <= 0) {
    cout << "Please enter a positive integer." << endl;
    return 1;
  }
  // Calls function to find smallest integer, assigns to smallest
  int smallest = find_smallest(total_ints);
  cout << "The smallest integer is: " << smallest << endl;

  return 0;
}

// Data Validation to disallow strings & doubles/floats
bool check_data() {
  if (!cin) {
    cout << "Please enter an integer." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
  }
  // Checks if data entered was a float by finding decimal
  else if (cin.peek() == '.') {
    cout << "Please enter an integer." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
  }
  return true;
}

int get_integer_count() {
  int total_ints;
  // Ask the user for the numbers of integers to be compared
  while (true) {
    cout << "Enter the total number of integers to compare: ";
    cin >> total_ints;
    // Exit loop if data validation check passes
    if (check_data()) break;
  }
  return total_ints;
}

int get_integer_input(int integer) {
  int number;
  // One by one, ask for integers to compare
  while (true) {
    cout << "Enter integer " << integer << ": ";
    cin >> number;
    if (check_data()) break; // Exit loop if data validation passes
  }
  return number;
}

int find_smallest(int total_ints) {
  // Initializes smallest with integer #1
  int smallest = get_integer_input(1);
  int number; // used to compare against smallest

  // Loops while current integer is less than total_ints (expected inputs)
  for (int integer = 2; integer <= total_ints; ++integer) {
    number = get_integer_input(integer);
    // Set number to smalllest if it is lower than current smallest
    if (number < smallest) {
      smallest = number;
    }
  }
  return smallest;
}
