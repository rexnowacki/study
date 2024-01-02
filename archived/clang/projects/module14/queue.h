
#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

// Define the structure for the queue node
typedef struct node {
    int data;
    struct node *next;
} Node;

// Define the structure for the queue
typedef struct {
    Node *front;
    Node *rear;
    int size;
} Queue;

// Function declarations
void initializeQueue(Queue *q);
bool isQueueEmpty(Queue *q);
void addToQueue(Queue *q, int value);
int removeFromQueue(Queue *q);
int getFront(Queue *q);
int getRear(Queue *q);
int getQueueSize(Queue *q);

// Initialize the queue
void initializeQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// Check if the queue is clear
bool isQueueEmpty(Queue *q) {
    return (q->size == 0);
}

// Add an element to the queue
void addToQueue(Queue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: unable to allocate memory.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    q->size++;
}

// Remove an element from the queue
int removeFromQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;
    return data;
}

// Get the front element of the queue
int getFront(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

// Get the rear element of the queue
int getRear(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->rear->data;
}

// Get the size of the queue (number of items in queue)
int getQueueSize(Queue *q) {
    return q->size;
}
#endif
