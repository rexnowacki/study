// Christopher Nowacki
// CIS 265 
// State Income Tax Assignment
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  char input[20];
  int dollars, cents; 
  int income_cents, tax_cents;
  int read_values;

  // Read input as a string
  printf("Please enter your taxable income: ");
  scanf("%s", input);
  // Check the length of the Input
  if (strlen(input) > 100000000) {
    printf("That is too much money.");
    return 1;
  }

  // Check for letters in the input
  for (int i = 0; i < strlen(input); ++i) {
    if (!isdigit(input[i]) && input[i] != '.') {
      printf("Input contains invalid characters -- Aborting.");
      return 1;
    }
  }

  // Now convert string to numbers
  // If input is entered as "1000", set cents to 0
  read_values = sscanf(input, "%d.%d", &dollars, &cents);
  if (read_values == 1) {
    cents = 0;
  }
  // Disallow negative income
  if (dollars < 0 || cents < 0) {
    printf("Invalid input -- negative income reported.\n");
    return 1;
  }
  
  // Convert dollars to cents to avoid rounding errors with float/double
  income_cents = dollars * 100 + cents;
  // Calculate tax based on income tax brackets
  if (income_cents <= 75000) {
        tax_cents = income_cents / 100;
    } else if (income_cents <= 225000) {
        tax_cents = 750 + (income_cents - 75000) * 2 / 100;
    } else if (income_cents <= 375000) {
        tax_cents = 3750 + (income_cents - 225000) * 3 / 100;
    } else if (income_cents <= 525000) {
        tax_cents = 8250 + (income_cents - 375000) * 4 / 100;
    } else if (income_cents <= 700000) {
        tax_cents = 14250 + (income_cents - 525000) * 5 / 100;
    } else {
        tax_cents = 23000 + (income_cents - 700000) * 6 / 100;
    }
  // Display the claculated tax in dollars and cents
  printf("Your tax due is: $%d.%02d\n", tax_cents / 100, tax_cents % 100);
  return 0;
}
