#include <iostream>
using namespace std;

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Time Complexity: O(h) where h is height of tree
    Node* insertHelper(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insertHelper(node->left, val);
        else
            node->right = insertHelper(node->right, val);
        return node;
    }

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

    // Time Complexity: O(h)
    bool searchHelper(Node* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data) 
            return searchHelper(node->left, val);
        return searchHelper(node->right, val);
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insertHelper(root, val);
    }

    void preorder() {
        if (!root) cout << "Tree is empty!";
        preorderHelper(root);
        cout << endl;
    }

    void inorder() {
        if (!root) cout << "Tree is empty!";
        inorderHelper(root);
        cout << endl;
    }

    void postorder() {
        if (!root) cout << "Tree is empty!";
        postorderHelper(root);
        cout << endl;
    }

    bool search(int val) {
        return searchHelper(root, val);
    }
};

void displayMenu() {
    cout << "\nBinary Search Tree Operations:\n";
    cout << "1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    BST tree;
    int choice, val;
    
    while (true) {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "Invalid input! Please enter a number 1-6\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                tree.insert(val);
                break;
            case 2:
                cout << "Preorder traversal: ";
                tree.preorder();
                break;
            case 3:
                cout << "Inorder traversal: ";
                tree.inorder();
                break;
            case 4:
                cout << "Postorder traversal: ";
                tree.postorder();
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> val;
                cout << (tree.search(val) ? "Found" : "Not found") << endl;
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
