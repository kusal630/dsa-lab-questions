#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front; // Pointer to the front (head) of the queue
    Node* rear;  // Pointer to the rear (tail) of the queue

public:
    // Constructor: initializes an empty queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor: deallocates any remaining nodes
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Enqueue operation: adds an element to the rear of the queue.
    // Time Complexity: O(1)
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        // If the queue is empty, new node becomes both front and rear.
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << value << " successfully.\n";
    }

    // Dequeue operation: removes an element from the front of the queue.
    // Time Complexity: O(1)
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Nothing to dequeue.\n";
            return;
        }
        Node* temp = front;
        int removedValue = front->data;
        front = front->next;
        // If the queue becomes empty, update rear as well.
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        cout << "Dequeued " << removedValue << " successfully.\n";
    }

    // Peek operation: shows the front element without removing it.
    // Time Complexity: O(1)
    void peek() const {
        if (front == nullptr) {
            cout << "Queue is empty. Nothing to peek.\n";
            return;
        }
        cout << "Front element is: " << front->data << "\n";
    }

    // Optional: Display all elements in the queue for clarity.
    void display() const {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter an integer to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        // Optionally display the queue after each operation.
        q.display();
    } while (choice != 4);

    return 0;
}
