// Christopher Nowacki
// CIS 265
// Difference in Dates

#include <stdio.h>
#include <time.h>

int main() {
    struct tm date1 = {0}, date2 = {0};
    time_t time1, time2;
    double difference;

    // Prompt user to enter first date in MM/DD/YYYY format
    printf("Enter first date (MM/DD/YYYY): ");
    scanf("%d/%d/%d", &date1.tm_mon, &date1.tm_mday, &date1.tm_year);
    date1.tm_year -= 1900; // Adjust year
    date1.tm_mon -= 1; // Adjust month (January is 0)

    // Prompt user to enter second date in MM/DD/YYYY format
    printf("Enter second date (MM/DD/YYYY): ");
    scanf("%d/%d/%d", &date2.tm_mon, &date2.tm_mday, &date2.tm_year);
    date2.tm_year -= 1900; // Adjust year
    date2.tm_mon -= 1; // Adjust month

    // Convert struct tm to time_t
    time1 = mktime(&date1);
    time2 = mktime(&date2);

    // Calculate the difference in seconds and convert it to days
    difference = difftime(time2, time1) / (60 * 60 * 24);

    // Print the difference
    printf("Difference between the two dates is: %.0f days\n", difference);

    return 0;
}

