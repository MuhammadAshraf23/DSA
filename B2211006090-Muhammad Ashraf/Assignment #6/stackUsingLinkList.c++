#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr; // Initially the stack is empty

// Function to push an element onto the stack
void push(int x) {
    Node* newNode = new Node(); // Create a new node
    if (!newNode) {
        cout << "Memory allocation failed!" << endl;
        return;
    }

    newNode->data = x; // Set the data of the new node
    newNode->next = top; // Point the new node to the current top node
    top = newNode; // Move the top pointer to the new node
}

// Function to display the elements of the stack
void display() {
    if (top == nullptr) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack elements are: \n";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == nullptr) {
        cout << "Stack is empty!" << endl;
    } else {
        Node* temp = top;
        cout << "The popped element is: " << top->data << endl;
        top = top->next; // Move the top pointer to the next node
        delete temp; // Deallocate the memory of the popped node
    }
}

// Function to get the top element without removing it
int peek() {
    if (top != nullptr) {
        return top->data;
    }
    cout << "Stack is empty!" << endl;
    return -1; // Return -1 if stack is empty
}

int main() {
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);
    
    display();

    pop();
     pop();

    int y = peek();
    if (y != -1) {
        cout << "Top element is: " << y << endl;
    }

    return 0;
}
