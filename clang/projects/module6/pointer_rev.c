
#include <stdio.h>

#define MAX_MESSAGE_LENGTH 1000  // Define the maximum message length

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char *current_position = message;  // Use a pointer to keep track of the current position

    printf("Enter a message: ");

    // Read characters one-by-one and store in the array
    while (current_position < message + MAX_MESSAGE_LENGTH - 1) {  // Use pointer arithmetic
        char ch = getchar();
        if (ch == '\n') {
            break;  // Stop reading if newline character is encountered
        }
        *current_position = ch;   // Use pointer dereference to assign character
        current_position++;       // Move the pointer to the next position
    }
    *current_position = '\0';  // Null-terminate the string

    printf("Reversed message: ");
    // Print the reversed message
    while (current_position > message) {  // Decrement pointer until we reach the beginning
        current_position--;  // Move the pointer backwards
        putchar(*current_position);  // Print the character the pointer currently points to
    }
    putchar('\n');

    return 0;
}
