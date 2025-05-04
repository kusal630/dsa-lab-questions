#include <cstdio>
#include <cstdlib>

#define SIZE 5 // Define stack size

class Stack {
private:
    char arr[SIZE]; // Character array to store stack elements
    int top; // Top pointer

public:
    Stack() { top = -1; } // Constructor initializes stack

    // Push operation
    void push(char ch) {
        if (top >= SIZE - 1) {
            printf("Stack Overflow! Cannot push %c\n", ch);
            return;
        }
        arr[++top] = ch;
        printf("Pushed %c onto the stack.\n", ch);
    }
    // Time Complexity: O(1) (Constant time insertion at the top)

    // Pop operation
    void pop() {
        if (top < 0) {
            printf("Stack Underflow! Cannot pop.\n");
            return;
        }
        printf("Popped %c from the stack.\n", arr[top--]);
    }
    // Time Complexity: O(1) (Constant time removal from the top)

    // Peek operation
    void peek() {
        if (top < 0) {
            printf("Stack is empty. No top element.\n");
            return;
        }
        printf("Top element: %c\n", arr[top]);
    }
    // Time Complexity: O(1) (Constant time access to the top element)
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
// Overall Space Complexity: O(1) (Fixed size array, no dynamic allocation)
