#include <iostream>
#include "ListADT.h"

int main() {
    ListADT list1, list2, list3;
    int choice, value;

    do {
        cout << "\nMenu: \n";
        cout << "1. Insert into List1\n";
        cout << "2. Insert into List2\n";
        cout << "3. Merge List1 and List2 into List3\n";
        cout << "4. Display List3\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert into List1: ";
                cin >> value;
                list1.insertAscending(value);
                break;
            case 2:
                cout << "Enter value to insert into List2: ";
                cin >> value;
                list2.insertAscending(value);
                break;
            case 3:
                list3 = list1.merge(list2);
                cout << "Lists merged into List3." << endl;
                break;
            case 4:
                cout << "List3: ";
                list3.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
