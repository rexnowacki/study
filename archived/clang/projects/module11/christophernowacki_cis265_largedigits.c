// Christopher Nowacki
// CIS 265
// Big Digits!
#include <stdio.h>
#include <ctype.h> // for isdigit

#define MAX_DIGITS 10

char digits[3][MAX_DIGITS * 4]; // Stores large digit representation

// String representations for digits 0-9
const char *digit_rep[10][3] = {
    {" _ ", "| |", "|_|"}, // 0
    {"   ", "  |", "  |"}, // 1
    {" _ ", " _|", "|_ "}, // 2
    {" _ ", " _|", " _|"}, // 3
    {"   ", "|_|", "  |"}, // 4
    {" _ ", "|_ ", " _|"}, // 5
    {" _ ", "|_ ", "|_|"}, // 6
    {" _ ", "  |", "  |"}, // 7
    {" _ ", "|_|", "|_|"}, // 8
    {" _ ", "|_|", " _|"}  // 9
};

// Clears the digits array by filling with spaces
void clear_digits_array(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < MAX_DIGITS * 4; j++) {
            digits[i][j] = ' ';
        }
    }
}

// Inserts the large digit representations into digits array
void process_digit(int digit, int position) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            digits[i][position * 4 + j] = digit_rep[digit][i][j];
        }
    }
}

// Displays big digits
void print_digits_array(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < MAX_DIGITS * 4; j++) {
            putchar(digits[i][j]);
        }
        putchar('\n');
    }
}

int main(void) {
    char input_char;
    int position = 0;
    // Initialize empty array
    clear_digits_array();
    printf("Enter a number: ");
    while ((input_char = getchar()) != '\n' && input_char != EOF && position < MAX_DIGITS) {
        if (input_char >= '0' && input_char <= '9') {
            process_digit(input_char - '0', position++);
        }  
      } 
    print_digits_array();

    return 0;
}
