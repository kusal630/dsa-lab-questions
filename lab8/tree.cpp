#include <iostream>
using namespace std;

// Node structure for the binary tree
struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class for characters
class BinaryTree {
private:
    Node* root;
    
    // Helper function for insertion (recursive)
    Node* insert(Node* node, char val) {
        if (node == nullptr)
            return new Node(val);
        // For this example, duplicate values are not inserted.
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }
    
    // Recursive Preorder traversal (Root, Left, Right)
    void preOrder(Node* node) {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
    
    // Recursive Inorder traversal (Left, Root, Right)
    void inOrder(Node* node) {
        if (node == nullptr)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
    
    // Recursive Postorder traversal (Left, Right, Root)
    void postOrder(Node* node) {
        if (node == nullptr)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
    
    // Recursive search in the BST
    bool search(Node* node, char key) {
        if (node == nullptr)
            return false;
        if (node->data == key)
            return true;
        else if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }
    
    // Helper function to deallocate memory
    void clear(Node* node) {
        if (node == nullptr)
            return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    // Constructor: initialize an empty tree.
    BinaryTree() : root(nullptr) {}
    
    // Destructor: free the allocated memory.
    ~BinaryTree() {
        clear(root);
    }
    
    // Insert a value into the tree.
    void insert(char val) {
        root = insert(root, val);
    }
    
    // Display Preorder traversal.
    void preOrder() {
        preOrder(root);
        cout << "\n";
    }
    
    // Display Inorder traversal.
    void inOrder() {
        inOrder(root);
        cout << "\n";
    }
    
    // Display Postorder traversal.
    void postOrder() {
        postOrder(root);
        cout << "\n";
    }
    
    // Search for a value in the tree.
    bool search(char key) {
        return search(root, key);
    }
};

int main() {
    BinaryTree tree;
    int choice;
    char value;
    
    do {
        cout << "\n--- Tree Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Preorder\n";
        cout << "3. Inorder\n";
        cout << "4. Postorder\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter a character to insert: ";
                cin >> value;
                tree.insert(value);
                cout << "Inserted " << value << " into the tree.\n";
                break;
            case 2:
                cout << "Preorder Traversal: ";
                tree.preOrder();
                break;
            case 3:
                cout << "Inorder Traversal: ";
                tree.inOrder();
                break;
            case 4:
                cout << "Postorder Traversal: ";
                tree.postOrder();
                break;
            case 5:
                cout << "Enter a character to search: ";
                cin >> value;
                if (tree.search(value))
                    cout << value << " is found in the tree.\n";
                else
                    cout << value << " is not found in the tree.\n";
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
    
    return 0;
}
