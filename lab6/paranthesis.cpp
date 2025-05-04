#include <iostream>
#include <string>
#include "stack_adt_linklist.h"  // Include Stack ADT header

using namespace std;

// Function to check if a string of parentheses is balanced
bool isBalanced(const string &parentheses) {
    Stack stack;

    for (char ch : parentheses) {
        if (ch == '(') {
            stack.push(ch);  // Push opening bracket
        } else if (ch == ')') {
            if (stack.isEmpty()) {
                return false;  // Unmatched closing bracket
            }
            stack.pop();  // Pop matching opening bracket
        } else {
            continue;  // Ignore non-parentheses characters
        }
    }
    return stack.isEmpty();  // Stack should be empty if balanced
}

// Menu-driven program
int main() {
    int choice;
    string parentheses;

    do {
        cout << "\nMenu:";
        cout << "\n1. Check Balance";
        cout << "\n2. Exit";
        cout << "\nEnter your choice: ";

        if (!(cin >> choice)) {  // Input validation
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();  // Clear error state
            cin.ignore(10000, '\n');  // Discard invalid input
            continue;  // Restart loop
        }

        cin.ignore();  // Clear buffer before getline

        switch (choice) {
            case 1:
                cout << "Enter parentheses string: ";
                getline(cin, parentheses);  // Read input with spaces
                
                if (isBalanced(parentheses)) {
                    cout << "Balanced Parentheses ✅" << endl;
                } else {
                    cout << "Unbalanced Parentheses ❌" << endl;
                }
                break;

            case 2:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 2);

    return 0;
}
