// Christopher Nowacki
// CIS 278
// Palindrome Tester

#include <iostream>
#include <string>

using namespace std;

bool testPalindrome(const string& str, int start = 0, int end = -1) {
    // If end is default (-1), set it to the last character of the string
    if (end == -1) {
        end = str.length() - 1;
    }

    // Base case: If start index is greater than or equal to end index, return true
    if (start >= end) {
        return true;
    }
    // If characters at start and end are different, return false
    if (str[start] != str[end]) {
        return false;
    }
    // Recursive testPalindrome call
    return testPalindrome(str, start + 1, end - 1);
}

int main() {
    // Get user input and call testPalindrome
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    if (testPalindrome(input)) {
        cout << "\"" << input << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }
    return 0;
}
