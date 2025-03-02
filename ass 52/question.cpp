//! Assignment-52: Priority Queue

/* //? 1. Define a class PriorityQueue with node type pointer start as member variable. Implement PriorityQueue using singly linked list.
#include <iostream>
using namespace std;
struct node
{
    int priority;
    int item;
    node *ptr;
};
class PriorityQueue
{
private:
    node *start;

public:
}; */

/* //? 2. In question 1, define a constructor to initialise member variable.
PriorityQueue::PriorityQueue()
{
    start = NULL;
} */

/* //? 3. In question 1, define a method to insert new item in the Priority Queue according to the priority number.
void PriorityQueue::insert(int p, int data)
{
    node *newnode = new node;
    newnode->priority = p;
    newnode->item = data;
    newnode->next = NULL;
    if (start == NULL || start->priority < p)
    {
        newnode->next = start;
        start = newnode;
        return;
    }

    node *temp = start;
    while (temp->next != NULL && temp->next->priority >= p)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
} */

/* //? 4. In question 1, define a method to delete highest priority element
void PriorityQueue::delHighestPriority()
{
    if (start == NULL)
    {
        cout << "Queue is Empty." << endl;
        return;
    }
    node *temp = start;
    start = start->next;
    delete temp;
} */

/* //? 5. In question 1, define a method to get highest priority element
node *PriorityQueue::getHighestPriority()
{
    if (start == NULL)
    {
        return NULL;
    }
    return start;
} */

/* //? 6. In question 1, define a method to get highest priority number.
int PriorityQueue::getHighestPriorityNumber()
{
    if (start == NULL)
    {
        return -1;
    }
    return start->priority;
} */

/* //? 7. In question 1, define a destructor to deallocate the memory.
PriorityQueue::~PriorityQueue()
{
    while (start)
        delHighestPriority();
} */

/* //? 8. In question 1, define a method to check if Priority Queue is empty
bool PriorityQueue::isEmpty()
{
    return start == NULL;
} */

/* //? 9. In question 1, define a copy constructor to implement deep copy.
PriorityQueue::PriorityQueue(const PriorityQueue &p)
{
    start = NULL;
    if (p.start == NULL)
        return;
    node *temp = p.start;
    while (temp != NULL)
    {
        insert(temp->priority, temp->item);
        temp = temp->next;
    }
} */

/* //? 10. In question 1, define a copy assignment operator to implement deep copy
const PriorityQueue &PriorityQueue::operator=(const PriorityQueue &p)
{
    if (this != &p)
    {
        while (start != NULL)
            delHighestPriority();
        if (p.start == NULL)
            return *this;
        node *temp = p.start;
        while (temp != NULL)
        {
            insert(temp->priority, temp->item);
            temp = temp->next;
        }
    }
    return *this;
} */