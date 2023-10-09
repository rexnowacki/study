// Christopher Nowacki
// CIS 265 
// Message Reverser
#include <stdio.h>

int MAX_MESSAGE_LENGTH = 1000;  // maximum message length

int main() {
    char message[MAX_MESSAGE_LENGTH]; // Array to store message
    char *current_position = message;  // Pointer to track current_position
    printf("Enter a message: ");

    // Read message character by character until newline or maxlength
    while (current_position < message + MAX_MESSAGE_LENGTH - 1) {  
        char ch = getchar();
        if (ch == '\n') {
            break;  // Stop reading if newline
        }
        *current_position = ch;   // Store the chracater and move to next posititon
        printf("%s", message);
        current_position++;
    }
    *current_position = '\0';  // Null-terminator

    // printf("%s", message);
    printf("Reversed message: ");
    // Print the reversed message
    while (current_position > message) {
        current_position--;  // Move the pointer backwards
        putchar(*current_position);  // Print the character the pointer currently points to
    }
    printf("\n");

    return 0;
}
