#include <iostream>
#include <iomanip>

using namespace std;
int main() {
    // Print table header, field width 12 
    cout << setw(12) << "Decimal"
              << setw(12) << "Octal"
              << setw(12) << "Hexadecimal"
              << setw(12) << "Character"
              << endl;
    cout << "------------------------------------------------" << endl;
    for (int i = 33; i <= 126; ++i) {
        // Decimal
        cout << setw(12) << dec << i;
        // Octal
        cout << setw(12) << oct << i;
        // Hex
        cout << setw(12) << hex << i;
        // Print character
        cout << setw(12) << (char)i << endl;
    }

    return 0;
}

