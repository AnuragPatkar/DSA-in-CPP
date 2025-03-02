//! Assignment-53: Tree

/* //? 1. Define a class BST (Binary Search Tree) with node type pointer root as member variable. Implement Binary Search Tree using linked representation.
#include <iostream>
using namespace std;
struct node
{
    node *left;
    int item;
    node *right;
};
class BST
{
private:
    node *root;
public:
    BST();
    BST(const BST&b);
    const BST &operator=(const BST &b);
    ~BST();
}; */

/* //? 2. In question 1, define a constructor to initialise root pointer with NULL.
BST::BST()
{
    root = NULL;
} */

/* //? 3. In question 1, define a method to check if the tree is empty.
bool BST::isEmpty()
{
    return root == NULL;
} */

/* //? 4. In question 1, define a method to insert a new element in the BST
void BST::insert(int data)
{
    node *newnode = new node;
    newnode->item = data;
    newnode->left = NULL;
    newnode->right = NULL;
    if (isEmpty())
    {
        root = newnode;
        return;
    }
    node *t = root;
    while (true)
    {
        if (data < t->item)
        {
            if (t->left == NULL)
            {
                t->left = newnode;
                break;
            }
            t = t->left;
        }
        else
        {
            if (t->right == NULL)
            {
                t->right = newnode;
                break;
            }
            t = t->right;
        }
    }
} */

/* //? 5. In question 1, define a method for preorder traversing of BST
void BST::preorder(node *root)
{
    if (root)
    {
        cout << root->item << " ";
        preorder(root->left);
        preorder(root->right);
    }
} */

/* //? 6. In question 1, define a method for inorder traversing of BST
void BST::inorder(node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->item << " ";
        inorder(root->right);
    }
} */

/* //? 7. In question 1, define a method for postorder traversing of BST
void BST::postorder(node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->item << " ";
    }
} */

//? 8. In question 1, define a method to delete an element from BST

/* //? 9. In question 1, define a method to search an item in the BST
bool BST::search(node *root, int data)
{
    while (root != NULL)
    {
        if (data == root->item)
            return true;

        if (data < root->item)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return false;
} */

/* //? 10. In question 1, define a destructor to release memory of all the nodes of BST.
void BST::destroyTree(node *root)
{
    if (root)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
        root=NULL;
    }
}
BST::~BST()
{
    destroyTree(root);
} */

/* //? 11. In question 1, define a copy constructor to implement deep copy.
BST::BST(const BST &b)
{
    root = NULL;
    if (b.root == NULL)
        return;
    root = copyTree(b.root);
}
node *BST::copyTree(node *otherroot)
{
    if (otherroot == NULL)
        return NULL;
    node *newnode = new node;
    newnode->item = otherroot->item;
    newnode->left = copyTree(otherroot->left);
    newnode->right = copyTree(otherroot->right);
    return newnode;
} */

/* //? 12. In question 1, define a copy assignment operator to implement deep copy.
node *BST::copyTree(node *otherroot)
{
    if (otherroot == NULL)
        return NULL;
    node *newnode = new node;
    newnode->item = otherroot->item;
    newnode->left = copyTree(otherroot->left);
    newnode->right = copyTree(otherroot->right);
    return newnode;
}
const BST &BST::operator=(const BST &b)
{
    if (this != &b)
    {

        destroyTree(root);
        root = NULL;
        if (b.root == NULL)
            return *this;
        root = copyTree(b.root);
    }
    return *this;
} */