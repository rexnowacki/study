// Christopher Nowacki
// CIS 278
// 16.9 -- Duplicate Elimination

#include <iostream>
#include <algorithm>
#include <iterator> // For ostream_iterator
#include <vector>

using namespace std;

int main() {
    int numbers[20]; // Declare an array to store 20 integers

    cout << "Please enter 20 integers:" << endl;
    for (int i = 0; i < 20; ++i) {
        cin >> numbers[i]; // Read 20 integers from user input
    }
    
    // Sort the numbers
    sort(numbers, numbers + 20);
   
    // Empty vector to store unique numbers and copy uniques to vector
    vector<int> unique_numbers;
    unique_copy(numbers, numbers + 20, back_inserter(unique_numbers));
    
    // Display results using copy
    cout << "Unique numbers are:" << endl;
    copy(unique_numbers.begin(), unique_numbers.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
