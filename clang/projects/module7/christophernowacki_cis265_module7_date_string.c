// Christopher Nowacki
// CIS 265
// Date to String

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables for user input
    int day, year, month;

    // Array of pointers to strings holding month names.
    // Using "None" at index[0] allows month int to match up with month string (1 for January, etc.)
    char *months[] = {"None", "January", "February", "March", "April", "May", 
                      "June", "July", "August", "September", "October", "November", "December"};
    
    // Prompt the user to enter a date
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    // Check if the entered month and day are valid
    // Month must be between 1-12
    // Day must be between 1-31
    // Year must be between 1000-9999
    if(month < 1 || month > 12 || day < 1 || day > 31 || year < 1000 || year > 9999) {
        printf("Invalid date entered.\n");
        return 1;
    }

    // Display the entered date in the desired format
    printf("You entered the date %s %d, %d\n", months[month], day, year);
    return 0;
}

