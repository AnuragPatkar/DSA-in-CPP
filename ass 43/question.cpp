//! Assignment-43: Singly Linked List

/* //? 1. Define a class SLL to implement singly linked list data structure with member variable start pointer of type node.
#include <iostream>
#include <stdio.h>
using namespace std;
struct node
{
    int item;
    node *next;
    node(int data)
    {
        item = data;
        next = NULL;
    }
};
class SLL
{
private:
    node *start;

public:
    SLL()
    {
        start = NULL;
    }
    SLL(const SLL &list)
    {
        start = NULL;
        node *temp = list.start;
        while (temp != NULL) // Fix: Changed 'head' to 'temp'
        {
            insertAtLast(temp->item);
            temp = temp->next;
        }
    }
    SLL &operator=(SLL &list)
    {
        if (this != &list)
        {
            while (head != NULL)
                delFirst();
            node *temp = list.start;
            while (temp != NULL) // Fix: Changed 'head' to 'temp'
            {
                insertAtLast(temp->item);
                temp = temp->next;
            }
        }
        return *this;
    }
    void insertAtStart(int data)
    {
        node *newnode = new node(data);
        newnode->next = start;
        start = newnode;
    }
    void insertAtLast(int data)
    {
        node *newnode = new node(data);
        if (start == NULL)
        {
            start = newnode;
            return;
        }
        node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    int search(int data)
    {
        node *temp = start;
        int index = 0;
        while (temp->next != NULL)
        {
            if (temp->item == data)
            {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }
    void afterNode(int key, int data)
    {
        node *newnode = new node(data);
        node *temp = start;
        while (temp->item != key)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    void delFirst()
    {
        node *temp = start;
        start = start->next;
        delete temp;
    }
    void delLast()
    {
        if (start == NULL)
            return;
        if (start->next == NULL)
        {
            delete start;
            start = NULL;
            return;
        }
        node *temp = start;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    void delNode(int data)
    {

        if (start == NULL)
        {
            cout << "List is empty. Deletion not possible!" << endl;
            return;
        }

        if (start->item == data) // If head node is to be deleted
        {
            delFirst();
            return;
        }
        node *temp = start;
        while (temp->next->item != data)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            cout << "Node with value " << data << " not found!" << endl;
            return;
        }
        node *t = temp->next;
        temp->next = temp->next->next;
        delete t;
    }
    ~SLL()
    {
        while (start != NULL)
            delFirst();
    }
}; */

/* //? 2. In question 1, define a constructor to initialise start pointer with NULL.
SLL()
{
    start = NULL;
} */

/* //? 3. In question 1, define a method to insert a data into the list at the beginning.
void insertAtStart(int data)
{
    node *temp = new node(data);
    temp->next = start;
    start = temp;
} */

/* //? 4. In question 1, define a method to insert a data into the list at the end
void insertAtLast(int data)
{
    node *newnode = new node(data);
    if (start == NULL)
    {
        start = newnode;
        return;
    }
    node *temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
} */

/* //? 5. In question 1, define a method to search a node with the give item.
int search(int data)
{
    node *temp = start;
    int index = 0;
    while (temp->next != NULL)
    {
        if (temp->item == data)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
} */

/* //? 6. In question 1, define a method to insert a data into the list after the specified node of the list.
void afterNode(int key, int data)
{
    node *newnode = new node(data);
    node *temp = start;
    while (temp->item != key)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
} */

/* //? 7. In question 1, define a method to delete first node from the list.
void delFirst()
{
    node *temp=start;
    start=start->next;
    delete temp;
} */

/* //? 8. In question 1, define a method to delete last node of the list.
void delLast()
{
    if (start == NULL)
        return;
    if (start->next == NULL)
    {
        delete start;
        start = NULL;
        return;
    }
    node *temp = start;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
} */

/* //? 9. In question 1, define a method to delete a specific node.
void delNode(int data)
{

    if (start == NULL)
    {
        cout << "List is empty. Deletion not possible!" << endl;
        return;
    }

    if (start->item == data) // If head node is to be deleted
    {
        delFirst();
        return;
    }
    node *temp = start;
    while (temp->next->item != data)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        cout << "Node with value " << data << " not found!" << endl;
        return;
    }
    node *t = temp->next;
    temp->next = temp->next->next;
    delete t;
} */

/* //? 10. In question 1, define a destructor to deallocates memory for all the nodes in the linked list.
~SLL()
{
    while (start != NULL)
        delFirst();
} */

/* //? 11. In question 1, define a copy constructor to implement deep copy.
SLL(const SLL &list)
{
    start = NULL;
    node *temp = list.start;
    while (temp != NULL) // Fix: Changed 'head' to 'temp'
    {
        insertAtLast(temp->item);
        temp = temp->next;
    }
} */

/* //? 12. In question 1, define a copy assignment operator to implement deep copy.
SLL &operator=(SLL &list)
{
    if (this != &list)
    {
        while (head != NULL)
                delFirst();
        node *temp = list.start;
        while (temp != NULL) // Fix: Changed 'head' to 'temp'
        {
            insertAtLast(temp->item);
            temp = temp->next;
        }
    }
    return *this;
} */