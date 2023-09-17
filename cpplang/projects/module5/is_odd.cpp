#include <iostream>

using namespace std;

bool is_odd(int n) {
  return n % 2 != 0;
}

int main() {
  int product = 1;

  for (int i = 1; i <= 15; ++i) {
    if (is_odd(i)) {
      product *=i;
    }
  }
  cout << "The product of the odd integers from 1 to 15 is: " << product << endl;
  return 0;
}
