#ifndef STACK_ADT_LINKLIST_H
#define STACK_ADT_LINKLIST_H

#include <iostream>
using namespace std;

// Stack ADT using a Singly Linked List
struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top; 

public:
    Stack() { top = nullptr; } // Constructor initializes stack as empty

    // Push operation: Inserts a character at the top of the stack
    void push(char ch) {
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Heap Overflow! Cannot push " << ch << endl;
            return;
        }
        newNode->data = ch;
        newNode->next = top;
        top = newNode;
    }
    // Time Complexity: O(1) (Constant time insertion)

    // Pop operation: Removes and returns the top element of the stack
    char pop() {
        if (!top) {
            return '\0';
        }
        Node* temp = top;
        char poppedData = temp->data;
        top = top->next;
        delete temp;
        return poppedData;
    }
    // Time Complexity: O(1) (Constant time removal)

    // Peek operation: Returns the top element of the stack without removing it
    char peek() {
        return (top) ? top->data : '\0';
    }
    // Time Complexity: O(1)

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
    // Time Complexity: O(1)

    // Destructor: Frees memory allocated for the stack
    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

#endif // STACK_ADT_LINKLIST_H
