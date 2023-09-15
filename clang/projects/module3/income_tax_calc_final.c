// Christopher Nowacki
// CIS 265
// State Income Tax Assessment Assignment
//
// This program takes input from the user (income), ensures that the input is valid, 
// and computes the taxable amount and displays this information to the user.

#include <stdio.h>
#include <ctype.h>

int main(void) {
  float income, tax;
  // Used to verify successful scanf
  int validate;
  printf("Enter taxable income: ");
  // Get user input and confirm that response was scanned as float
  validate = scanf("%f", &income);
  
  // Invalidate responses with non-digits
  if (validate != 1) {
    printf("Non-digits entered -- Aborting.\n");
    return 1;
  }
  
// Invalidate responses with negative incomes
  if (income < 0) {
    printf("Negative income entered -- Aborting.\n");
    return 1;
  }
  // Calculate taxable amount 
  if (income <= 750.00f)
        tax = .01f * income;
    else if (income <= 2250.00f)
        tax = 7.50f + (.02f * (income - 750.00f));
    else if (income <= 3750.00f)
        tax = 37.50f + (.03f * (income - 2250.00f));
    else if (income <= 5250.00f)
        tax = 82.50f + (.04f * (income - 3750.00f));
    else if (income <= 7000)
        tax = 142.50f + (.05f * (income - 5250.00f));
    else
        tax = 230.00f + (.06f * (income - 7000.00f));

    // Display tax due
    printf("Tax due: $%.2f\n", tax);
    return 0;
}
