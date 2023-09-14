// Christopher Nowacki || Cis 265
// Integer to Octal

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  char input[50];
  int user_input;
  int oct_digit1, oct_digit2, oct_digit3, oct_digit4, oct_digit5;

  printf("Enter a number between 0 and 32767: ");
  scanf("%s", input);

  // Check for letters in the input
  for (int i = 0; i < strlen(input); ++i) {
    if (input[i] == '-') {
      printf("Negative decimal to octal conversion not supported -- Aborting.\n");
      return 1;
    }
    if (!isdigit(input[i])) {
      printf("Input contains invalid characters -- Aborting.\n");
      return 1;
    }
  }

  // Convert the string back to numbers
  sscanf(input, "%d", &user_input);

  // Check if the number is within the specified range
  if (user_input < 0 || user_input > 32767) {
    printf("Number out of range.\n");
    return 1;
  }

  // Calculate the 5 octal digits from right to left
  // 1. Divide input by 8; remainder is 5th digit
  // 2. Divide input by 8 twice, remainder is 4th digit.
  // 3. Divide input by 8 thrice, remainder is 3rd digit.
  // 4. Divide input by 8 four times, remainder is 2nd digit.
  // 5. Divide input by 8 five times, remainder is 1st digit.
  oct_digit1 = user_input % 8;
  oct_digit2 = (user_input / 8) % 8;
  oct_digit3 = (user_input / 8 / 8) % 8;
  oct_digit4 = (user_input / 8 / 8 / 8) % 8;
  oct_digit5 = (user_input / 8 / 8 / 8 / 8) % 8;

  // Logic to remove leading 0's
  if (oct_digit5 != 0) { 
    printf("%d", oct_digit5);
  }
  printf("%d%d%d%d\n", oct_digit4, oct_digit3, oct_digit2, oct_digit1);
  
  // printf("In octal, your number is: %d%d%d%d%d\n", oct_digit5, oct_digit4, oct_digit3, oct_digit2, oct_digit1);

  return 0;
}
