#include <iostream>

class HashTable {
private:
    enum EntryState { EMPTY, OCCUPIED, DELETED }; // Moved enum outside HashEntry

    struct HashEntry {
        int key;
        EntryState state;
    };

    HashEntry* table;
    int size;

    int hashFunction(int key) {
        int index = key % size;
        return index < 0 ? index + size : index;
    }

public:
    HashTable(int size) : size(size) {
        table = new HashEntry[size];
        for (int i = 0; i < size; ++i) {
            table[i].state = EMPTY; // Directly use enum value
        }
    }

    ~HashTable() {
        delete[] table;
    }

    bool insert(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        int firstDeleted = -1;

        do {
            if (table[index].state == OCCUPIED) {
                if (table[index].key == key) return false; // Duplicate
            } else {
                if (table[index].state == DELETED && firstDeleted == -1) {
                    firstDeleted = index;
                } else if (table[index].state == EMPTY) {
                    if (firstDeleted != -1) index = firstDeleted;
                    table[index].key = key;
                    table[index].state = OCCUPIED;
                    return true;
                }
            }
            index = (index + 1) % size;
        } while (index != originalIndex);

        if (firstDeleted != -1) {
            table[firstDeleted].key = key;
            table[firstDeleted].state = OCCUPIED;
            return true;
        }

        return false; // Table full
    }

    bool deleteKey(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        do {
            if (table[index].state == OCCUPIED && table[index].key == key) {
                table[index].state = DELETED;
                return true;
            }
            if (table[index].state == EMPTY) break;
            index = (index + 1) % size;
        } while (index != originalIndex);

        return false;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        do {
            if (table[index].state == OCCUPIED && table[index].key == key) return true;
            if (table[index].state == EMPTY) break;
            index = (index + 1) % size;
        } while (index != originalIndex);

        return false;
    }

    // Fixed display function
    void display() {
        for (int i = 0; i < size; ++i) {
            std::cout << "Index " << i << ": ";
            if (table[i].state == OCCUPIED) {
                std::cout << table[i].key;
            } else if (table[i].state == DELETED) {
                std::cout << "Deleted";
            } else {
                std::cout << "Empty";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int size;
    do {
        std::cout << "Enter hash table size (positive integer): ";
        std::cin >> size;
    } while (size <= 0);

    HashTable ht(size);
    int choice, key;

    do {
        std::cout << "\nMenu:\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nChoice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter key: ";
                std::cin >> key;
                std::cout << (ht.insert(key) ? "Inserted!\n" : "Failed (duplicate/full)\n");
                break;
            case 2:
                std::cout << "Enter key: ";
                std::cin >> key;
                std::cout << (ht.deleteKey(key) ? "Deleted!\n" : "Not found!\n");
                break;
            case 3:
                std::cout << "Enter key: ";
                std::cin >> key;
                std::cout << (ht.search(key) ? "Found!\n" : "Not found!\n");
                break;
            case 4:
                ht.display();
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
