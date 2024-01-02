// *** Printing a string backwards:
// Write a program that inputs a string and prints the string backward. Convert all uppercase
// characters to lowercase and all lowercase characters to uppercase.
//

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
    // Input the string
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    // Use a string stream to process the string
    std::stringstream ss;
    for (char c : input) {
        if (std::isupper(c)) {
            ss << (char)std::tolower(c);
        } else if (std::islower(c)) {
            ss << (char)std::toupper(c);
        } else {
            ss << c;
        }
    }

    // Get the processed string and reverse it
    std::string result = ss.str();
    std::reverse(result.begin(), result.end());

    std::cout << "Reversed and modified string: " << result << std::endl;

    return 0;
}
