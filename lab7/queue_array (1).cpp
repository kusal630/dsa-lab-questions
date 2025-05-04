#include <iostream>
using namespace std;

class Queue {
private:
    static const int SIZE = 5;
    int arr[SIZE];
    int front, rear, count; // 'count' keeps track of the number of elements

public:
    Queue() : front(0), rear(-1), count(0) {}

    // Enqueue operation: Adds an element to the queue.
    // Time Complexity: O(1)
    void enqueue(int value) {
        if (count == SIZE) {
            cout << "Queue is full. Cannot enqueue " << value << ".\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        count++;
        cout << "Enqueued " << value << " successfully.\n";
    }

    // Dequeue operation: Removes an element from the queue.
    // Time Complexity: O(1)
    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty. Nothing to dequeue.\n";
            return;
        }
        int removedValue = arr[front];
        front = (front + 1) % SIZE;
        count--;
        cout << "Dequeued " << removedValue << " successfully.\n";
    }

    // Peek operation: Shows the element at the front without removing it.
    // Time Complexity: O(1)
    void peek() const {
        if (count == 0) {
            cout << "Queue is empty. Nothing to peek.\n";
            return;
        }
        cout << "Front element is: " << arr[front] << "\n";
    }

    // Display the queue elements for clarity (optional)
    void display() const {
        if (count == 0) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0, index = front; i < count; i++) {
            cout << arr[index] << " ";
            index = (index + 1) % SIZE;
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
        // Optionally display the queue after each operation
        q.display();
    } while (choice != 4);

    return 0;
}
