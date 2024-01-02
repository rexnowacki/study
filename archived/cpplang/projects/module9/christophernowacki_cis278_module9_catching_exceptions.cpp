// Christopher Nowacki
// CIS 278
// Catch(...)ing exceptions

#include <iostream>
#include <stdexcept> // For exceptions
using namespace std;

// This function throws exceptions
void throwException(int choice) {
    switch (choice) {
        case 1:
            throw runtime_error("Runtime Error Exception");
        case 2:
            throw bad_alloc();
        case 3:
            throw overflow_error("Overflow Error Exception");
        case 4:
            throw invalid_argument("Underflow Error Exception");
        default:
            throw "Unknown Exception";
    }
}

int main() {
    for (int i = 1; i <= 5; i++) {
        try {
            cout << "Trying to throw exception #" << i << endl;
            throwException(i); // call function to throw exception
        }
        catch (...) { // catch handler for any exception
            cout << "Exception caught using catch(...)" << endl;
        }
        cout << endl;
    }
    return 0;
}
