#include <iostream>
using namespace std;

class CircularQueue {
private:
    static const int SIZE = 5;
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() : front(-1), rear(-1) {}

    // Enqueue: Adds an element to the circular queue.
    // Time Complexity: O(1)
    void enqueue(int value) {
        // Check if the queue is full
        if ((rear + 1) % SIZE == front) {
            cout << "Circular Queue is full. Cannot enqueue " << value << ".\n";
            return;
        }

        // First element condition
        if (front == -1) {
            front = 0;
        }

        // Update rear in circular fashion and insert value
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        cout << "Enqueued " << value << " successfully.\n";
    }

    // Dequeue: Removes an element from the circular queue.
    // Time Complexity: O(1)
    void dequeue() {
        if (front == -1) {
            cout << "Circular Queue is empty. Nothing to dequeue.\n";
            return;
        }

        int removedValue = arr[front];
        // Only one element in the queue
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        cout << "Dequeued " << removedValue << " successfully.\n";
    }

    // Peek: Shows the element at the front without removing it.
    // Time Complexity: O(1)
    void peek() const {
        if (front == -1) {
            cout << "Circular Queue is empty. Nothing to peek.\n";
            return;
        }
        cout << "Front element is: " << arr[front] << "\n";
    }

    // Display: Shows all elements in the circular queue (for clarity).
    void display() const {
        if (front == -1) {
            cout << "Circular Queue is empty.\n";
            return;
        }

        cout << "Circular Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue cq;
    int choice, value;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
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
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.peek();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        // Optionally display the queue after each operation
        cq.display();
    } while (choice != 4);

    return 0;
}
