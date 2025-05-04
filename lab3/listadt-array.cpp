#include <cstdio>
#include <cstdlib>

class listadt {
private:
    int size = 5;
    int arr[5] = {1, 2, 3, 4};  // Last index remains empty
    int count = 4; // Number of valid elements

public:
    void insertbeg();
    void insertend();
    void insertpos();
    void deletebeg();
    void deleteend();
    void deletepos();
    void search();
    void display();
    void rotate();
};

int main() {
    listadt list;
    int option;

    do {
        printf("\nSelect an option:\n");
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at a certain position\n");
        printf("4. Delete at beginning\n5. Delete at end\n6. Delete at certain position\n");
        printf("7. Search\n8. Display\n9. Rotate\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1: list.insertbeg(); break;
            case 2: list.insertend(); break;
            case 3: list.insertpos(); break;
            case 4: list.deletebeg(); break;
            case 5: list.deleteend(); break;
            case 6: list.deletepos(); break;
            case 7: list.search(); break;
            case 8: list.display(); break;
            case 9: list.rotate(); break;
            case 10: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid option! Please enter a valid choice.\n");
        }
    } while (option != 10);

    return 0;
}

// Inserting element at beginning
void listadt::insertbeg() {
    if (count == size) {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    int newbeg;
    printf("Enter the new element to add at beginning: ");
    scanf("%d", &newbeg);

    for (int i = count; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = newbeg;
    count++;

    display();
}

// Inserting element at end
void listadt::insertend() {
    if (count == size) {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    int newend;
    printf("Enter the element to add at end: ");
    scanf("%d", &newend);

    arr[count] = newend;
    count++;

    display();
}

// Inserting element at a specific position
void listadt::insertpos() {
    if (count == size) {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    int pos, newele;
    printf("Enter the position (0 to %d) to insert: ", count);
    scanf("%d", &pos);

    if (pos < 0 || pos > count) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter the new element: ");
    scanf("%d", &newele);

    for (int i = count; i > pos; --i) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = newele;
    count++;

    display();
}

// Deleting element from beginning
void listadt::deletebeg() {
    if (count == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    for (int i = 0; i < count - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    count--;

    display();
}

// Deleting element from end
void listadt::deleteend() {
    if (count == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    count--;

    display();
}

// Deleting element from a specific position
void listadt::deletepos() {
    if (count == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    int pos;
    printf("Enter the position (0 to %d) to delete: ", count - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= count) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos; i < count - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    count--;

    display();
}

// Searching for an element
void listadt::search() {
    int key, found = 0;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    for (int i = 0; i < count; ++i) {
        if (arr[i] == key) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element not found.\n");
    }
}

// Displaying the array
void listadt::display() {
    if (count == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Current array: ");
    for (int i = 0; i < count; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Rotating the array to the right
void listadt::rotate() {
    if (count == 0) {
        printf("Array is empty. Cannot rotate.\n");
        return;
    }

    int rot;
    printf("Enter the number of times to rotate right: ");
    scanf("%d", &rot);

    rot = rot % count;  // Optimize rotation count
    for (int r = 0; r < rot; ++r) {
        int temp = arr[count - 1];
        for (int i = count - 1; i > 0; --i) {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }

    display();
}
