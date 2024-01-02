// Christopher Nowacki
// CIS 265
// Module 14 - Queue 
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Main function to test the queue
int main() {
    Queue q;
    initializeQueue(&q);
    int choice, value;
// MAin menu
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert an integer item to the end of the queue\n");
        printf("2. Remove an integer item from the beginning of the queue\n");
        printf("3. Display first item in the queue\n");
        printf("4. Display last item in the queue\n");
        printf("5. Display the count of items in the queue\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer value: ");
                scanf("%d", &value);
                addToQueue(&q, value);
                break;
            case 2:
                value = removeFromQueue(&q);
                if (value != -1) {
                    printf("Removed item: %d\n", value);
                }
                break;
            case 3:
                value = getFront(&q);
                if (value != -1) {
                    printf("First item: %d\n", value);
                }
                break;
            case 4:
                value = getRear(&q);
                if (value != -1) {
                    printf("Last item: %d\n", value);
                }
                break;
            case 5:
                printf("Queue size: %d\n", getQueueSize(&q));
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
