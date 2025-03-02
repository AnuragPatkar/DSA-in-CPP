//! Assignment-49: Queue using arrays

/* //? 1. Define a class Queue with capacity, front, rear and ptr pointer as member variables. Implement queue using array.
#include <iostream>
using namespace std;
class Queue
{
private:
    int capacity;
    int front, rear;
    int *ptr;
public:
    Queue();
    Queue(const Queue &q);
    const Queue& operator=(const Queue &q);
    ~Queue();

}; */

/* //? 2. In question 1, define a parameterzied constructor to initialise member variables.
Queue(int size)
{
    capacity = size;
    front = -1;
    rear = -1;
    ptr = new int[capacity];
} */

/* //? 3. In question 1, define a method to insert a new element at the rear in the queue.
void insert(int data)
{
    if
        return (front == 0 && rear == capacity - 1 || front == rear + 1);
    {
        cout << "QUEUE is FULL." << endl;
    }
    else
    {
        if (front == -1)
        {
            front++;
            rear++;
        }
        else if (rear == capacity - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        ptr[rear] = data;
    }
} */

/* //? 4. In question 1, define a method to view rear element of the queue.
void viewRear()
{
    if (rear == -1)
    {
        cout << "QUEUE is Empty." << endl;
        return;
    }
    cout << ptr[rear] << endl;
} */

/* //? 5. In question 1, define a method to view front element of the queue.
void viewFront()
{
    if (front == -1)
    {
        cout << "QUEUE is Empty." << endl;
        return;
    }
    cout << ptr[front] << endl;
} */

/* //? 6. In question 1, define a method to delete the front element of the queue.
void delFront()
{

    if (front == -1)
    {
        cout << "QUEUE is Empty." << endl;
        return;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == capacity - 1)
    {
        front = 0;    
    }
    else
    {
        front++; // Move front forward (No shifting needed)
    }
} */

/* //? 7. In question 1, define a destructor to deallocates the memory.
~Queue()
{
    delete[] ptr;
} */

/* //? 8. In question 1, define a method to check queue overflow
bool overflow()
{
    return (front==0&& rear == capacity - 1|| front == rear + 1);
} */

/* //? 9. In question 1, define a method to check queue underflow.
bool underflow()
{
    return front == -1;
} */

/* //? 10. In question 1, Define a method to count number of elements present in the queue
int count()
{
    if (front == -1)
        return 0;
    else if(front>rear)
        return capacity-front+rear+1;
    else 
         return rear - front + 1;
} */

/* //? 11. In question 1, define a copy constructor to implement deep copy.
Queue(const Queue &q)
{
    if (q.front == -1)
    {
        capacity = 0;
        front = -1;
        rear = -1;
        ptr = NULL;
        return;
    }
    capacity = q.capacity;
    front = q.front;
    rear = q.rear;
    ptr = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
        ptr[i] = q.ptr[i];
    }
} */

/* //? 12. In question 1, define a copy assignment operator to implement deep copy
const Queue &operator=(const Queue &q)
{
    if (this != &q)
    {
        if (ptr != NULL)
            delete[] ptr;
        if (q.front == -1)
        {
            capacity = 0;
            front = -1;
            rear = -1;
            ptr = NULL;
            return *this;
        }
        capacity = q.capacity;
        front = q.front;
        rear = q.rear;
        ptr = new int[capacity];
        for (int i = 0; i <capacity; i++)
        {
            ptr[i] = q.ptr[i];
        }
    }
    return *this;
} */