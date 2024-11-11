#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr; // Front of the queue
Node* rear = nullptr;  // Rear of the queue

// Function to add an element to the queue (enqueue)
void Enqueue(int x) {
    Node* newNode = new Node(); // Create a new node
    if (!newNode) {
        cout << "Memory allocation failed!" << endl;
        return;
    }

    newNode->data = x;
    newNode->next = nullptr;

    // If the queue is empty, the new node will be both the front and the rear
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode; // Link the new node after the current rear
        rear = newNode;       // Move the rear pointer to the new node
    }

    cout << "Element added: " << x << endl;
}

// Function to remove an element from the queue (dequeue)
void Dequeue() {
    if (front == nullptr) {
        cout << "Queue is empty.\n";
    } else {
        Node* temp = front; // Store the current front node
        cout << "Element deleted from queue: " << front->data << endl;

        front = front->next; // Move the front pointer to the next node

        // If the queue becomes empty, set rear to nullptr
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp; // Deallocate memory of the old front node
    }
}

// Function to peek at the front element of the queue
int Peek() {
    if (front == nullptr) {
        cout << "Queue is empty.\n";
        return -1; // Return -1 to indicate an empty queue
    } else {
        return front->data;
    }
}

int main() {
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    Enqueue(6);
    Enqueue(7);

    Dequeue();
    Dequeue();
    Dequeue();

    int y = Peek();
    if (y != -1) {
        cout << "Peek value: " << y << endl;
    }

    return 0;
}
