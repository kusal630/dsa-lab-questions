#ifndef LISTADT_H
#define LISTADT_H

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class ListADT {
private:
    Node* head;

public:
    ListADT() {
        head = nullptr;
    }

    Node* gethead() {
        return head;
    }

    // 1. Insert Ascending
    void insertAscending(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr || head->data >= val) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data < val) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 2. Merge Two Lists in Ascending Order
    ListADT merge(ListADT& other) {
        ListADT mergedList;
        Node* temp1 = head;
        Node* temp2 = other.gethead();

        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->data < temp2->data) {
                mergedList.insertAscending(temp1->data);
                temp1 = temp1->next;
            } else {
                mergedList.insertAscending(temp2->data);
                temp2 = temp2->next;
            }
        }

        // Add remaining elements from either list
        while (temp1 != nullptr) {
            mergedList.insertAscending(temp1->data);
            temp1 = temp1->next;
        }
        while (temp2 != nullptr) {
            mergedList.insertAscending(temp2->data);
            temp2 = temp2->next;
        }

        return mergedList;
    }

    // 3. Display
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor
    ~ListADT() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif
