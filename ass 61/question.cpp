//! Assignment-61: Template

/* //? 1. Define a function template which takes two arguments of same types and return the greater value.
#include <iostream>
using namespace std;
template <typename X>
X greater(X a, X b)
{
    return a > b ? a : b;
} */

/* //? 2. Define a function template to print values of an array of any type.
#include <iostream>
using namespace std;
template <typename X>
void printArray(X arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[]={1,2,3,4,5};
    float arr[]={2.5,3.5,4.5,6.5,7.5};
    char arr[5];
} */

/* //? 3. Define a function template to sort an array of any type.
#include <iostream>
using namespace std;
template <typename X>
void sortArray(X arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
} */

/* //? 4. Define data structure Array using class template
#include <iostream>
using namespace std;
template <class X>
class Array
{
private:
    int capacity;
    int lastIndex;
    X *ptr;

public:
    Array(int c)
    {
        capacity = c;
        lastIndex = -1;
        ptr = new X[capacity];
    }
    void insert(int index, X data)
    {
        if (lastIndex == capacity - 1)
        {
            cout << "Array is full" << endl;
            return;
        }
        if (index < 0 || index > lastIndex + 1)
        {
            cout << "Invalid index!" << endl;
            return;
        }
        lastIndex++;
        for (int i = lastIndex; i > index; i--)
        {
            ptr[i] = ptr[i - 1];
        }
        ptr[index] = data;
    }
    void append(X data)
    {
        if (lastIndex == capacity - 1)
        {
            cout << "Array is full" << endl;
            return;
        }
        lastIndex++;
        ptr[lastIndex] = data;
    }
    void del(X data)
    {
        int i, index = -1;
        for (i = 0; i <= lastIndex; i++)
        {
            if (ptr[i] == data)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            cout << "Element not found!" << endl;
            return;
        }
        for (i = index; i < lastIndex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        lastIndex--;
    }
    X getItem(int index)
    {
        if (index < 0 || index > lastIndex)
        {
            cout << "Invalid index!" << endl;
            return X(); // Default constructed value return karega
        }
        return ptr[index];
    }
    void display()
    {
        if (lastIndex == -1)
        {
            cout << "Array is empty!" << endl;
            return;
        }
        for (int i = 0; i <= lastIndex; i++)
        {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }
    ~Array()
    {
        delete[] ptr;
    }
}; */

/* //? 5. Define data structure Dynamic Array using class template
#include <iostream>
using namespace std;
template <class X>
class Array
{
private:
    int capacity;
    int lastIndex;
    X *ptr;

public:
    Array(int c)
    {
        capacity = c;
        lastIndex = -1;
        ptr = new X[capacity];
    }
    void resize()
    {
        X *temp;
        temp = new X[capacity * 2];
        for (int i = 0; i < capacity; i++)
        {
            temp[i] = ptr[i];
        }
        delete[] ptr;
        ptr = temp;
        capacity *= 2;
    }
    void insert(int index, X data)
    {
        if (lastIndex == capacity - 1)
        {
            resize();
        }
        if (index < 0 || index > lastIndex + 1)
        {
            cout << "Invalid index!" << endl;
            return;
        }
        lastIndex++;
        for (int i = lastIndex; i > index; i--)
        {
            ptr[i] = ptr[i - 1];
        }
        ptr[index] = data;
    }
    void append(X data)
    {
        if (lastIndex == capacity - 1)
        {
            resize();
        }
        lastIndex++;
        ptr[lastIndex] = data;
    }
    void del(X data)
    {
        int i, index = -1;
        for (i = 0; i <= lastIndex; i++)
        {
            if (ptr[i] == data)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            cout << "Element not found!" << endl;
            return;
        }
        for (i = index; i < lastIndex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        lastIndex--;
    }
    X getItem(int index)
    {
        if (index < 0 || index > lastIndex)
        {
            cout << "Invalid index!" << endl;
            return X(); // Default constructed value return karega
        }
        return ptr[index];
    }
    void display()
    {
        if (lastIndex == -1)
        {
            cout << "Array is empty!" << endl;
            return;
        }
        for (int i = 0; i <= lastIndex; i++)
        {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }
    ~Array()
    {
        delete[] ptr;
    }
}; */

/* //? 6. Define data structure Linked List using class template
#include <iostream>
using namespace std;
template <class X>
struct node
{
    X item;
    node<X> *next;
};
template <class X>
class SLL
{
private:
    node<X> *start;

public:
    SLL()
    {
        start = NULL;
    }
    void Atstart(X data)
    {
        node<X> *newnode = new node<X>;
        newnode->item = data;

        newnode->next = start;
        start = newnode;
    }
    void Atlast(X data)
    {
        node<X> *newnode = new node<X>;
        newnode->item = data;
        newnode->next = NULL;
        if (start == NULL)
        {
            start = newnode;
            return;
        }
        node<X> *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    int search(X data)
    {
        int index = 0;
        node<X> *t = start;
        while (t != NULL)
        {
            if (t->item == data)
                return index;
            t = t->next;
            index++;
        }
        return -1;
    }
    void afterNode(X key, X data)
    {
        node<X> *t = start;
        while (t != NULL)
        {
            if (t->item == key)
                break;
            t = t->next;
        }
        if (t == NULL)
        {
            cout << key << " Not Found in List." << endl;
            return;
        }
        node<X> *newnode = new node<X>;
        newnode->item = data;
        newnode->next = t->next;
        t->next = newnode;
    }
    void delFirst()
    {
        if (start == NULL)
        {
            cout << "List is Empty." << endl;
            return;
        }
        if (start->next == NULL)
        {
            delete start;
            start = NULL;
            return;
        }
        node<X> *t = start;
        start = start->next;
        delete t;
    }
    void delLast()
    {
        if (start == NULL)
        {
            cout << "List is Empty." << endl;
            return;
        }
        if (start->next == NULL)
        {
            delete start;
            start = NULL;
        }
        else
        {
            node<X> *t = start;
            node<X> *p = NULL;
            while (t->next != NULL)
            {
                p = t;
                t = t->next;
            }
            p->next = NULL;
            delete t;
        }
    }
    void delNode(X data)
    {
        if (start == NULL)
        {
            return;
        }
        if (start->item == data)
        {
            delete start;
            start = NULL;
            return;
        }
        node<X> *t = start;
        while (t->next->item != data || t != NULL)
        {
            t = t->next;
        }
        if (t != NULL)
        {
            node<X> *p = t->next;
            t->next = t->next->next;
            delete p;
        }
    }
    ~SLL()
    {
        while (start != NULL)
            delFirst();
    }
}; */

/* //? 7. Define data structure Doubly Linked List using class template
#include <iostream>
using namespace std;
template <class X>
struct node
{
    node<X> *prev;
    X item;
    node<X> *next;
};
template <class X>
class DLL
{
private:
    node<X> *start;

public:
    DLL()
    {
        start = NULL;
    }
    void Atstart(X data)
    {
        node<X> *newnode = new node<X>;
        newnode->item = data;
        newnode->prev = NULL;

        newnode->next = start;
        if (start != NULL)
        {
            start->prev = newnode;
        }
        start = newnode;
    }
    void Atlast(X data)
    {
        node<X> *newnode = new node<X>;
        newnode->item = data;
        newnode->next = NULL;
        if (start == NULL)
        {
            newnode->prev = NULL;
            start = newnode;
            return;
        }
        node<X> *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newnode->prev = temp;
        temp->next = newnode;
    }
    int search(X data)
    {
        int index = 0;
        node<X> *t = start;
        while (t != NULL)
        {
            if (t->item == data)
                return index;
            t = t->next;
            index++;
        }
        return -1;
    }
    void afterNode(X key, X data)
    {
        node<X> *t = start;
        while (t != NULL)
        {
            if (t->item == key)
                break;
            t = t->next;
        }
        if (t == NULL)
        {
            cout << key << " Not Found in List." << endl;
            return;
        }
        node<X> *newnode = new node<X>;
        newnode->item = data;
        newnode->next = t->next;
        newnode->prev = t;
        if (t->next != NULL)
        {
            t->next->prev = newnode;
        }
        t->next = newnode;
    }
    void delFirst()
    {
        if (start == NULL)
        {
            cout << "List is Empty." << endl;
            return;
        }
        if (start->next == NULL)
        {
            delete start;
            start = NULL;
            return;
        }
        node<X> *t = start;
        start = start->next;
        start->prev = NULL;
        delete t;
    }
    void delLast()
    {
        if (start == NULL)
        {
            cout << "List is Empty." << endl;
            return;
        }
        if (start->next == NULL)
        {
            delete start;
            start = NULL;
        }
        else
        {
            node<X> *t = start;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->prev->next = NULL;
            delete t;
        }
    }
    void delNode(X data)
    {
        if (start == NULL)
        {
            return;
        }
        if (start->item == data)
        {
            delete start;
            start = NULL;
            return;
        }
        node<X> *t = start;
        while (t->next->item != data || t != NULL)
        {
            t = t->next;
        }
        if (t != NULL)
        {
            node<X> *p = t->next;
            p->next->prev = t;
            t->next = t->next->next;
            delete p;
        }
    }
    ~DLL()
    {
        while (start != NULL)
            delFirst();
    }
}; */

/* //? 8. Define data structure Stack using class template
#include <iostream>
using namespace std;
template<class X>
class STACK
{
private:
    int capacity;
    int top;
    X*ptr;

public:
    STACK(int size)
    {
        capacity = size;
        top = -1;
        ptr = new X[capacity];
    }
    STACK(const STACK &s)
    {
        capacity = s.capacity;
        top = s.top;
        ptr = new X[capacity];

        for (int i = 0; i <= top; i++)
        {
            ptr[i] = s.ptr[i];
        }
    }
    const STACK &operator=(const STACK &s)
    {
        if (this == &s)
            return *this;

        delete[] ptr;
        capacity = s.capacity;
        top = s.top;
        ptr = new X[capacity];

        for (int i = 0; i <= top; i++)
        {
            ptr[i] = s.ptr[i];
        }

        return *this;
    }
    void push(X data)
    {
        if (top >= capacity - 1)
        {
            cout << "STACK is FULL." << endl;
            return;
        }
        ptr[++top] = data;
    }
    X peek()
    {
        if (top < 0)
        {
            cout << "STACK is Empty." << endl;
            throw out_of_range("Stack is empty");
        }
        return ptr[top];
    }
    X pop()
    {
        if (top < 0)
        {
            cout << "STACK is Empty." << endl;
            throw out_of_range("Stack is empty");
        }
        return ptr[top--];
    }
    bool stackOverflow()
    {
        return top >= capacity - 1;
    }
    bool stackUnderflow()
    {
        return top < 0;
    }
    ~STACK()
    {
        delete[] ptr;
    }
}; */

/* //! stack using linked list
#include <iostream>
using namespace std;
template <class X>
struct node
{
    X item;
    node<X> *next;
};
template <class X>
class STACK
{
private:
    node<X> *top;

public:
    STACK() { top = NULL; }
    STACK(STACK &s)
    {
        if (s.top == NULL)
            return;

        node<X> *t = s.top;
        node<X> *prev = NULL;
        while (t)
        {
            node<X> *newnode = new node<X>;
            newnode->item = t->item;
            newnode->next = NULL;

            if (prev)
            {
                prev->next = newnode;
            }
            else
            {
                top = newnode;
            }
            prev = newnode;
            t = t->next;
        }
    }
    STACK &operator=(STACK &s)
    {
        if (this != &s)
        {
            // Clear the current stack
            while (top)
            {
                pop();
            }

            // Copy the new stack
            if (s.top == NULL)
            {
                top = NULL;
            }
            else
            {
                node<X> *t = s.top;
                node<X> *prev = NULL;
                while (t)
                {
                    node<X> *newnode = new node<X>;
                    newnode->item = t->item;
                    newnode->next = NULL;

                    if (prev)
                    {
                        prev->next = newnode;
                    }
                    else
                    {
                        top = newnode;
                    }
                    prev = newnode;
                    t = t->next;
                }
            }
        }
        return *this;
    }
    void push(X data)
    {
        node<X> *newnode = new node<X>;
        newnode->item = data;
        newnode->next = top;
        top = newnode;
    }
    X pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow!" << endl;
            throw out_of_range("Stack is Empty");
        }
        node<X> *temp = top;
        X popped = top->item;
        top = top->next;
        delete temp;
        return popped;
    }
    X peek()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow!" << endl;
            throw out_of_range("Stack is Empty");
        }
        return top->item;
    }
    void reverse()
    {
        node<X> *prev = NULL;
        node<X> *current = top;
        node<X> *next = NULL;

        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        top = prev;
    }
    ~STACK()
    {
        while (top)
        {
            node<X> *temp = top;
            top = top->next;
            delete temp;
        }
    }
}; */

/* //? 9. Define data structure Queue using class template
#include <iostream>
using namespace std;
template <class X>
class Queue
{
private:
    int capacity;
    int front, rear;
    X *ptr;

public:
    Queue()
    {
        capacity = 0;
        front = -1;
        rear = -1;
        ptr = NULL;
    }
    Queue(int size)
    {
        capacity = size;
        front = -1;
        rear = -1;
        if (capacity > 0)
            ptr = new X[capacity];
        else
            ptr = NULL;
    }
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
        ptr = new X[capacity];
        for (int i = 0; i < capacity; i++)
        {
            ptr[i] = q.ptr[i];
        }
    }
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
            ptr = new X[capacity];
            for (int i = 0; i < capacity; i++)
            {
                ptr[i] = q.ptr[i];
            }
        }
        return *this;
    }
    void insert(X data)
    {
        if (front == 0 && rear == capacity - 1 || front == rear + 1)
        {
            cout << "QUEUE is FULL." << endl;
            return;
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
    }
    void viewRear()
    {
        if (rear == -1)
        {
            cout << "QUEUE is Empty." << endl;
            return;
        }
        cout << ptr[rear] << endl;
    }
    void viewFront()
    {
        if (front == -1)
        {
            cout << "QUEUE is Empty." << endl;
            return;
        }
        cout << ptr[front] << endl;
    }
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
    }
    bool overflow()
    {
        return (front == 0 && rear == capacity - 1 || front == rear + 1);
    }
    bool underflow()
    {
        return front == -1;
    }
    int count()
    {
        if (front == -1)
            return 0;
        else if (front > rear)
            return capacity - front + rear + 1;
        else
            return rear - front + 1;
    }
    ~Queue()
    {
        if(ptr!=NULL)
          delete[] ptr;
    }
}; */

/* //! Queue using linked list
#include <iostream>
using namespace std;
template <class X>
struct node
{
    X item;
    node<X> *next;
};
template <class X>
class Queue
{
private:
    node<X> *front, *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    Queue(X data)
    {
        node<X> *newnode = new node<X>;
        newnode->item = data;
        newnode->next = NULL;
        front = newnode;
        rear = newnode;
    }
    Queue(const Queue &q)
    {
        front = NULL;
        rear = NULL;
        if (q.front == NULL)
        {
            return;
        }
        node<X> *temp = q.front;
        while (temp != NULL)
        {
            insert(temp->item);
            temp = temp->next;
        }
    }
    const Queue &operator=(const Queue &q)
    {
        if (this != &q)
        {
            while (front != NULL)
                delFront();
            node<X> *temp = q.front;
            while (temp != NULL)
            {
                insert(temp->item);
                temp = temp->next;
            }
        }
        return *this;
    }
    void insert(X data)
    {
        node<X> *newnode = new node<X>;
        newnode->item = data;
        newnode->next = NULL;
        if (front == NULL)
        {
            front = newnode;
            rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }
    void viewRaer()
    {
        if (rear == NULL)
        {
            cout << "Queue is Empty." << endl;
            return;
        }
        cout << rear->item << endl;
    }
    void viewFront()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty." << endl;
            return;
        }
        cout << front->item << endl;
    }
    void delFront()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty." << endl;
            return;
        }
        node<X> *t = front;
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
    }
    int count()
    {
        node<X> *temp = front;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ~Queue()
    {
        while (front != NULL)
            delFront();
    }
}; */

/* //? 10. Define data structure deque using class template
#include <iostream>
using namespace std;
template <class X>
class Deque
{
private:
    int capacity;
    int front, rear;
    X *ptr;

public:
    Deque();
    Deque(int);
    Deque(const Deque &d);
    const Deque &operator=(const Deque &d);
    void insertFront(X);
    void insertBack(X);
    void delFront();
    void delBack();
    bool underflow();
    bool overflow();
    X getFront();
    X getBack();
    ~Deque();
};
template <class X>
Deque<class X>::Deque()
{
    capacity = 0;
    front = -1;
    rear = -1;
    ptr = NULL;
}
template <class X>
Deque<class X>::Deque(int c)
{
    capacity = c;
    front = -1;
    rear = -1;
    if (capacity <= 0)
        ptr = NULL;
    else
        ptr = new int[capacity];
}
template <class X>
Deque<class X>::Deque(const Deque &d)
{
    if (d.capacity == 0)
    {
        ptr = NULL;
        return;
    }
    capacity = d.capacity;
    front = d.front;
    rear = d.rear;
    ptr = new X[capacity];
    for (int i = 0; i < capacity; i++)
    {
        ptr[i] = d.ptr[i];
    }
}
template <class X>
const Deque<class X> &Deque<class X>::operator=(const Deque &d)
{
    if (this != &d)
    {
        if (ptr != NULL)
        {
            delete[] ptr;
        }
        if (d.capacity == 0)
            return;
        capacity = d.capacity;
        front = d.front;
        rear = d.rear;
        ptr = new X[capacity];
        for (int i = 0; i < capacity; i++)
        {
            ptr[i] = d.ptr[i];
        }
    }
    return *this;
}
template <class X>
void Deque<class X>::insertBack(X data)
{
    if (overflow())
    {
        cout << "Deque is Full." << endl;
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == capacity - 1)
    {
        rear = 0;
    }
    else
        rear++;
    ptr[rear] = data;
}
template <class X>
void Deque<class X>::insertFront(X data)
{
    if (overflow())
    {
        cout << "Deque is Full." << endl;
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        ptr[rear] = data;
    }
    else if (front > 0)
    {
        front--;
        ptr[front] = data;
    }
    else
    {
        rear++;
        for (int i = rear; i > front; i--)
        {
            ptr[i] = ptr[i - 1];
        }
        ptr[front] = data;
    }
}
template <class X>
void Deque<class X>::delFront()
{
    if (front == -1)
    {
        cout << "Duque is Empty." << endl;
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
        front++;
    }
}
template <class X>
void Deque<class X>::delBack()
{
    if (front == -1)
    {
        cout << "Duque is Empty." << endl;
        return;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        rear = capacity - 1;
    }
    else
    {
        rear--;
    }
}
template <class X>
bool Deque<class X>::overflow()
{
    return (front == 0 && rear == capacity - 1 || front == rear + 1);
}
template <class X>
bool Deque<class X>::underflow()
{
    return front == -1;
}
template <class X>
X Deque<class X>::getFront()
{
    if (underflow())
    {
        cout << "Deque is Empty." << endl;
        return;
    }
    return ptr[front];
}
template <class X>
X Deque<class X>::getBack()
{
    if (underflow())
    {
        cout << "Deque is Empty." << endl;
        return;
    }
    return ptr[rear];
}
template <class X>
Deque<class X>::~Deque()
{
    if (ptr != NULL)
        delete[] ptr;
} */

/*//! Deque using Doubly linked list 
#include <iostream>
using namespace std;
template <class X>
struct node
{
    node<X> *prev;
    X item;
    node<X> *next;
};
template <class X>
class Deque
{
private:
    node<X> *front, *rear;

public:
    Deque();
    Deque(const Deque &d);
    const Deque &operator=(const Deque &d);
    void insertFront(X data);
    void insertRear(X data);
    void delFront();
    void delRear();
    X *getFront();
    X *getRear();
    bool isEmpty();
    ~Deque();
};
template <class X>
Deque<class X>::Deque()
{
    front = NULL;
    rear = NULL;
}
template <class X>
Deque<class X>::Deque(const Deque &d)
{
    front = NULL;
    rear = NULL;
    if (d.front == NULL)
        return;
    node<X> *t = d.front;
    while (t != NULL)
    {
        insertRear(t->item);
        t = t->next;
    }
}
template <class X>
const Deque<class X> &Deque<class X>::operator=(const Deque &d)
{
    if (this != &d)
    {
        while (front != NULL)
        {
            delFront();
        }
        if (d.front == NULL)
            return *this;
        node <X>*t = d.front;
        while (t != NULL)
        {
            insertRear(t->item);
            t = t->next;
        }
    }
    return *this;
}
template <class X>
void Deque<class X>::insertFront(X data)
{
    node<X> *newnode = new node<X>;
    newnode->item = data;
    newnode->prev = NULL;
    if (front == NULL)
    {
        front = newnode;
        rear = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = front;
        front->prev = newnode;
        front = newnode;
    }
}
template <class X>
void Deque<class X>::insertRear(X data)
{
    node<X> *newnode = new node<X>;
    newnode->item = data;
    newnode->next = NULL;
    if (front == NULL)
    {
        front = newnode;
        rear = newnode;
        newnode->prev = NULL;
    }
    else
    {
        newnode->prev = rear;
        rear->next = newnode;
        rear = newnode;
    }
}
template <class X>
void Deque<class X>::delFront()
{
    if (front == NULL)
    {
        cout << "Deque is Empty." << endl;
        return;
    }
    node<X> *t = front;
    if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
        front->prev = NULL;
    }
    delete t;
}
template <class X>
void Deque<class X>::delRear()
{
    if (front == NULL)
    {
        cout << "Deque is Empty." << endl;
        return;
    }
    node<X> *t = rear;
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
}
template <class X>
X *Deque<class X>::getFront()
{
    if (front == NULL)
    {
        cout << "Deque is Empty." << endl;
        return NULL;
    }
    return front->item;
}
template <class X>
X *Deque<class X>::getRear()
{
    if (front == NULL)
    {
        cout << "Deque is Empty." << endl;
        return NULL;
    }
    return rear->item;
}
template <class X>
bool Deque<class X>::isEmpty()
{
    return (front == NULL);
}
template <class X>
Deque<class X>::~Deque()
{
    while (front != NULL)
        delFront();
} */