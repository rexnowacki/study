// Christopher Nowacki
// CIS 278
// 16.8 -- Duplicate Elimination 

#include <iostream>
#include <algorithm>
#include <iterator> // For ostream_iterator

using namespace std;

int main() {
    int numbers[20]; // Declare an array to store 20 integers

    cout << "Please enter 20 integers:" << endl;
    for (int i = 0; i < 20; ++i) {
        cin >> numbers[i]; // Read 20 integers from user input
    }
    
    // Sort the numbers
    sort(numbers, numbers + 20);
    
    // Remove duplicate numbers from array
    auto last_unique = unique(numbers, numbers + 20);
    
    // Get number of unique numbers and create new array
    int size_without_duplicates = last_unique - numbers;
    int unique_numbers[20];
    
    // Copy unique numbers to new array
    copy(numbers, numbers + size_without_duplicates, unique_numbers);

    // Display results using copy
    cout << "Unique numbers are:" << endl;
    copy(numbers, numbers + size_without_duplicates, ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
