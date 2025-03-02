//! Assignment-46: Circular Doubly Linked List

/* //? 1. Define a class CDLL to implement Circular Doubly linked list data structure with member variable start pointer of type node.
#include <iostream>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class CDLL
{
private:
    node *last;

public:
}; */

/* //? 2. In question 1, define a constructor to initialise last pointer with NULL.
CDLL()
{
    last = NULL;
} */

/* //? 3. In question 1, define a method to insert a data into the list at the beginning.
void insertAtFirst(int data)
{
    node *newnode = new node();
    newnode->item = data;
    if (last == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        last = newnode;
    }
    else
    {
        newnode->next = last->next;
        newnode->prev = last;
        last->next->prev = newnode;
        last->next = newnode;
    }
} */

/* //? 4. In question 1, define a method to insert a data into the list at the end
void insertAtLast(int data)
{
    node *newnode=new node();
    newnode->item=data;
    if(last==NULL)
    {
        newnode->next=newnode;
        newnode->prev=newnode;
        last=newnode;
    }
    else
    {
        newnode->next=last->next;
        newnode->prev=last;
        last->next->prev=newnode;
        last->next=newnode;
        last=newnode;
    }
} */

/* //? 5. In question 1, define a method to search a node with the give item.
node *search(int data)
{
    if (last == NULL)
        return NULL;
    node *temp = last->next;
    do
    {
        if (temp->item == data)
            return temp;
        temp = temp->next;
    } while (temp != last->next);
    return NULL;
} */

/* //? 6. In question 1, define a method to insert a data into the list after the specified node of the list.
void insertAfter(node *t, int data)
{
    if (t == NULL)
    {
        cout << "Error: Given node is NULL." << endl;
        return;
    }
    node *newnode = new node();
    newnode->item = data;
    newnode->next = t->next;
    newnode->prev = t;
    t->next->prev = newnode;
    t->next = newnode;
    if (t == last)
    {
        last = newnode;
    }
} */

/* //? 7. In question 1, define a method to delete first node from the list.
void delFirst()
{
    if (last == NULL)
        return;
    if (last->next == last)
    {
        delete last;
        last = NULL;
        return;
    }
    else
    {
        node *temp = last->next;
        last->next = temp->next;
        temp->next->prev = last;
        delete temp;
    }
} */

/* //? 8. In question 1, define a method to delete last node of the list.
void delLast()
{
    if (last == NULL)
        return;
    if (last->next == last)
    {
        delete last;
        last = NULL;
        return;
    }
    else
    {
        node *temp = last->prev;
        temp->next = last->next;
        last->next->prev = temp;
        delete last;
        last = temp;
    }
} */

/* //? 9. In question 1, define a method to delete a specific node.
void delNode(node *t)
{
    if (last == NULL)
        return;
    if (t->next == t)
    {
        delete t;
        last = NULL;
        return;
    }
    node *n = t->prev;
    n->next = t->next;
    t->next->prev = n;
    if (t == last)
        last = n;
    delete t;
} */

/* //? 10. In question 1, define a destructor to deallocates memory for all the nodes in the linked list.
~CDLL()
{
    while (last)
        delFirst();
} */

/* //? 11. In question 1, define a copy constructor to implement deep copy.
CDLL(CDLL &list)
{
    last = NULL;
    if (list.last == NULL)
        return;

    node *temp = list.last->next;
    do
    {
        insertAtLast(temp->item);
        temp = temp->next;
    } while (temp != list.last->next);
} */

/* //? 12. In question 1, define a copy assignment operator to implement deep copy.
CDLL &operator=(CDLL &list)
{
    if (this != &list)
    {
        while (last != NULL)
            delFirst();

        if (list.last == NULL)
            return *this;

        node *temp = list.last->next;
        do
        {
            insertAtLast(temp->item);
            temp = temp->next;
        } while (temp != list.last->next);
    }
    return *this;
} */