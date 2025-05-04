#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class HashTable {
private:
    int TABLE_SIZE;
    vector<int> table;
    static constexpr int EMPTY = -1;
    static constexpr int DELETED = -2;

public:
    HashTable(int size) : TABLE_SIZE(size), table(size, EMPTY) {}

    bool insert(int key) {
        int hash = key % TABLE_SIZE;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            int idx = (hash + i * i) % TABLE_SIZE;
            if (table[idx] == EMPTY || table[idx] == DELETED) {
                table[idx] = key;
                cout << "Inserted " << key << " at index " << idx << endl;
                return true;
            }
        }
        cout << "Hash table is full. Could not insert " << key << ".\n";
        return false;
    }

    bool remove(int key) {
        int hash = key % TABLE_SIZE;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            int idx = (hash + i * i) % TABLE_SIZE;
            if (table[idx] == key) {
                table[idx] = DELETED;
                cout << "Deleted " << key << " from index " << idx << endl;
                return true;
            }
            if (table[idx] == EMPTY) break;
        }
        cout << "Key " << key << " not found.\n";
        return false;
    }

    bool search(int key) {
        int hash = key % TABLE_SIZE;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            int idx = (hash + i * i) % TABLE_SIZE;
            if (table[idx] == key) {
                cout << "Key " << key << " found at index " << idx << endl;
                return true;
            }
            if (table[idx] == EMPTY) break;
        }
        cout << "Key " << key << " not found.\n";
        return false;
    }

    void display() {
        cout << "\nHash Table Contents:\n";
        cout << left << setw(8) << "Index" << "Value\n";
        cout << string(20, '-') << "\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << left << setw(8) << i;
            if (table[i] == EMPTY)
                cout << "EMPTY\n";
            else if (table[i] == DELETED)
                cout << "DELETED\n";
            else
                cout << table[i] << "\n";
        }
        cout << endl;
    }
};

// --- Out-of-class definitions for static constexpr members ---
constexpr int HashTable::EMPTY;
constexpr int HashTable::DELETED;

int main() {
    // Utility to check if a number is prime
    auto isPrime = [](int n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2)
            if (n % i == 0)
                return false;
        return true;
    };

    int size;
    while (true) {
        cout << "Enter size of hash table (must be prime): ";
        cin >> size;
        if (isPrime(size)) break;
        cout << "Error: Table size must be a prime number for quadratic probing.\n";
    }

    HashTable ht(size);
    int choice, key;

    while (true) {
        cout << "\n--- Hash Table Menu ---\n"
             << "1. Insert\n"
             << "2. Delete\n"
             << "3. Search\n"
             << "4. Display\n"
             << "5. Exit\n"
             << "Enter your choice: ";
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
                ht.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter 1–5.\n";
        }
    }
}
