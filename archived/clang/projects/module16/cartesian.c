// Christopher Nowacki
// CIS 265
// Cartesian Polar

#include <stdio.h>
#include <math.h>
#include <complex.h>

int main() {
    double a, b; // Real and imaginary parts of the complex number
    double r, theta; // Radial Coordinate, Angular Coordinate

    // Prompt user to enter the real and imaginary parts
    printf("Enter the real part (a) of the complex number: ");
    scanf("%lf", &a);
    printf("Enter the imaginary part (b) of the complex number: ");
    scanf("%lf", &b);

    // Convert to polar form
    r = sqrt(a*a + b*b); // Radial Coordinate
    theta = atan2(b, a); // Angular Coordinate

    // Display the polar form
    printf("Polar form: r = %f, theta = %f radians\n", r, theta);

    return 0;
}
