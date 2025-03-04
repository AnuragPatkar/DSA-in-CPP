//! Assignment-54: AVL Tree

//? 1. Define a class AVL, with node type pointer root as member variable. Implement AVL tree using linked representation

//? 2. In question 1, define constructor to initialise member variable.

//? 3. In question 1, define a method to get balance factor of a node.

//? 4. In question 1, define a method left Rotate for anticlockwise rotation

//? 5. In question 1, define a method rightRotate for clockwise rotation

//? 6. In question 1, define a method to insert new element in the tree

//? 7. In question 1, define a method to delete an element from the tree.

//? 8. In question 1, define preorder traversal

//? 9. In question 1, define postorder traversal

//? 10. In question 1, define inorder traversal.

//? 11. In question 1, define destructor to release memory.

//? 12. In question 1, define a search method to find the element in the tree.

/* //! Answers:
#include <iostream>
using namespace std;

// Node structure for AVL Tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val) : key(val), left(NULL), right(NULL), height(1) {}
};

class AVL {
private:
    Node* root;

    // Utility function to get height of a node
    int height(Node* node) {
        return (node == NULL) ? 0 : node->height;
    }

    // Utility function to get balance factor of a node
    int getBalance(Node* node) {
        if (node == NULL) return 0;
        return height(node->left) - height(node->right);
    }

    // Left Rotate (Anticlockwise Rotation)
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    // Right Rotate (Clockwise Rotation)
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    // Insert a node in AVL tree
    Node* insert(Node* node, int key) {
        if (node == NULL)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else // Duplicate keys not allowed
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // Left Heavy (Right Rotation)
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Heavy (Left Rotation)
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left-Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right-Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Get min value node
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    // Delete a node from AVL tree
    Node* deleteNode(Node* node, int key) {
        if (node == NULL)
            return node;

        if (key < node->key)
            node->left = deleteNode(node->left, key);
        else if (key > node->key)
            node->right = deleteNode(node->right, key);
        else {
            if ((node->left == NULL) || (node->right == NULL)) {
                Node* temp = node->left ? node->left : node->right;
                if (temp == NULL) {
                    temp = node;
                    node = NULL;
                } else
                    *node = *temp;
                delete temp;
            } else {
                Node* temp = minValueNode(node->right);
                node->key = temp->key;
                node->right = deleteNode(node->right, temp->key);
            }
        }

        if (node == NULL)
            return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0)
            return rightRotate(node);
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && getBalance(node->right) <= 0)
            return leftRotate(node);
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->key << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node) {
            cout << node->key << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->key << " ";
        }
    }

    Node* search(Node* node, int key) {
        if (node == NULL || node->key == key)
            return node;
        if (key < node->key)
            return search(node->left, key);
        return search(node->right, key);
    }

public:
    AVL() : root(NULL) {}
    ~AVL() { deleteTree(root); }

    void insert(int key) { root = insert(root, key); }
    void remove(int key) { root = deleteNode(root, key); }
    void inorder() { inorder(root); cout << endl; }
    void preorder() { preorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
    bool search(int key) { return search(root, key) != NULL; }

    void deleteTree(Node* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }
};

int main() {
    AVL tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Inorder: ";
    tree.inorder();

    cout << "Preorder: ";
    tree.preorder();

    cout << "Postorder: ";
    tree.postorder();

    tree.remove(30);
    cout << "After deletion of 30: ";
    tree.inorder();
    return 0;
} */