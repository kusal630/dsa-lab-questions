#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int* heap;
    int size;
    int capacity;

    // Time Complexity: O(log n)
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Time Complexity: O(log n)
    void heapifyDown(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

    // Time Complexity: O(n)
    void resize() {
        int newCapacity = capacity == 0 ? 1 : capacity * 2;
        int* newHeap = new int[newCapacity];
        for (int i = 0; i < size; ++i)
            newHeap[i] = heap[i];
        delete[] heap;
        heap = newHeap;
        capacity = newCapacity;
    }

public:
    PriorityQueue(int initialCapacity = 10) {
        capacity = initialCapacity;
        heap = new int[capacity];
        size = 0;
    }

    ~PriorityQueue() {
        delete[] heap;
    }

    // Time Complexity: O(log n) amortized
    void insert(int value) {
        if (size == capacity)
            resize();
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    // Time Complexity: O(log n)
    int deleteMax() {
        if (size == 0)
            return -1;
        int maxVal = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return maxVal;
    }

    // Time Complexity: O(n)
    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty.\n";
            return;
        }
        cout << "Priority Queue elements: ";
        for (int i = 0; i < size; ++i)
            cout << heap[i] << " ";
        cout << endl;
    }

    // Time Complexity: O(n)
    bool search(int value) {
        for (int i = 0; i < size; ++i)
            if (heap[i] == value)
                return true;
        return false;
    }

    // Time Complexity: O(n log n)
    void heapSort() {
        if (size == 0) {
            cout << "Heap is empty.\n";
            return;
        }

        int* copyHeap = new int[size];
        int copySize = size;
        for (int i = 0; i < size; ++i)
            copyHeap[i] = heap[i];

        // Build max heap (already a max heap)
        // Perform heap sort
        for (int i = copySize - 1; i > 0; --i) {
            swap(copyHeap[0], copyHeap[i]);
            // Heapify down on reduced heap
            int current = 0;
            while (true) {
                int left = 2 * current + 1;
                int right = 2 * current + 2;
                int largest = current;

                if (left < i && copyHeap[left] > copyHeap[largest])
                    largest = left;
                if (right < i && copyHeap[right] > copyHeap[largest])
                    largest = right;

                if (largest != current) {
                    swap(copyHeap[current], copyHeap[largest]);
                    current = largest;
                } else {
                    break;
                }
            }
        }

        cout << "Sorted elements (ascending order): ";
        for (int i = 0; i < copySize; ++i)
            cout << copyHeap[i] << " ";
        cout << endl;

        delete[] copyHeap;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;

    do {
        cout << "\nPriority Queue Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Sort (Heap Sort)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;
            case 2: {
                int maxVal = pq.deleteMax();
                if (maxVal == -1)
                    cout << "Priority Queue is empty.\n";
                else
                    cout << "Deleted element: " << maxVal << endl;
                break;
            }
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (pq.search(value))
                    cout << "Value found.\n";
                else
                    cout << "Value not found.\n";
                break;
            case 5:
                pq.heapSort();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}