//! Assignment-51: Deque

/* //? 1. Define a class Deque with node type pointers front and rear as member variables. Implement queue using doubly linked list.
#include <iostream>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class Deque
{
private:
    node *front, *rear;

public:
}; */

/* //? 2. In question 1, define a constructor to initialise member variables
Deque::Deque()
{
    front = NULL;
    rear = NULL;
} */

/* //? 3. In question 1, define a method to insert a new element at the front
void Deque::insertFront(int data)
{
    node*newnode =new node;
    newnode->item=data;
    newnode->prev=NULL;
    if(front==NULL&&rear==NULL)
    {
        front=newnode;
        rear=newnode;
        newnode->next=NULL;
    }
    else 
    {
      newnode->next=front;
      front->prev=newnode;
      front=newnode;
    }
} */

/* //? 4. In question 1, define a method to insert a new element at the rear,
void Deque::insertRear(int data)
{
    node*newnode =new node;
    newnode->item=data;
    newnode->next=NULL;
    if(front==NULL&&rear==NULL)
    {
        front=newnode;
        rear=newnode;
        newnode->prev=NULL;
    }
    else 
    {
      newnode->prev=rear;
      rear->next=newnode;
      rear=newnode;
    }
} */

/* //? 5. In question 1, define a method to delete front element
void Deque::delFront()
{
    if (front == NULL && rear == NULL)
    {
        cout << "Deque is Empty." << endl;
        return;
    }
    node *t = front;
    if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front=front->next;
        front->prev=NULL;
    }
    delete t;
} */

/* //? 6. In question 1, define a method to delete rear element
void Deque::delRear()
{
    if (front == NULL && rear == NULL)
    {
        cout << "Deque is Empty." << endl;
        return;
    }
    node *t = rear;
    if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        rear = rear->prev;
        rear->next = NULL;
    }
    delete t;
} */

/* //? 7. In question 1, define a method to get front element.
node *Deque::getFront()
{
    if (front == NULL && rear == NULL)
    {
        cout << "Deque is Empty." << endl;
        return NULL;
    }
    return front;
} */

/* //? 8. In question 1, define a method to get rear element
node *Deque::getRear()
{
    if (front == NULL && rear == NULL)
    {
        cout << "Deque is Empty." << endl;
        return NULL;
    }
    return rear;
} */

/* //? 9. In question 1, define a destructor to deallocate the memory.
Deque::~Deque()
{
    while (front != NULL)
        delFront();
} */

/* //? 10. In question 1, define a method to check if deque is empty.
bool Deque::isEmpty()
{
    return (front == NULL && rear == NULL);
} */

/* //? 11. In question 1, define a copy constructor to implement deep copy.
Deque::Deque(const Deque &d)
{
    front = NULL;
    rear = NULL;
    if (d.front == NULL)
        return;
    node *t = d.front;
    while (t != NULL)
    {
        insertRear(t->item);
        t = t->next;
    }
} */

/* //? 12. In question 1, define a copy assignment operator to implement deep copy.
const Deque &Deque::operator=(const Deque &d)
{
    if (this != &d)
    {
        while(front!=NULL)
        {
            delFront();
        }
        if (d.front == NULL)
            return *this;
        node *t = d.front;
        while (t != NULL)
        {
            insertRear(t->item);
            t = t->next;
        }
    }
    return *this;
} */