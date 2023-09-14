
#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to generate a multiplication question
void generate_question() {
    int num1 = rand() % 10;
    int num2 = rand() % 10;
    int answer;

    while (true) {
        std::cout << "How much is " << num1 << " times " << num2 << "? ";
        std::cin >> answer;

        if (answer == num1 * num2) {
            std::cout << "Very good!\n";
            return;
        } else {
            std::cout << "No... please try again.\n";
        }
    }
}

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(0)));

    while (true) {
        generate_question();
    }

    return 0;
}
