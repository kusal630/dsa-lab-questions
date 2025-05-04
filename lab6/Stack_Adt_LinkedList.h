#ifndef STACK_ADT_LINKEDLIST_H
#define STACK_ADT_LINKEDLIST_H

#include <iostream>
#include <cstdlib>

using namespace std;

// Node structure for singly linked list stack
struct Node {
    char data;
    Node* next;
};

// Stack class using Singly Linked List
class Stack {
private:
    Node* top; // Pointer to top of stack

public:
    Stack() { top = nullptr; } // Constructor

    // Push operation
    void push(char ch) {
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Stack Overflow!\n";
            return;
        }
        newNode->data = ch;
        newNode->next = top;
        top = newNode;
    }
    // Time Complexity: O(1)

    // Pop operation
    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return '\0';
        }
        Node* temp = top;
        char poppedData = temp->data;
        top = top->next;
        delete temp;
        return poppedData;
    }
    // Time Complexity: O(1)

    // Peek operation
    char peek() {
        return (isEmpty()) ? '\0' : top->data;
    }
    // Time Complexity: O(1)

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

#endif // STACK_ADT_LINKEDLIST_H
