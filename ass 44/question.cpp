//! Assignment-44: Doubly Linked List

/* //? 1. Define a class DLL to implement singly linked list data structure with member variable start pointer of type node.
#include <iostream>
#include <stdio.h>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
    node(int data)
    {
        prev=NULL;
        item = data;
        next = NULL;
    }
};
class DLL
{
private:
    node *start;
}; */

/* //? 2. In question 1, define a constructor to initialise start pointer with NULL.
DLL() { start = NULL; } */

/* //? 3. In question 1, define a method to insert a data into the list at the beginning.
void Atstart(int data)
{
    node *newnode = new node(data);
    newnode->prev = NULL;
    newnode->next = start;
    if (start != NULL)
    {
        start->prev = newnode;
    }
    start = newnode;
} */

/* //? 4. In question 1, define a method to insert a data into the list at the end
void AtLast(int data)
{
    node *newnode = new node(data);
    newnode->next = NULL;

    if (start == NULL)
    {
        newnode->prev = NULL;
        start = newnode;
        return;
    }
    node *temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
} */

/* //? 5. In question 1, define a method to search a node with the give item.
int search(int data)
{
    int index = 0;
    node *temp = start;
    while (temp != NULL)
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
    node *temp = start;
    while (temp != NULL)
    {
        if (temp->item == key)
        {
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << key << "is not in list." << endl;
        return;
    }
    else if (temp->next == NULL)
    {
        AtLast(data);
    }
    else
    {
        node *newnode = new node(data);

        newnode->next = temp->next;
        temp->next->prev = newnode;
        newnode->prev = temp;
        temp->next = newnode;
    }
} */

/* //? 7. In question 1, define a method to delete first node from the list.
void delFirst()
{
    if (start == NULL)
        return;
    node *temp = start;
    start = start->next;
    if (start!= NULL)
    {
        start->prev = NULL;
    }
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
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
} */

/* //? 9. In question 1, define a method to delete a specific node.
void delNode(int data)
{
    if (start == NULL)
        return;
    if (start->item == data && start->next == NULL)
    {
        delete start;
        start = NULL;
        return;
    }
    if (start->item == data && start->next != NULL)
    {
        delFirst();
        return;
    }
    node *temp = start;
    while (temp != NULL && temp->next != NULL && temp->next->item != data)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
    {
        cout << data << " is not in list" << endl;
        return;
    }
    node *t = temp->next;
    if (temp->next->next != NULL)
    {
        temp->next = temp->next->next;
        temp->next->prev = temp;
    }
    else
    {
        temp->next = NULL;
    }

    delete t;
} */

/* //? 10. In question 1, define a destructor to deallocates memory for all the nodes in the linked list.
~DLL()
{
    while (start != NULL)
        delFirst();
} */

/* //? 11. In question 1, define a copy constructor to implement deep copy.
DLL(DLL &list)
{
    start=NULL;
    node *temp=list.start;
    while(temp!=NULL)
    {
        AtLast(temp->item);
        temp=temp->next;
    }

} */

/* //? 12. In question 1, define a copy assignment operator to implement deep copy.
DLL &operator=(DLL &list)
{
    if (this != &list)
    {
        while(start!=NULL)
          delFirst();
        node *temp = list.start;
        while (temp != NULL)
        {
            AtLast(temp->item);
            temp = temp->next;
        }
    }
    return *this;
} */