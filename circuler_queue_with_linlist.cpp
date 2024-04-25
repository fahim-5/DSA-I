#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Function to check if the queue is empty
int isEmpty() {
    return (front == NULL && rear == NULL);
}

// Function to enqueue an element
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    rear->next = front; // Making the queue circular
    printf("%d enqueued to queue.\n", value);
}

// Function to dequeue an element
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    int value = front->data;
    struct Node* temp = front;
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front; // Maintaining circularity
    }
    free(temp);
    printf("%d dequeued from queue.\n", value);
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main() {
    // Enqueue elements
    enqueue(10);
    enqueue(20);
    enqueue(30);

    // Display elements
    display();

    // Dequeue elements
    dequeue();
    dequeue();

    // Display elements after dequeue
    display();

    return 0;
}
