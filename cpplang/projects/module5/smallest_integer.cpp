// 1. get user input with the n integers 
// 2. run algorithm to determine smallest integer
// 2a. compare int_a and int_b, set smallest_int = lesser
// 2b. compare smallest_int and int_c, set smallest_int = lesser
// 3. display results


#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

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

// This function will determine the smallest integer and return it 
int find_smallest(int integer_a, int integer_b, int integer_c, int integer_d, int integer_e) {
  
  // Declare variables
  int smallest_integer = integer_a;

  // Compare each integer to the previous smallest integer to determine
  // the smallest int
  if (integer_b < smallest_integer) smallest_integer = integer_b;
  if (integer_c < smallest_integer) smallest_integer = integer_c;
  if (integer_d < smallest_integer) smallest_integer = integer_d;
  if (integer_e < smallest_integer) smallest_integer = integer_e;

  return smallest_integer;
}


int main() {
  int integer_a, integer_b, integer_c, integer_d, integer_e;
  
  // Obtain user input
  while (true) {
    cout << "Please enter integer #1: ";
    cin >> integer_a;
    if (check_data()) break;
  }
  
  while (true) { 
    cout << "Please enter integer #2: ";
    cin >> integer_b;
    if (check_data()) break;
  }
  
  while (true) {
    cout << "Please enter integer #3: ";
    cin >> integer_c;
    if (check_data()) break;
  }

  while (true) {
    cout << "Please enter integer #4: ";
    cin >> integer_d;
    if (check_data()) break;
  }

  while (true) {
    cout << "Please enter integer #5: ";
    cin >> integer_e;
    if (check_data()) break;
  }

  // Get smallest integer and display it
  int smallest_integer = find_smallest(integer_a, integer_b, integer_c, integer_d, integer_e);
  cout << "The smallest integer is: " << smallest_integer << endl;

  return 0;
}
