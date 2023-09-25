// Christopher Nowacki
// CIS 278
// 5.12 -- Product of Odd Integers
#include <iostream>

using namespace std;
// Determine if integer is odd
bool is_odd(int n) {

  if (n % 2 != 0) {
    return true;
  }
  return false;
}

int main() {
  int product = 1;

  // Loop through 1-15
  for (int i = 1; i <= 15; ++i) {
    if (is_odd(i)) {
      // Multiply the product by current odd
      product *=i;
    }
  }
  // Output result
  cout << "The product of the odd integers from 1 to 15 is: " << product << endl;
  return 0;
}
