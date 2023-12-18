// Christopher Nowacki
// CIS 265
// Exercise 9 on pp.526

#include <stdio.h>

// Count number of 1 bits in a byte (using loop)
int count_ones_a(unsigned char ch)
{
    int i, one_count = 0;
    for (i = 0; i < 8; i++) // Loop through each bit position
        if (ch & (1 << i))
            one_count++; // Increment count if bit is 1
    return one_count;
}

// Count the number of 1 bits in a byte without loop
int count_ones_b(unsigned char ch)
{
    return (ch & 1)
         + ((ch >> 1) & 1)
         + ((ch >> 2) & 1)
         + ((ch >> 3) & 1)
         + ((ch >> 4) & 1)
         + ((ch >> 5) & 1)
         + ((ch >> 6) & 1)
         + ((ch >> 7) & 1);
}

int main(void)
{
    unsigned char num;
    printf("\nEnter a value between 0 and 255: ");
    scanf(" %hhu", &num); // Read an unsigned char (byte) 
    printf("Number of 1 bits in %hhu: %d\n", num, count_ones_a(num));
    printf("Number of 1 bits in %hhu: %d\n\n", num, count_ones_b(num));
    return 0;
}
