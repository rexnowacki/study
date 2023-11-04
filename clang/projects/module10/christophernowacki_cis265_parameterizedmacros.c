// Christopher Nowacki
// CIS 265
// PArameterized Macros
#include <stdio.h>

// Macros
#define CHECK(x, y, n) ((x) >= 0 && (x) < (n) && (y) >= 0 && (y) < (n) ? 1 : 0)
#define MEDIAN(x, y, z) ((x) > (y) ? ((x) < (z) ? (x) : ((y) > (z) ? (y) : (z))) : ((x) > (z) ? (x) : ((y) < (z) ? (y) : (z))))
#define POLYNOMIAL(x) (3*(x)*(x)*(x)*(x)*(x) + 2*(x)*(x)*(x)*(x) - 5*(x)*(x)*(x) - (x)*(x) + 7*(x) - 6)

int main() {
    int choice;

    printf("Choose a function:\n");
    printf("1. Check\n");
    printf("2. Median\n");
    printf("3. Polynomial\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);

    // Check
    switch (choice) {
        case 1:
        {
            int x, y, z;
            printf("Enter integer x: ");
            scanf("%d", &x);
            printf("Enter integer y: ");
            scanf("%d", &y);
            printf("Enter (max) integer z: ");
            scanf("%d", &z);
            
            if(CHECK(x, y, z)) {
                printf("(%d, %d) are within the range 0 to %d\n", x, y, z-1);
            } else {
                printf("(%d, %d) are NOT within the range 0 to %d\n", x, y, z-1);
            }
            break;
        }
        // Median
        case 2:
        {
            int a, b, c;
            printf("Enter integer a: ");
            scanf("%d", &a);
            printf("Enter integer b: ");
            scanf("%d", &b);
            printf("Enter integer c: ");
            scanf("%d", &c);
            
            printf("The median of %d, %d, and %d is: %d\n", a, b, c, MEDIAN(a, b, c));
            break;
        }
        case 3:
        // Polynomial
        {
            double x_value;
            printf("Enter a double value for x: ");
            scanf("%lf", &x_value);
            
            printf("The polynomial value for x=%f is: %.2f\n", x_value, POLYNOMIAL(x_value));
            break;
        }
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
