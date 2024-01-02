// Christopher Nowacki
// CIS 265
// Bitwise Operator sWap
#include <stdio.h>

unsigned short swap_bytes(unsigned short i) {
    // Swap the bytes of 'i' by shifting and recombining them using bitwise operations
    return (i >> 8) | (i << 8);
}

int main() {
    unsigned short number, swapped;
    
    // Get user input
    printf("Enter a hexadecimal number (up to four digits): ");
    scanf("%hx", &number);
    
    // Call swap_bytes function with entered number
    swapped = swap_bytes(number);

    printf("Number with bytes swapped: %hx\n", swapped);

    return 0;
}
