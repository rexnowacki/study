
#include <iostream>

int main() {
    int n, num;
    int smallest;

   cout << "Enter the number of integers to compare: ";
   cin >> n;

    if (n <= 0) {
       cout << "You must enter a positive number for the number of integers to compare." <<endl;
        return 1;
    }

   cout << "Enter integer 1: ";
   cin >> smallest; // Initialize 'smallest' with the first number entered

    for (int i = 1; i < n; ++i) { // Start loop from 1 because we already have the first integer
       cout << "Enter integer " << (i + 1) << ": ";
       cin >> num;

        if (num < smallest) {
            smallest = num;
        }
    }

   cout << "The smallest integer is: " << smallest <<endl;

    return 0;
}
