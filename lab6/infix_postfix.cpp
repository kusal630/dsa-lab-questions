#include <iostream>
#include <cctype>   // For isdigit() function
#include <cstdlib>  // For exit()
#include "Stack_ADT_LinkedList.h"

using namespace std;

// Function to determine operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '=') return 0; // Assignment operator
    return -1;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    Stack stack;
    string postfix = "";

    for (char ch : infix) {
        if (isdigit(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop(); // Remove '(' from stack
        } else { // Operator
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                postfix += stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    Stack stack;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            stack.push(ch - '0'); // Convert char to int
        } else { // Operator
            int val2 = stack.pop();
            int val1 = stack.pop();
            switch (ch) {
                case '+': stack.push(val1 + val2); break;
                case '-': stack.push(val1 - val2); break;
                case '*': stack.push(val1 * val2); break;
                case '/': stack.push(val1 / val2); break;
                case '=': stack.push(val2); break; // Assignment (simple case)
            }
        }
    }
    return stack.pop();
}

int main() {
    string infixExpression, postfixExpression;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Get Infix Expression\n";
        cout << "2. Convert Infix to Postfix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infixExpression;
                break;

            case 2:
                if (infixExpression.empty()) {
                    cout << "Please enter an infix expression first!\n";
                } else {
                    postfixExpression = infixToPostfix(infixExpression);
                    cout << "Postfix Expression: " << postfixExpression << endl;
                }
                break;

            case 3:
                if (postfixExpression.empty()) {
                    cout << "Convert an infix expression to postfix first!\n";
                } else {
                    cout << "Evaluation Result: " << evaluatePostfix(postfixExpression) << endl;
                }
                break;

            case 4:
                cout << "Exiting program...\n";
                exit(0);
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (true);

    return 0;
}
