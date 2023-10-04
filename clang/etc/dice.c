
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a 6-sided dice
int roll_dice() {
    return (rand() % 6) + 1;
}

int main(int argc, char *argv[]) {
    // Check if a command line argument is provided
    if (argc != 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Roll the three dice
    int dice1 = roll_dice();
    int dice2 = roll_dice();
    int dice3 = roll_dice();

    // Calculate the total
    int total = dice1 + dice2 + dice3;

    // Display the dice values and the total
    printf("Dice 1: %d\n", dice1);
    printf("Dice 2: %d\n", dice2);
    printf("Dice 3: %d\n", dice3);
    printf("Total: %d\n", total);

    // Display the appropriate message based on the total
    if (total == 17 || total == 18) {
        printf("%s lets you pound her tight pussy.\n", argv[1]);
    } else if (total >= 14 && total <= 16) {
        printf("%s puts her hair in a ponytail and drops to her knees.\n", argv[1]);
    } else {
        printf("%s isn't horny. Too bad bb\n", argv[1]);
    }

    return 0;
}
