// Christopher Nowacki
// CIS 265
// Word Sort with Pointers 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_WORDS 100 // Max words
#define MAX_WORD_SIZE 20 // Maximum size of each word

int read_line(char str[], int word_size) { 
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < word_size) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}

int word_compare(const void *first_word, const void *second_word) {
    // Convert to character pointers
    const char *word_a = *(const char **)first_word;
    const char *word_b = *(const char **)second_word;
   // Return negative value is first word should come before second word
   // Return positive value is second word should come before second word
   // Return 0 if words are the same
    return strcmp(word_a, word_b);
}

int main(void) {
    char *word_list[MAX_WORDS];
    int word_count = 0;
    char buffer[MAX_WORD_SIZE + 1];

    // Infinite loop: Prompt until empty line and ENTER
    for (;;) {
        printf("Enter word: ");
        read_line(buffer, MAX_WORD_SIZE);
        if (strlen(buffer) == 0) {
            break;
        }

        // Dynamically allocate memory for the word and copy the content from buffer
        word_list[word_count] = malloc(strlen(buffer) + 1);
        // If allocation fails
        if (word_list[word_count] == NULL) {
            printf("Memory allocation failed. Exiting...\n");
            exit(EXIT_FAILURE);
        }
        // Copy string from buffer into array
        strcpy(word_list[word_count], buffer);

        word_count++;
    }

    // Sort the list of words using qsort
    qsort(word_list, word_count, sizeof(char *), word_compare);

    // Display the sorted list of words
    printf("\nIn sorted order: ");
    for (int i = 0; i < word_count; i++) {
        printf("%s ", word_list[i]);
        free(word_list[i]);
    }
    printf("\n");

    return 0;
}


