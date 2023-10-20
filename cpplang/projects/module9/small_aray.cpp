
#include <iostream>
using namespace std;

int recursiveMinimum(const int arr[], int start, int end) {
    // Base case: If start equals end, return the element at that position
    if (start == end) {
        return arr[start];
    }

    // Recursive case: Find the minimum of the current element and the minimum of the rest of the array
    int minOfRest = recursiveMinimum(arr, start + 1, end);
    if (arr[start] < minOfRest) {
        return arr[start];
    } else {
        return minOfRest;
    }
}

int main() {
    int arr[] = {3, 13, 4, 10, 5, 9, 2, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum element in the array is: " << recursiveMinimum(arr, 0, size - 1) << endl;
    return 0;
}
