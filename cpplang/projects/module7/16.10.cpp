// Christopher Nowacki
// CIS 278
// Display Vector Contents from File
#include <iostream>
#include <fstream> // to read from text file
#include <vector>
#include <iterator> // for istream/ostream
#include <algorithm> // for copy

using namespace std;

int main() {
    ifstream input_file("int_data.txt"); // text file with integers separated by whitespace

    // Check if the file was successfully opened
    if (!input_file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Use istream_iterator to read integers from the int_data.txt
    istream_iterator<int> start(input_file), end;

    // Vector to store the int values
    vector<int> numbers;

    // Using copy algorithm and back_inserter to put file's contents into the vector
    copy(start, end, back_inserter(numbers));

    // Displaying the vector's content
    copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
