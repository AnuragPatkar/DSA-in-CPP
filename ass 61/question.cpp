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

//? 8. Define data structure Stack using class template

//? 9. Define data structure Queue using class template

//? 10. Define data structure deque using class template