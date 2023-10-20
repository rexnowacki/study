
#include <iostream>
#include <stdexcept>
using namespace std;

void throwException(int choice) {
    switch (choice) {
        case 1:
            throw runtime_error("Runtime Error Exception");
        case 2:
            throw range_error("Range Error Exception");
        case 3:
            throw overflow_error("Overflow Error Exception");
        case 4:
            throw underflow_error("Underflow Error Exception");
        default:
            throw "Unknown Exception";
    }
}

int main() {
    for (int i = 1; i <= 5; i++) {
        try {
            cout << "Trying to throw exception #" << i << endl;
            throwException(i);
        }
        catch (...) {
            cout << "Exception caught using catch(...)" << endl;
        }
        cout << endl;
    }
    return 0;
}
