#include <iostream>
#include <vector>
#include <list>

using namespace std;

class HashTable {
private:
    vector<list<int>> table;
    int TABLE_SIZE;

    // Simple hash function: modulo
    int hashFunction(int key) const {
        return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
    }

public:
    // Constructor: initialize table with given size
    HashTable(int size) : TABLE_SIZE(size), table(size) {}

    // Insert key into the chain at hashed index
    // Average: O(1), Worst: O(n) if all keys collide
    void insert(int key) {
        int idx = hashFunction(key);
        // Prevent duplicates
        for (int x : table[idx]) {
            if (x == key) {
                cout << "Key " << key << " already present at index " << idx << "\n";
                return;
            }
        }
        table[idx].push_front(key);
        cout << "Inserted " << key << " at index " << idx << "\n";
    }

    // Delete key from the chain at hashed index
    // Average: O(1), Worst: O(n) if all keys collide
    void remove(int key) {
        int idx = hashFunction(key);
        for (auto it = table[idx].begin(); it != table[idx].end(); ++it) {
            if (*it == key) {
                table[idx].erase(it);
                cout << "Deleted " << key << " from index " << idx << "\n";
                return;
            }
        }
        cout << "Key " << key << " not found\n";
    }

    // Search for key in the chain at hashed index
    // Average: O(1), Worst: O(n) if all keys collide
    void search(int key) const {
        int idx = hashFunction(key);
        for (int x : table[idx]) {
            if (x == key) {
                cout << "Key " << key << " found at index " << idx << "\n";
                return;
            }
        }
        cout << "Key " << key << " not found\n";
    }
};

int main() {
    int size;
    cout << "Enter size of hash table: ";
    cin >> size;
    if (size <= 0) {
        cout << "Invalid size. Exiting.\n";
        return 1;
    }

    HashTable ht(size);
    int choice, key;

    while (true) {
        cout << "\n--- Hash Table Menu (Separate Chaining) ---\n"
             << "1. Insert\n"
             << "2. Delete\n"
             << "3. Search\n"
             << "4. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.remove(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                ht.search(key);
                break;
            case 4:
                cout << "Exiting.\n";
                return 0;
            default:
                cout << "Invalid choice. Please select 1–4.\n";
        }
    }
}
