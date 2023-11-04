// Christopher Nowacki
// CIS 265
// DISP and DISP2
#include <stdio.h>
#include <math.h>   // Include for math functions

// Macro to display the result of a single-argument function
#define DISP(f, x) printf(#f "(%f) = %f\n", x, f(x))

// Macro to display the result of a two-argument function
#define DISP2(f, x, y) printf(#f "(%f, %f) = %f\n", x, y, f(x, y))

// returns the sum of two doubles
double double_sum(double a, double b) {
    return a + b;
}

int main() {
    DISP(sqrt, 16.0);             // Display sqrt of 3.0
    DISP2(double_sum, 3.0, 4.0);  // Display double sum with 3.0 and 4.0
    return 0;
}

