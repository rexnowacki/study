// Christopher Nowacki
// CIS 265
// Compute a polynomial given input as x

#include <stdio.h>

// Function to compute the value of the polynomial
int compute_polynomial(int x) {
    return 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x - 6;
}

int main() {
    int x, polynomial_value;

    // Get x value from user
    printf("Enter a value for x: ");
    scanf("%d", &x);  // %lf is the format specifier for double

    // Call the function to compute the polynomial value
    polynomial_value = compute_polynomial(x);

    // Print polynomial
    printf("Given polynomial:\n");
    printf("3x⁵ + 2x⁴ - 5x³ - x² + 7x - 6\n");

    // Display results
    printf("The value of the polynomial for x = %d is: %d\n", x, polynomial_value);

    return 0;
}
