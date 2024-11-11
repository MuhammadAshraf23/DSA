#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE], head = -1, tail = -1;

void Enqueue(int x) {
    if (tail == SIZE - 1) {
        cout << "Queue is full.\n";
    } else {
        if (head == -1) {
            head = 0;
        }
        tail++;
        queue[tail] = x;
        cout << "Element added: " << queue[tail] << endl;
    }
}

void Dequeue() {
    if (head == -1) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Element deleted from queue: " << queue[head] << endl;
        if (head == tail) {
            head = -1;
            tail = -1;
        } else {
            head++;
        }
    }
}

int Peek() {
    if (head == -1) {
        cout << "Queue is empty.\n";
        return -1; // Return -1 to indicate an empty queue
    } else {
        return queue[head];
    }
}

int main() {
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5); 
    Dequeue();
    Dequeue();
    Dequeue();
    
    int y = Peek();
    if (y != -1) { 
        cout << "Peek value: " << y << endl;
    }
    
    return 0;
}
