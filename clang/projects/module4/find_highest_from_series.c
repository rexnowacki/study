// Christopher Nowacki
// CIS 265
// Largest Number from a Series

#include <stdio.h>

int main() {
  double number, largest;

  // Prompt user for input
  printf("Enter a number (enter a number equal to or less than 0 to quit): ");
  scanf("%lf", &number);

  // If the first number itself is negative or 0, ask again
  while (number <=0) {
    printf("Please enter a non-negative number to start with: ");
    scanf("%lf", &number);
  }

  largest = number; // Initialize largest with the first valid non-negative number

  // Loop to get numbers until 0 or a negative number is entered
  while (number > 0) {
    // If this number is greater than the number occupying largest, set largest
    // to current number
    if (number > largest) {
      largest = number;
    }
    // Prompt again
    printf("Enter another number (enter a number equal to or less than 0 to quit): ");
    scanf("%lf", &number);
  }

  // Display results
  printf("The largest non-negative number entered was: %.2lf\n", largest);
  return 0;
}
