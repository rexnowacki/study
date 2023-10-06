
#include <stdio.h>

#define MAX_MESSAGE_LENGTH 1000  // Define the maximum message length

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int length = 0;  // Actual message length

    printf("Enter a message: ");

    // Read characters one-by-one and store in the array
    while (length < MAX_MESSAGE_LENGTH - 1) {
        char ch = getchar();
        if (ch == '\n') {
            break;  // Stop reading if newline character is encountered
        }
        message[length] = ch;
        length++;
    }
    message[length] = '\0';  // Null-terminate the string

    printf("Reversed message: ");
    // Print the reversed message
    for (int i = length - 1; i >= 0; i--) {
        putchar(message[i]);
    }
    putchar('\n');

    return 0;
}
