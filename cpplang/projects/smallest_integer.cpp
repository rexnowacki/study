
#include <iostream>

int main() {
    int n, num;
    int smallest;

    std::cout << "Enter the number of integers to compare: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "You must enter a positive number for the number of integers to compare." << std::endl;
        return 1;
    }

    std::cout << "Enter integer 1: ";
    std::cin >> smallest; // Initialize 'smallest' with the first number entered

    for (int i = 1; i < n; ++i) { // Start loop from 1 because we already have the first integer
        std::cout << "Enter integer " << (i + 1) << ": ";
        std::cin >> num;

        if (num < smallest) {
            smallest = num;
        }
    }

    std::cout << "The smallest integer is: " << smallest << std::endl;

    return 0;
}
