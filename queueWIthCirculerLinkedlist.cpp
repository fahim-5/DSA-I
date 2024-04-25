#include <iostream>
using namespace std;

// Struct for a Node
struct Node {
    int data;
    Node* next;
};

// Global pointers for front and rear
Node* front = NULL;
Node* rear = NULL;

// Function to check if the queue is empty
bool isEmpty() {
    return front == NULL;
}

// Function to enqueue an element
void enqueue(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    rear->next = front;    // Circular linking.....here raer next will aways keep the head in it.
}

// Function to dequeue an element
int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    int x;
    if (front == rear) {        //if only one node
        x = front->data;
        delete front;          //removing the node
        front = rear = NULL;   //vaning the link lsit
    } else {
        Node* temp = front;      //this previous front
        x = temp->data;
        front = front->next;    // updaing the front
        rear->next = front;    // Circular linking.....updating the rare next
        delete temp;       //   deleting the previous front
    }
    return x;
}


// Function to display the queue
void displayQueue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    Node* temp = front;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);   // so it will print the whole link list with out repeating

    cout << endl;
}

// Main function
int main() {
    // Enqueue elements
    enqueue(10);
    enqueue(13);
    enqueue(7);
    enqueue(11);

    // Display the front element
    cout << "Front: " << front->data << endl;

    // Dequeue an element
    cout << "Dequeued element: " << dequeue() << endl;

    // Display the front element after dequeue
    cout << "Front after dequeue: " << front->data << endl;

    // Display the queue
    cout << "Queue: ";
    displayQueue();

    return 0;
}
