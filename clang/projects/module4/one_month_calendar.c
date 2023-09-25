// Christopher Nowacki
// CIS 265
// Calendar Program -- Module 4
#include <stdio.h>

int main(void) {
    // Declare integers total_days, day, weekday, position
    int total_days, day, weekday, position;
    // Get number of days in month, assign to total_days
    printf("Enter number of days in month: ");
    scanf("%d", &total_days);
    // Get starting day of the week, assign to weekday
    printf("Enter starting day of the week (1=Mon, 7=Sun): ");
    scanf("%d", &weekday);
    // Print Header
    printf("\n Mo Tu We Th Fr Sa Su\n");
    // Loop for printing calendar to terminal
    for (position = 1, day = 1; position <= total_days + weekday - 1; position++) {
        if (position < weekday)
            printf("   ");
        else
            printf("%3d", day++);
        if (position % 7 == 0)
            printf("\n");
    }

    printf("\n");
    return 0;
}
