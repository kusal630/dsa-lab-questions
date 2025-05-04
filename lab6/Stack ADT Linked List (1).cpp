#include <cstdio>
#include <cstdlib>

// Node structure for the singly linked list
struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top; // Pointer to the top node

public:
    Stack() { top = nullptr; } // Constructor initializes stack

    // Push operation
    void push(char ch) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (!newNode) {
            printf("Heap Overflow! Cannot push %c\n", ch);
            return;
        }
        newNode->data = ch;
        newNode->next = top;
        top = newNode;
        printf("Pushed %c onto the stack.\n", ch);
    }
    // Time Complexity: O(1) (Constant time insertion at the top)

    // Pop operation
    void pop() {
        if (!top) {
            printf("Stack Underflow! Cannot pop.\n");
            return;
        }
        Node* temp = top;
        printf("Popped %c from the stack.\n", temp->data);
        top = top->next;
        free(temp);
    }
    // Time Complexity: O(1) (Constant time removal from the top)

    // Peek operation
    void peek() {
        if (!top) {
            printf("Stack is empty. No top element.\n");
            return;
        }
        printf("Top element: %c\n", top->data);
    }
    // Time Complexity: O(1) (Constant time access to the top element)

    // Destructor to free memory
    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            free(temp);
        }
    }
};

int main() {
    Stack stack;
    int choice;
    char element;

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to push: ");
                scanf(" %c", &element);
                stack.push(element);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
// Overall Space Complexity: O(n) (Dynamic memory allocation for n elements)
