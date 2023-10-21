// Christopher Nowacki
// CIS 265
// File IO Module 8
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// Searching for a Word and Highlighting it
void search_word(FILE *fp, char *word) {
    char temp[512];
    int count = 0;

    // Iterate through each line of the file
    while (fgets(temp, sizeof(temp), fp)) {
        char *start = temp, *pos;
        // Use strstr to search for specified word in complete string
        while ((pos = strstr(start, word)) != NULL) {
            *pos = '\0';  // Temporarily terminate the string at found word
            printf("%s[%s]", start, word);  // Print the string up to the word and then the word wrapped in []
            start = pos + strlen(word);  // Move past the word
            count++;  // Count each occurence
        }
        printf("%s", start);  // Print the rest of the line
    }
    printf("\nNumber of occurrences of the word \"%s\" is %d.\n", word, count);
}

// Display n Lines
void display_lines(FILE *fp, int num_lines) {
    char temp[512];
    int count = 0;
    // Loop to read and print lines from the file
    // Conditional on successful fget and count being less than requested number of lines
    while(fgets(temp, 512, fp) != NULL && count < num_lines) {
        printf("%s", temp);
        count++;
    }
}

// Clear input buffer
void clear_input_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Append text to file
void append_content(FILE *fp) {
    char temp[512]; 
    long file_size; // Variable to hold the size of the file

    // Clear the input buffer to remove any leftover characters
    clear_input_buffer();

    // Check if the file is not empty by getting file size
    fseek(fp, 0, SEEK_END); 
    file_size = ftell(fp);    // Get the file size
    if (file_size != 0) {
        fprintf(fp, "\n");  // Add a newline if file NOT empty
    }
    
    printf("Enter the content you want to append: ");
    fgets(temp, sizeof(temp), stdin);

    // Remove the newline character read by fgets
    size_t len = strlen(temp);
    // Check that string is not empty and that last charcter is \n
    if (len > 0 && temp[len - 1] == '\n') {
       temp[len - 1] = '\0';
    }

    fprintf(fp, "%s", temp);
}
int main() {
    FILE *fp;
    char choice;
    char word[100];
    int num_lines;

    do {
        printf("\nMenu:\n");
        printf("1. Press (S) to search for a word\n");
        printf("2. Press (L) to display specified number of text lines to the screen\n");
        printf("3. Press (A) to append new content to the file\n");
        printf("4. Press (Q) to quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        // Open file with read, write (append) permissions
        fp = fopen("CIS265.txt", "a+");
        if(fp == NULL) {
            printf("File could not be opened.\n");
            return 1;
        }

        switch(choice) {
            case 'S':
            case 's':
                printf("Enter the word you want to search for: ");
                scanf("%s", word);
                search_word(fp, word);
                break;
            case 'L':
            case 'l':
                printf("How many lines do you want to display? ");
                scanf("%d", &num_lines);
                display_lines(fp, num_lines);
                break;
            case 'A':
            case 'a':
                append_content(fp);
                break;
            case 'Q':
            case 'q':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
        // Close file
        fclose(fp);
    } while(choice != 'Q' && choice != 'q');

  return 0;
}

