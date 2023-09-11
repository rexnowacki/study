
// Christopher Nowacki
// CIS 265
// Chapter 3, pp.50, #3

// This program displays data related to the five groups of an ISBN. 

#include <stdio.h>

int main(void)
{
	// Declare variables
	int gs1_prefix, group_id, publisher_code, item_num, check_digit;
	
	// Get user input for ISBN (codes separated by hyphens)
	printf("Enter ISBN: ");
	scanf("%d -%d -%d -%d -%d", &gs1_prefix, &group_id, &publisher_code, &item_num, &check_digit);

	// Display results
	printf("GS1 prefix: %d\n"
		"Group identifier: %d\n"
        	"Publisher code: %d\n"
        	"Item number: %d\n"
        	"Check digit: %d\n",
            	gs1_prefix, group_id, publisher_code, item_num, check_digit);

	return 0;
}
