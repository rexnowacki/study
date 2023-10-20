// Christopher Nowacki
// CIS 265
// Smallest Word, Largest Word
//
#include <stdio.h>
#include <string.h>

// Constant to hold max buffer size
#define MAX_LENGTH 20

// Function to clear input buffer -- was having issues with data validation
void clear_input_buffer() {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF);
}

// Arrays to contain word, smallest word, and largest word (alphabetically)
int main() {
  char word[MAX_LENGTH + 1];
  char smallest_word[MAX_LENGTH + 1] = "";
  char largest_word[MAX_LENGTH + 1] = "";

// Infinite loop for input and comparison
for(;;) {
    printf("Enter word: ");
    scanf("%20s", word); // Reads up to 20 characters

    // Check if word is 4-letters long
    if (strlen(word) == 4) {
      if (getchar() == '\n') { // Ensure there are no trailing characters
        printf("\nFour letter word detected. Here are your results:");
        break;
      }
      printf("Error: Words should not include any whitespace.\n");
      clear_input_buffer();
      continue;
    }

    // Check for spaces or words longer than buffer by looking for null term & line end
    if (word[MAX_LENGTH - 1] != '\0' || getchar() != '\n') {
      if (word[MAX_LENGTH - 1] != '\0') {
        printf("Error: Please enter words with a length shorter than twenty (20) characters.\n");
      } else {
        printf("Error: Words should not include any whitespace. If necessary, hyphenate.\n");
      }
      clear_input_buffer();
      continue;
    }

    // If smallest_word is empty or new_word is smallest 
    if (strcmp(smallest_word, "") == 0 || strcmp(word, smallest_word) < 0) {
        strcpy(smallest_word, word);
    }

    // Same but for largest word
    if (strcmp(largest_word, "") == 0 || strcmp(word, largest_word) > 0) {
        strcpy(largest_word, word);
    }
}
  // Display output
  printf("\nSmallest word: %s\n", smallest_word);
  printf("Largest word: %s\n", largest_word);

  return 0;
}
