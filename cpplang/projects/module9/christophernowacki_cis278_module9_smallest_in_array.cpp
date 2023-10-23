
#include <iostream>
using namespace std;

int recursive_minimum(const int arr[], int start, int end) {
    // If start equals end, return the element at that position
    if (start == end) {
        return arr[start];
    }

    // Recursive call: for next portion of the array
    int minOfRest = recursive_minimum(arr, start + 1, end);
    if (arr[start] < minOfRest) {
        return arr[start]; // Return current element if it is smallest
    } else {
        return minOfRest; // IF not, return the smallest number found
    }
}

int main() {
    int start, end;
    int arr[] = {3, 13, 4, 10, 5, 9, 2, 6, 5};
    // Get number of elements in array
    int size = sizeof(arr) / sizeof(arr[0]);
    start = 0;
    end = size - 1;
    // Call function to find smallest element of array and display result
    cout << "The minimum element in the array is: " << recursive_minimum(arr, start, end) << endl;
    return 0;
}
