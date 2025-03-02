//! Assignment-50: Queue using linked list

/* //? 1. Define a class Queue with node type pointers front and rear as member variables. Implement queue using Singly linked list.
#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};
class Queue
{
private:
    node *start;

public:
    Queue();
    Queue(const Queue &q);
    const Queue &operator=(const Queue &q);
    ~Queue();
}; */

/* //? 2. In question 1, define a constructor to initialise member variable.
Queue(int data)
{
    node *newnode = new node();
    newnode->item = data;
    newnode->next = NULL;
    front = newnode;
    rear = newnode;
} */

/* //? 3. In question 1, define a method to insert a new element at the rear in the queue.
void insert(int data)
{
    node *newnode = new node();
    newnode->item = data;
    newnode->next = NULL;
    if (front == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
} */

/* //? 4. In question 1, define a method to view rear element in the queue.
void viewRaer()
{
    if(rear==NULL)
    {
        cout<<"Queue is Empty."<<endl;
        return;
    }
    cout<<rear->item<<endl;
} */

/* //? 5. In question 1, define a method to view front element in the queue.
void viewFront()
{
    if(front==NULL)
    {
        cout<<"Queue is Empty."<<endl;
        return;
    }
    cout<<front->item<<endl;
} */

/* //? 6. In question 1, define a method to delete the front element of the queue.
void delFront()
{
    if (front == NULL)
    {
        cout << "Queue is Empty." << endl;
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
        front = front->next;
    }
    delete t;
} */

/* //? 7. In question 1, define a destructor to deallocates the memory.
~Queue()
{
    while(front!=NULL)
      delFront();
} */

/* //? 8. In question 1, define a copy constructor to implement deep copy.
Queue(const Queue &q)
{
    front = NULL;
    rear = NULL;
    if (q.front == NULL)
    {
        return;
    }
    node *temp = q.front;
    while (temp != NULL)
    {
        insert(temp->item);
        temp = temp->next;
    }
} */

/* //? 9. In question 1, define a copy assignment operator to implement deep copy.
const Queue &operator=(const Queue &q)
{
    if (this != &q)
    {
        while (front != NULL)
            delFront();
        node *temp = q.front;
        while (temp != NULL)
        {
            insert(temp->item);
            temp = temp->next;
        }
    }
    return *this;
} */

/* //? 10. In question 1, define a method to count number of elements present in the queue
int count()
{
    node *temp = front;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
} */