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
  int total_ints = get_integer_count();
  if (total_ints <= 0) {
    cout << "Please enter a positive integer." << endl;
    return 1;
  }
  int smallest = find_smallest(total_ints);
  cout << "The smallest integer is: " << smallest << endl;

  return 0;
}

bool check_data() {
  if (!cin) {
    cout << "Please enter an integer." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
  }
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
  while (true) {
    cout << "Enter the total number of integers to compare: ";
    cin >> total_ints;
    if (check_data()) break;
  }
  return total_ints;
}

int get_integer_input(int integer) {
  int number;
  while (true) {
    cout << "Enter integer " << integer << ": ";
    cin >> number;
    if (check_data()) break;
  }
  return number;
}

int find_smallest(int total_ints) {
  int smallest = get_integer_input(1);
  int number;

  for (int integer = 2; integer <= total_ints; ++integer) {
    number = get_integer_input(integer);
    if (number < smallest) {
      smallest = number;
    }
  }
  return smallest;
}
