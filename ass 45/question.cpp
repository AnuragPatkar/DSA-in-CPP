//! Assignment-45: Circular Linked List

/* //? 1. Define a class CLL to implement Circular linked list data structure with member variable last pointer of type node.
#include <stdio.h>
#include <iostream>
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
class CLL
{
private:
    node *last;
}; */

/* //? 2. In question 1, define a constructor to initialise last pointer with NULL.
CLL()
{
    last = NULL;
} */

/* //? 3. In question 1, define a method to insert a data into the list at the beginning.
void AtFirst(int data)
{
    node *newnode = new node(data);
    if (last == NULL)
    {
        last = newnode;
        newnode->next = last;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
    }
} */

/* //? 4. In question 1, define a method to insert a data into the list at the end
void AtLast(int data)
{
    node *newnode = new node(data);
    if (last == NULL)
    {
        last = newnode;
        newnode->next = last;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
        last = newnode;
    }
} */

/* //? 5. In question 1, define a method to search a node with the give item.
int search(int data)
{
    if (last == NULL)
        return -1;
    int index = 0;
    node *temp = last->next;
    while (1)
    {
        if (temp->item == data)
        {
            return index;
        }
        temp = temp->next;
        index++;
        if (temp == last->next)
            break;
    }
    return -1;
} */

/* //? 6. In question 1, define a method to insert a data into the list after the specified node of the list.
void afterNode(int key, int data)
{
    if (last == NULL)
        return;
    bool found = false;
    node *temp = last->next;
    while (1)
    {
        if (temp->item == key)
        {
            found = true;
            break;
        }
        temp = temp->next;
        if (temp == last->next)
            break;
    }
    if (!found)
    {
        cout << key << " is not in list." << endl;
        return;
    }
    node *newnode = new node(data);
    newnode->next = temp->next;
    temp->next = newnode;
    if (temp == last)
        last = newnode;
} */

/* //? 7. In question 1, define a method to delete first node from the list.
void delFirst()
{
    if (last == NULL)
        return;
    node *temp = last->next;
    if (last == last->next)
    {
        delete last;
        last = NULL;
        return; 
    }

    else
        last->next = temp->next;
    delete temp;
} */

/* //? 8. In question 1, define a method to delete last node of the list.
void delLast()
{
    if (last == NULL)
        return;
    node *temp = last->next;
    if (last == last->next)
    {
        delete last;
        last = NULL;
    }
    else
    {
        while (temp->next != last)
        {
            temp = temp->next;
        }
        temp->next = last->next;
        delete last;
        last = temp;
    }
} */

/* //? 9. In question 1, define a method to delete a specific node.
void delNode(int data)
{
    if (last == NULL)
        return;
    node *temp = last->next;
    bool found = false;
    if (temp->item == data && temp==temp->next)
    {
        delete last;
        last = NULL;
        return;
    }
    else
    {
        while (temp->next != last->next)
        {
            if (temp->next->item == data)
            {
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found)
        {
            cout << data << " is not in list." << endl;
            return;
        }
        node *t = temp->next;
        temp->next = temp->next->next;
        if (t == last)
            last = temp;
        delete t;
    }
} */

/* //? 10. In question 1, define a destructor to deallocates memory for all the nodes in the linked list.
~CLL()
{
    while (last)
        delFirst();
} */

/* //? 11. In question 1, define a copy constructor to implement deep copy.
CLL(CLL &list)
{
    last = NULL;
    if (list.last == NULL)
        return;
    node *temp = list.last->next;
    do
    {
        AtLast(temp->item);
        temp = temp->next;
    } while (temp != list.last->next);
} */

/* //? 12. In question 1, define a copy assignment operator to implement deep copy.
CLL &operator=(CLL &list)
{
    if (this != &list)
    {
        while (last != NULL)
            delLast();

        if (list.last == NULL)
            return *this;

        node *temp = list.last->next;
        do
        {
            AtLast(temp->item);
            temp = temp->next;
        } while (temp != list.last->next);
    }
    return *this;
} */