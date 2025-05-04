#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

class ExpressionTree {
private:
    struct Node {
        string data;
        Node* left;
        Node* right;
        Node(string val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Time Complexity: O(n)
    void preorderHelper(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    // Time Complexity: O(n)
    void inorderHelper(Node* node) {
        if (!node) return;
        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }

    // Time Complexity: O(n)
    void postorderHelper(Node* node) {
        if (!node) return;
        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->data << " ";
    }

public:
    ExpressionTree() : root(nullptr) {}

    // Time Complexity: O(n), where n = number of tokens in postfix
    void constructFromPostfix(const string& postfix) {
        stack<Node*> st;
        vector<string> tokens;
        stringstream ss(postfix);
        string token;
        
        // Split input into tokens
        while (getline(ss, token, ' ')) {
            if (!token.empty()) tokens.push_back(token);
        }

        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Operator: Pop two operands from stack
                if (st.size() < 2) {
                    cerr << "Invalid postfix expression!" << endl;
                    return;
                }
                Node* right = st.top(); st.pop();
                Node* left = st.top(); st.pop();
                Node* newNode = new Node(token);
                newNode->left = left;
                newNode->right = right;
                st.push(newNode);
            } else {
                // Operand: Push to stack
                st.push(new Node(token));
            }
        }

        if (st.size() != 1) {
            cerr << "Invalid postfix expression!" << endl;
            return;
        }
        root = st.top();
    }

    void preorder() {
        if (!root) cout << "Tree is empty!" << endl;
        else {
            preorderHelper(root);
            cout << endl;
        }
    }

    void inorder() {
        if (!root) cout << "Tree is empty!" << endl;
        else {
            inorderHelper(root);
            cout << endl;
        }
    }

    void postorder() {
        if (!root) cout << "Tree is empty!" << endl;
        else {
            postorderHelper(root);
            cout << endl;
        }
    }
};

void displayMenu() {
    cout << "\nExpression Tree Operations:\n";
    cout << "1. Enter Postfix Expression\n";
    cout << "2. Construct Expression Tree\n";
    cout << "3. Preorder Traversal\n";
    cout << "4. Inorder Traversal\n";
    cout << "5. Postorder Traversal\n";
    cout << "6. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    ExpressionTree et;
    string postfix;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter postfix expression (space-separated): ";
                getline(cin, postfix);
                break;
            case 2:
                et.constructFromPostfix(postfix);
                break;
            case 3:
                cout << "Preorder: ";
                et.preorder();
                break;
            case 4:
                cout << "Inorder: ";
                et.inorder();
                break;
            case 5:
                cout << "Postorder: ";
                et.postorder();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}