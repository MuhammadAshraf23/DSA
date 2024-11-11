#include <iostream>
using namespace std;

// Define a Node class to represent each node in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Define a LinkedList class to manage the linked list
 class LinkedList {
public:
    Node* head;

    // Constructor to initialize the list as empty
    LinkedList() {
        head = nullptr;
    }

    // Function to append a node at the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a node at a specific position
    void insertAtPosition(int value, int position) {
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < position; i++) {
            if (temp == nullptr) {
                cout << "Position out of range\n";
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete a node at the beginning of the list
    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Function to delete a node at a specific position
    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        if (position == 0) {
            head = head->next;
            delete temp;
            return;
        }

        for (int i = 1; i < position; i++) {
            if (temp == nullptr || temp->next == nullptr) {
                cout << "Position out of range\n";
                return;
            }
            temp = temp->next;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Function to display the entire linked list
    void displayList() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Destructor to clean up memory
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function to test the linked list operations
int main() {
    LinkedList list;

    // Test append and display
    list.append(10);
    list.append(20);
    list.append(30);
    cout << "List after append operations: ";
    list.displayList();

    // Test insert at the beginning
    list.insertAtBeginning(5);
    cout << "List after inserting at the beginning: ";
    list.displayList();

    // Test insert at a specific position
    list.insertAtPosition(15, 2); // Insert 15 at position 2
    cout << "List after inserting 15 at position 2: ";
    list.displayList();

    // Test delete at the beginning
    list.deleteAtBeginning();
    cout << "List after deleting at the beginning: ";
    list.displayList();

    // Test delete at a specific position
    list.deleteAtPosition(2); // Delete the node at position 2
    cout << "List after deleting at position 2: ";
    list.displayList();

    return 0;
}
