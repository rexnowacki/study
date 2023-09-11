// Christopher Nowacki
// CIS 265
// Chapter 7 Page 157, Project #4

// This program converts an alphanumeric phone number to numeric form.

#include <stdio.h>
#include <ctype.h>

int main(void) {

    // Declare char variable to store each character as it is read
    char c;

    printf("Enter phone number: ");
    // Loop to get characters until user presses "ENTER"
    while ((c = getchar()) != '\n') {
        // Convert lowercase characters to uppercase
        switch (toupper(c)) {
            // convert ABC to 2, DEF to 3, etc.
            case 'A': case 'B': case 'C':
                putchar('2');
                break;
            case 'D': case 'E': case 'F':
                putchar('3');
                break;
            case 'G': case 'H': case 'I':
                putchar('4');
                break;
            case 'J': case 'K': case 'L':
                putchar('5');
                break;
            case 'M': case 'N': case 'O':
                putchar('6');
                break;
            case 'P': case 'R': case 'S':
                putchar('7');
                break;
            case 'T': case 'U': case 'V':
                putchar('8');
                break;
            case 'W': case 'X': case 'Y':
                putchar('9');
                break;
            // Display other characters as they are, i.e. ! as !, - as -
            default:
                putchar(c);
                break;
        }
    }
    printf("\n");
    return 0;
}
