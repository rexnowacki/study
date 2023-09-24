// Christopher Nowacki
// CIS 265
// Project Name

// Write a program that prints a one-month calnedar. The user specifies
// the number of days in the month and the day of the week on which the
// month begins:
//      Enter number of days in the month: 31
//      Enter starting day of the week (1=Sun, 7=Sat): 3
//
//             1  2  3  4  5
//       6  7  8  9 10 11 12
//      13 14 15 16 17 18 19
//      20 21 22 23 24 25 26
//      27 28 29 30 31

// This Needs Work ** 

#include <stdio.h>

int main() {
  int days, start_day;
  int friday_13th;
  printf("Enter number of days in the month: ");
  scanf("%d", &days);

  printf("Enter starting day of the week (1=Sun, 2=Mon, 3=Tue, 4=Wed, 5=Thu, 6=Fri, 7=Sat): ");
  scanf("%d", &start_day);

  // Print the header for the calendar
  printf("\n");

    // Print leading spaces for the first week
  for (int i = 0; i < start_day; i++) {
    printf("    ");
  }

  // Print the days
  for (int day = 1; day <= days; day++) {
    printf("%3d ", day);

    // Detect Jason Voorhes
    if(day == 13 && (day + start_day) % 7 == 6) {
      friday_13th = 1;
    } 

    // If the day is a SAturday or the last day of the month, print newline
    if ((day + start_day) % 7 == 0 || day == days) {
      printf("\n");
    }
  }
  // Warn user of Spooky Szn
  if (friday_13th) {
    printf("Beware! Friday falls on the 13th this month.");
  }

  return 0;
}
