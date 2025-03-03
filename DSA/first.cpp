/* //! First Task: Array
#include <iostream>
#include <stdio.h>
using namespace std;
class Array
{
private:
    int capicity;
    int lastindex;
    int *ptr;

public:
    Array();
    Array(Array &); // deep copy
    Array &operator=(const Array &);
    void createArray(int);
    void insert(int, int);
    void append(int);
    int getItem(int);
    bool isEmpty();
    bool isFull();
    void delValue(int);
    void delIndex(int);
    void edit(int, int);
    int count();
    int getCapicity();
    void sort();
    void display();
    int greatest();
    int smallest();
    bool search(int);
    int sum_of_all_elements();
    float average();
    void rotate_right();
    void remove_duplicate();
    int second_greatest();
    void swap(int, int);
    ~Array();
};
Array::Array()
{
    ptr = NULL;
}
Array::Array(Array &arr)
{
    capicity = arr.capicity;
    lastindex = arr.lastindex;
    ptr = new int[capicity];
    for (int i = 0; i <= lastindex; i++)
    {
        ptr[i] = arr.ptr[i];
    }
}
Array &Array::operator=(const Array &arr)
{
    capicity = arr.capicity;
    lastindex = arr.lastindex;
    if (ptr != NULL)
    {
        delete[] ptr;
    }
    ptr = new int[capicity];
    for (int i = 0; i <= lastindex; i++)
    {
        ptr[i] = arr.ptr[i];
    }
    return *this;
}
void Array::createArray(int c)
{
    this->capicity = c;
    lastindex = -1;
    if (ptr != NULL)
    {
        delete[] ptr;
    }
    ptr = new int[capicity];
}
void Array::insert(int index, int value)
{
    if (index < 0 || index > lastindex + 1)
    {
        cout << "Invalid index or array is full\n";
        return;
    }

    for (int i = lastindex; i >= index; i--)
    {
        ptr[i + 1] = ptr[i];
    }

    ptr[index] = value;
    lastindex++;
}
void Array::append(int value)
{
    if (isFull())
    {
        cout << "Error: Array is full.\n";
        return;
    }

    lastindex++;
    ptr[lastindex] = value;
}
int Array::getItem(int index)
{
    if (index < 0 || index > lastindex)
    {
        cout << "Invalid index\n";
        return -1;
    }
    return ptr[index];
}
bool Array::isEmpty()
{
    return lastindex == -1;
}
bool Array::isFull()
{
    return lastindex == capicity - 1;
}
void Array::delValue(int value)
{
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        if (value == ptr[i])
        {
            break;
        }
    }
    if (i > lastindex)
    {
        cout << "Value not found\n";
        return;
    }

    for (int j = i; j < lastindex; j++)
    {
        ptr[j] = ptr[j + 1];
    }
    lastindex--;
}
void Array::delIndex(int index)
{
    if (index < 0 || index > lastindex)
    {
        cout << "Invalid index\n";
        return;
    }
    for (int i = index; i < lastindex; i++)
    {
        ptr[i] = ptr[i + 1];
    }
    lastindex--;
}
void Array::edit(int index, int value)
{
    if (index < 0 || index > lastindex)
    {
        cout << "Invalid index\n";
        return;
    }
    ptr[index] = value;
}
int Array::count()
{
    return lastindex + 1;
}
int Array::getCapicity()
{
    return capicity;
}
void Array::sort()
{
    int i, j, temp;
    for (i = 0; i <= lastindex; i++)
    {
        for (j = 0; j <= lastindex - i - 1; j++)
        {
            if (ptr[j] > ptr[j + 1])
            {
                // Manually swapping values without using swap()
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
}
int Array::greatest()
{
    int i, max = 0;
    for (i = 0; i <= lastindex; i++)
    {
        if (ptr[i] > max)
            max = ptr[i];
    }
    return max;
}
int Array::smallest()
{
    int i, min = ptr[0];
    for (i = 0; i <= lastindex; i++)
    {
        if (ptr[i] < min)
            min = ptr[i];
    }
    return min;
}
bool Array::search(int data)
{
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        if (ptr[i] == data)
            return true;
    }
    return false;
}
int Array::sum_of_all_elements()
{
    int sum = 0;
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        sum += ptr[i];
    }
    return sum;
}
float Array::average()
{
    float sum = 0;
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        sum += ptr[i];
    }
    return sum / lastindex;
}
void Array::rotate_right()
{
    int i;
    int temp = ptr[lastindex];
    for (i = lastindex; i > 0; i--)
    {
        ptr[i] = ptr[i - 1];
    }
    ptr[0] = temp;
}
void Array::remove_duplicate()
{
    int i, j;
    for (i = 0; i <= lastindex; i++)
    {
        if (ptr[i] != -1)
        {
            for (j = i + 1; j <= lastindex; j++)
            {
                if (ptr[i] == ptr[j])
                    ptr[j] = -1;
            }
        }
    }
    int temp[lastindex];

    for (i = 0, j = 0; i <= lastindex; i++)
    {
        if (ptr[i] != -1)
        {
            temp[j] = ptr[i];
            j++;
        }
    }
    lastindex = j - 1;
    for (i = 0; i <= lastindex; i++)
    {
        ptr[i] = temp[i];
    }
}
int Array::second_greatest()
{
    if (lastindex < 1)
    {
        cout << "Error:Not enough element." << endl;
        return -1;
    }
    int max = this->greatest();
    int i, second_max = this->smallest();
    for (i = 0; i <= lastindex; i++)
    {
        if (ptr[i] < max && ptr[i] > second_max)
        {
            second_max = ptr[i];
        }
    }
    return second_max;
}
void Array::swap(int i1, int i2)
{
    if (i1 < 0 || i1 > lastindex || i2 < 0 || i2 > lastindex)
    {
        cout << "Invalid index for swaping." << endl;
        return;
    }
    int temp;
    temp=ptr[i1];
    ptr[i1]=ptr[i2];
    ptr[i2]=temp;
}
void Array::display()
{
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        cout << ptr[i] << " ";
    }
}
Array::~Array()
{
    delete[] ptr;
}
int main()
{
    Array a1;
    a1.createArray(5);

    a1.insert(0, 6);
    a1.insert(1, 3);
    a1.insert(2, 9);
    a1.insert(3, 5);
    a1.insert(4, 11);
    a1.insert(5, 10);

    cout << "Before Sorting: ";
    a1.display();

    // a1.sort();

    // cout << "After Sorting: ";
    // a1.display();

    // cout << a1.smallest();
    cout << endl;
    // a1.rotate_right();

    // a1.remove_duplicate();
    // a1.display();

    // cout << a1.second_greatest();
    a1.swap(3,4);
    a1.display();
    return 0;
}*/

/* //! Second Task: Dynamic Array
#include <iostream>
using namespace std;
class DynArray
{
private:
    int capacity;
    int lastindex;
    int *ptr;

public:
    DynArray(int);
    DynArray(DynArray &arr);
    DynArray &operator=(DynArray &);
    void doubleArray();
    void halfArray();
    int cap_of_array();
    bool isEmpty();
    bool isFull();
    void append(int);
    void insert(int, int);
    void edit(int, int);
    void del(int);
    int getElement(int);
    int count();
    int findElement(int);
    ~DynArray();
};
DynArray::DynArray(int c)
{
    capacity = c;
    lastindex = -1;
    ptr = new int[capacity];
}
DynArray::DynArray(DynArray &arr)
{
    capacity = arr.capacity;
    lastindex = arr.lastindex;
    ptr = new int[capacity];
    for (int i = 0; i <= lastindex; i++)
    {
        ptr[i] = arr.ptr[i];
    }
}
DynArray &DynArray::operator=(DynArray &arr)
{
    capacity = arr.capacity;
    lastindex = arr.lastindex;
    if (ptr != NULL)
        delete[] ptr;
    ptr = new int[capacity];
    for (int i = 0; i <= lastindex; i++)
    {
        ptr[i] = arr.ptr[i];
    }
    return *this;
}

void DynArray::doubleArray()
{
    int *temp = new int[capacity * 2];
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        temp[i] = ptr[i];
    }
    if (ptr != NULL)
        delete[] ptr;
    ptr = temp;
    capacity *= 2;
}

void DynArray::halfArray()
{
    if (capacity / 2 < lastindex + 1) // 🔥 Ensure we don’t lose data
    {
        cout << "Cannot shrink array, data loss risk!" << endl;
        return;
    }
    int *temp = new int[capacity / 2];
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        temp[i] = ptr[i];
    }
    if (ptr != NULL)
        delete[] ptr;
    ptr = temp;
    capacity /= 2;
}
int DynArray::cap_of_array()
{
    return capacity;
}
bool DynArray::isEmpty()
{
    return lastindex == -1;
}
bool DynArray::isFull()
{
    return lastindex == capacity - 1;
}
void DynArray::append(int data)
{
    if (lastindex == capacity - 1)
    {
        doubleArray();
    }
    lastindex++;

    ptr[lastindex] = data;
}
void DynArray::insert(int index, int data)
{
    if (index < 0 || index > lastindex + 1) // 🔹 Invalid index check
    {
        cout << "Error: Invalid index!" << endl;
        return;
    }
    if (lastindex == capacity - 1)
    {
        doubleArray();
    }
    int i;
    for (i = lastindex; i >= index; i--)
    {
        ptr[i + 1] = ptr[i];
    }
    ptr[index] = data;
    lastindex++;
}
void DynArray::edit(int index, int data)
{
    if (index < 0 || index > lastindex)
    {
        cout << "Invalid Index." << endl;
        return;
    }
    ptr[index] = data;
}
void DynArray::del(int index)
{
    if (index < 0 || index > lastindex)
    {
        cout << "Invalid Index." << endl;
        return;
    }
    int i;
    for (i = index; i < lastindex; i++)
    {
        ptr[i] = ptr[i + 1];
    }
    lastindex--;
    if (capacity > 1 && lastindex + 1 <= capacity / 2)
        halfArray();
}
int DynArray::getElement(int index)
{
    if (index < 0 || index > lastindex)
    {
        cout << "invalid index.";
        return -1;
    }
    return ptr[index];
}
int DynArray::findElement(int data)
{
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        if (ptr[i] == data)
            return i;
    }
    return -1;
}
int DynArray::count()
{
    return lastindex + 1;
}
DynArray::~DynArray()
{
    delete[] ptr;
} */

/* //! Third Task: Singly linked list
#include <iostream>
#include<stdio.h>
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
    node *head;

public:
    SLL()
    {
        head = NULL;
    }
    SLL(const SLL &list)
    {
        head = NULL;
        node *temp = list.head;
        while (temp != NULL) // Fix: Changed 'head' to 'temp'
        {
            AtLast(temp->item);
            temp = temp->next;
        }
    }

    SLL &operator=(const SLL &list)
    {
        if (this != &list)
        {
            while (head != NULL)
                delFirst(); // Clear existing list

            node *temp = list.head;
            while (temp != NULL)
            {
                AtLast(temp->item);
                temp = temp->next;
            }
        }
        return *this;
    }

    void AtStart(int data)
    {
        node *newnode = new node(data);
        newnode->next = head;
        head = newnode;
    }
    void AtLast(int data)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    void After(int key, int data)
    {
        node *newnode = new node(data);
        node *temp = head;
        while (temp->item != key)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    void delFirst()
    {
        node *temp = head;
        head = temp->next;
        delete temp;
    }
    void delLast()
    {
        if (head == NULL)
            return;
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    void delNode(int data)
    {

        if (head == NULL)
        {
            cout << "List is empty. Deletion not possible!" << endl;
            return;
        }

        if (head->item == data) // If head node is to be deleted
        {
            delFirst();
            return;
        }

        node *temp = head;

        while (temp->next != NULL && temp->next->item != data)
        {
            temp = temp->next;
        }

        if (temp->next == NULL) // If data is not found
        {
            cout << "Node with value " << data << " not found!" << endl;
            return;
        }

        node *delNode = temp->next;    // Node to be deleted
        temp->next = temp->next->next; // Unlink node
        delete delNode;                // Free memory
    }
    void edit(int old_data, int new_data)
    {
        node *temp = head;
        while (temp != NULL && temp->item != old_data)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            cout << "Node with value " << old_data << " not found!" << endl;
            return;
        }
        temp->item = new_data;
    }
    int search(int key)
    {
        int index = 0;
        node *temp = head;

        while (temp != NULL)
        {
            if (temp->item == key)
            {
                return index;
            }
            temp = temp->next;
            index++;
        }

        return -1;
    }
    int count()
    {
        int c = 0;
        node *temp = head;

        while (temp != NULL)
        {
            temp = temp->next;
            c++;
        }

        return c;
    }
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->item << "-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~SLL()
    {
        while (head != NULL)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    SLL list;
    list.AtStart(10);
    list.AtStart(20);
    list.AtStart(25);
    list.AtLast(5);
    list.After(20, 15);

    list.display();

    SLL list2 = list;
    list2.display();

    return 0;
} */

/* //! Fourth Task: Doubly linked list
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
        prev = NULL;
        item = data;
        next = NULL;
    }
};
class DLL
{
private:
    node *start;

public:
    DLL() { start = NULL; }
    DLL(DLL &list)
    {
        start = NULL;
        node *temp = list.start;
        while (temp != NULL)
        {
            AtLast(temp->item);
            temp = temp->next;
        }
    }
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
    }
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
    }
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
    }
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
    }
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
    }
    void delFirst()
    {
        if (start == NULL)
            return;
        node *temp = start;
        start = start->next;
        if (start != NULL)
        {
            start->prev = NULL;
        }
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
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }
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
    }
    ~DLL()
    {
        while (start != NULL)
            delFirst();
    }
};*/

/* //! Fifth Task: Circular Linked List
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

public:
    CLL()
    {
        last = NULL;
    }
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
    }
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
    }
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
    }
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
    }
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
    }
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
    }
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
    }
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
    }
    void delNode(int data)
    {
        if (last == NULL)
            return;
        node *temp = last->next;
        bool found = false;
        if (temp->item == data && temp == temp->next)
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
    }
    ~CLL()
    {
        while (last)
            delFirst();
    }
}; */

/* //! Sixth Task: Circular Doubly Linked list
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
    CDLL()
    {
        last = NULL;
    }
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
    }
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
    }
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
    }
    void insertAtLast(int data)
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
            last = newnode;
        }
    }
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
    }
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
    }
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
    }
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
    }
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
    }
    ~CDLL()
    {
        while (last)
            delFirst();
    }
}; */

/* //! 7th Task: STACK using Arrays
#include <iostream>
using namespace std;
class STACK
{
private:
    int capacity;
    int top;
    int *ptr;

public:
    STACK(int size)
    {
        capacity = size;
        top = -1;
        ptr = new int[capacity];
    }
    STACK(const STACK &s)
    {
        capacity = s.capacity;
        top = s.top;
        ptr = new int[capacity];

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
        ptr = new int[capacity];

        for (int i = 0; i <= top; i++)
        {
            ptr[i] = s.ptr[i];
        }

        return *this;
    }
    void push(int data)
    {
        if (top >= capacity - 1)
        {
            cout << "STACK is FULL." << endl;
            return;
        }
        ptr[++top] = data;
    }
    int peek()
    {
        if (top < 0)
        {
            cout << "STACK is Empty." << endl;
            return -1;
        }
        return ptr[top];
    }
    int pop()
    {
        if (top < 0)
        {
            cout << "STACK is Empty." << endl;
            return -1;
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

/* //! 8th Task: STACK using Dynamic Array
#include <iostream>
using namespace std;
class DynArray
{
private:
    int capacity;
    int top;
    int *ptr;

public:
    DynArray(int size)
    {
        capacity = size;
        top = -1;
        ptr = new int[capacity];
    }
    DynArray(const DynArray &s)
    {
        capacity = s.capacity;
        top = s.top;
        ptr = new int[capacity];
        for (int i = 0; i <= top; i++)
        {
            ptr[i] = s.ptr[i];
        }
    }
    const DynArray &operator=(const DynArray &s)
    {
        if (this == &s)
            return *this;

        delete[] ptr;

        capacity = s.capacity;
        top = s.top;
        ptr = new int[capacity];
        for (int i = 0; i <= top; i++)
        {
            ptr[i] = s.ptr[i];
        }
        return *this;
    }
    void push(int data)
    {
        if (top >= capacity - 1)
        {
            int *temp = new int[capacity * 2];
            for (int i = 0; i <= top; i++)
            {
                temp[i] = ptr[i];
            }
            delete[] ptr;
            ptr = temp;
            capacity *= 2;
        }
        ptr[++top] = data;
    }
    int pop()
    {
        if (top < 0)
        {
            cout << "STACK is Empty." << endl;
            return -1;
        }
        return ptr[top--];
    }
    int peek()
    {
        if (top < 0)
        {
            return -1;
        }
        return ptr[top];
    }
    bool stackUnderflow()
    {
        return top < 0;
    }
    bool stackOverflow()
    {
        return top >= capacity - 1;
    }
    ~DynArray()
    {
        delete[] ptr;
    }
}; */

/* //! 9th Task: STACK using Linked list
#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};
class STACK
{
private:
    node *top;

public:
    STACK() { top = NULL; }
    STACK(STACK &s)
    {
        if (s.top == NULL)
        {
            top = NULL;
            return;
        }
        node *t = s.top;
        s.reverse();
        while (t)
        {
            push(t->item);
            t = t->next;
        }
        s.reverse();
    }
    STACK &operator=(STACK &s)
    {
        if (this != &s)
        {
            if (top != NULL)
            {
                while (top)
                    pop();
            }
            if (s.top == NULL)
            {
                top = NULL;
                return *this;
            }

            node *t = s.top;
            s.reverse();
            while (t)
            {
                push(t->item);
                t = t->next;
            }
            s.reverse();
        }
        return *this;
    }
    void push(int data)
    {
        node *newnode = new node();
        newnode->item = data;
        newnode->next = top;
        top = newnode;
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        node *temp = top;
        top = top->next;
        delete temp;
    }
    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return top->item;
    }
    void reverse()
    {
        STACK S1;
        while (top)
        {
            S1.push(peek());
            pop();
        }
        top = S1.top;
        S1.top = NULL;
    }
    ~STACK()
    {
        while (top)
        {
            node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};*/

/* //! 10th Task: Queue using Arrays
#include <iostream>
using namespace std;
class Queue
{
private:
    int capacity;
    int front, rear;
    int *ptr;

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
        ptr = new int[capacity];
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
        ptr = new int[capacity];
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
            ptr = new int[capacity];
            for (int i = 0; i <capacity; i++)
            {
                ptr[i] = q.ptr[i];
            }
        }
        return *this;
    }
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
        return (front==0&& rear == capacity - 1|| front == rear + 1);
    }
    bool underflow()
    {
        return front == -1;
    }
    int count()
    {
        if (front == -1)
            return 0;
        else if(front>rear)
            return capacity-front+rear+1;
        else
            return rear - front + 1;
    }
    ~Queue()
    {
        delete[] ptr;
    }
}; */

/* //! 11th Task: Queue using Dynamic Array
#include <iostream>
using namespace std;
class QUEUE
{
private:
    int capacity;
    int front, rear;
    int *ptr;

public:
    QUEUE()
    {
        capacity = 0;
        front = -1;
        rear = -1;
        ptr = NULL;
    }
    QUEUE(int data)
    {
        capacity = data;
        front = -1;
        rear = -1;
        ptr = new int[capacity];
    }
    QUEUE(const QUEUE &q)
    {
        if (q.front == -1)
        {
            capacity = 0;
            front = -1;
            rear = -1;
            ptr = NULL;
        }
        capacity = q.capacity;
        front = q.front;
        rear = q.rear;
        ptr = new int[capacity];
        for (int i = front; i <= rear; i++)
        {
            ptr[i] = q.ptr[i];
        }
    }
    const QUEUE &operator=(const QUEUE &q)
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
            }
            else
            {
                capacity = q.capacity;
                front = q.front;
                rear = q.rear;
                ptr = new int[capacity];
                for (int i = front; i <= rear; i++)
                {
                    ptr[i] = q.ptr[i];
                }
            }
        }
        return *this;
    }
    void insert(int data)
    {
        if (rear == capacity - 1)
        {
            int *temp = new int[capacity * 2];
            for (int i = front; i <= rear; i++)
            {
                temp[i - front] = ptr[i];
            }
            delete[] ptr;
            ptr = temp;
            rear=rear-front;
            front=0;
            capacity*=2;
        }
        if (front == -1)
        {
            front=0;
            rear=0;
        }
        else
        {
            rear++;
        }
        ptr[rear] = data;
    }
    void viewRear()
    {
        if (front == -1)
        {
            cout << "Queue if Full." << endl;
            return;
        }
        cout << ptr[rear] << endl;
    }
    void viewFront()
    {
        if (front == -1)
        {
            cout << "Queue if Full." << endl;
            return;
        }
        cout << ptr[front] << endl;
    }
    void delFront()
    {
        if (front == -1)
        {
            cout << "Queue if Full." << endl;
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
    bool underflow()
    {
        return front == -1;
    }
    int count()
    {
        if (front == -1)
        {
            cout << "Queue is empty." << endl;
            return 0;
        }
        return rear + 1 - front;
    }
    ~QUEUE()
    {
        delete[] ptr;
    }
}; */

/* //! 12th Task: Queue using linked list
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
    node *front, *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    Queue(int data)
    {
        node *newnode = new node();
        newnode->item = data;
        newnode->next = NULL;
        front = newnode;
        rear = newnode;
    }
    Queue(const Queue &q)
    {
        front = NULL;
        rear = NULL;
<<<<<<< HEAD
        if (q.front == NULL)
=======
        if (q.front == NULL) 
>>>>>>> 685987ef3b744ee1db9228189617fb9456d17525
        {
            return;
        }
        node *temp = q.front;
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
            node *temp = q.front;
            while (temp != NULL)
            {
                insert(temp->item);
                temp = temp->next;
            }
        }
        return *this;
    }
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
    }
    int count()
    {
        node *temp=front;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    ~Queue()
    {
        while (front != NULL)
            delFront();
    }
}; */

/* //! 13th Task: Deque using Array
#include <iostream>
using namespace std;
class Deque
{
private:
    int capacity;
    int front, rear;
    int *ptr;

public:
    Deque();
    Deque(int);
    Deque(const Deque &d);
    const Deque &operator=(const Deque &d);
    void insertFront(int);
    void insertBack(int);
    void delFront();
    void delBack();
    bool underflow();
    bool overflow();
    int getFront();
    int getBack();
    ~Deque();
};
Deque::Deque()
{
    capacity = 0;
    front = -1;
    rear = -1;
    ptr = NULL;
}
Deque::Deque(int c)
{
    capacity = c;
    front = -1;
    rear = -1;
    if (capacity <= 0)
        ptr = NULL;
    else
        ptr = new int[capacity];
}
Deque::Deque(const Deque &d)
{
    if (d.capacity == 0)
        return;
    capacity = d.capacity;
    front = d.front;
    rear = d.rear;
    ptr = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
        ptr[i] = d.ptr[i];
    }
}
const Deque &Deque::operator=(const Deque &d)
{
    if (this != &d)
    {
        if(ptr!=NULL)
        {
            delete []ptr;
        }
        if (d.capacity == 0)
            return;
        capacity = d.capacity;
        front = d.front;
        rear = d.rear;
        ptr = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            ptr[i] = d.ptr[i];
        }
    }
    return *this;
}
void Deque::insertBack(int data)
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
void Deque::insertFront(int data)
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
void Deque::delFront()
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
void Deque::delBack()
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
bool Deque::overflow()
{
    return (front == 0 && rear == capacity - 1 || front == rear + 1);
}
bool Deque::underflow()
{
    return front == -1;
}
int Deque::getFront()
{
    if (underflow())
    {
        cout << "Deque is Empty." << endl;
        return;
    }
    return ptr[front];
}
int Deque::getBack()
{
    if (underflow())
    {
        cout << "Deque is Empty." << endl;
        return;
    }
    return ptr[rear];
}
Deque ::~Deque()
{
    delete[] ptr;
} */

<<<<<<< HEAD
/* //! 14th Task: Deque using Doubly linked list
=======
/* //! 14th Task: Deque using linked list
>>>>>>> 685987ef3b744ee1db9228189617fb9456d17525
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
    Deque();
    Deque(const Deque &d);
    const Deque &operator=(const Deque &d);
    void insertFront(int data);
    void insertRear(int data);
    void delFront();
    void delRear();
    node *getFront();
    node *getRear();
    bool isEmpty();
    ~Deque();
};
Deque::Deque()
{
    front = NULL;
    rear = NULL;
}
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
}
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
}

void Deque::insertFront(int data)
{
    node *newnode = new node;
    newnode->item = data;
    newnode->prev = NULL;
    if (front == NULL )
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
void Deque::insertRear(int data)
{
    node *newnode = new node;
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
void Deque::delFront()
{
    if (front == NULL)
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
        front = front->next;
        front->prev = NULL;
    }
    delete t;
}
void Deque::delRear()
{
    if (front == NULL )
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
}
node *Deque::getFront()
{
    if (front == NULL)
    {
        cout << "Deque is Empty." << endl;
        return NULL;
    }
    return front;
}
node *Deque::getRear()
{
    if (front == NULL)
    {
        cout << "Deque is Empty." << endl;
        return NULL;
    }
    return rear;
}
bool Deque::isEmpty()
{
    return (front == NULL);
}
Deque::~Deque()
{
    while (front != NULL)
        delFront();
} */

/* //! 15th Task: Priority Queue using Singly Linked List
#include <iostream>
using namespace std;
struct node
{
    int priority;
    int item;
    node *next;
};
class PriorityQueue
{
private:
    node *start;

public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue &p);
    const PriorityQueue &operator=(const PriorityQueue &p);
    void insert(int, int);
    void delHighestPriority();
    node *getHighestPriority();
    int getHighestPriorityNumber();
    bool isEmpty();
    ~PriorityQueue();
};
PriorityQueue::PriorityQueue()
{
    start = NULL;
}
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
}
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
}

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
}
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
}
node *PriorityQueue::getHighestPriority()
{
    if (start == NULL)
    {
        return NULL;
    }
    return start;
}
int PriorityQueue::getHighestPriorityNumber()
{
    if (start == NULL)
    {
        return -1;
    }
    return start->priority;
}
bool PriorityQueue::isEmpty()
{
    return start == NULL;
}
PriorityQueue::~PriorityQueue()
{
    while (start)
        delHighestPriority();
}*/

/* //! 16th Task: Priority Queue using Array
#include <iostream>
using namespace std;
class PriorityQueue
{
private:
    int **arr;
    int capacity;
    int lastindex;

public:
    PriorityQueue(int cap)
    {
        capacity = cap;
        lastindex = -1;
        arr = new int *[capacity]; // Array of pointers
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = new int[2]; // her pointer ek array ko point krega jo , nya 2 size ka array create krega,priority+element
        }
    }
    PriorityQueue(const PriorityQueue &p)
    {
        capacity = p.capacity;
        lastindex = p.lastindex;
        arr = new int *[capacity];
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = new int[2];
            arr[i][0] = p.arr[i][0];
            arr[i][1] = p.arr[i][1];
        }
    }
    const PriorityQueue &operator=(const PriorityQueue &p)
    {
        if (this != &p)
        {
            for (int i = 0; i < lastindex; i++)
            {
                delete[] arr[i];
            }
            delete[] arr;
            capacity = p.capacity;
            lastindex = p.lastindex;
            arr = new int *[capacity];
            for (int i = 0; i < capacity; i++)
            {
                arr[i] = new int[2];
                arr[i][0] = p.arr[i][0];
                arr[i][1] = p.arr[i][1];
            }
        }
        return *this;
    }
    void insert(int p, int data)
    {
        if (lastindex == capacity - 1)
        {
            cout << "Queue is Full." << endl;
            return;
        }
        int i = lastindex;
        while (i >= 0 && arr[i][0] < p)
        {
            arr[i + 1][0] = arr[i][0];
            arr[i + 1][1] = arr[i][1];
            i--;
        }
        arr[i + 1][0] = p;
        arr[i + 1][1] = data;
        lastindex++;
    }
    void delHighestPriority()
    {
        if (lastindex == -1)
        {
            cout << "Queue is Empty." << endl;
            return;
        }
        delete[] arr[0];

        for (int i = 0; i < lastindex; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[lastindex] = NULL;
        lastindex--;
    }
    void display()
    {
        if (lastindex == -1)
        {
            cout << "Queue is Empty." << endl;
            return;
        }
        for (int i = 0; i <= lastindex; i++)
        {
            cout << "(" << arr[i][0] << "," << arr[i][1] << ")" << endl;
        }
    }
    int *getHighestPriority()
    {
        if (lastindex == -1)
        {
            cout << "Queue is Empty." << endl;
            return NULL;
        }
        return arr[0];
    }
    bool isEmpty()
    {
        return lastindex == -1;
    }
    bool isFull()
    {
        return lastindex == capacity - 1;
    }
    ~PriorityQueue()
    {
        for (int i = 0; i < capacity; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
};
int main()
{
    PriorityQueue pq(5);
    pq.insert(2, 12);
    pq.insert(4, 16);
    pq.insert(3, 15);

    pq.delHighestPriority();
    pq.display();
} */

/* //! 17th Task: Tree
#include <iostream>
using namespace std;
#define DATA_NOT_FOUND 1
struct node
{
    node *left;
    int item;
    node *right;
};
class BST
{
private:
    node *root;

public:
    BST();
    BST(const BST &b);
    const BST &operator=(const BST &b);
    node *copyTree(node *);
    bool isEmpty();
    void insert(int);
    void preorder(node *);
    void inorder(node *);
    void postorder(node *);
    void del(int);
    bool search(node *, int);
    void display();
    void destroyTree(node *);
    ~BST();
};
BST::BST()
{
    root = NULL;
}
BST::BST(const BST &b)
{
    root = NULL;
    if (b.root == NULL)
        return;
    root = copyTree(b.root);
}
node *BST::copyTree(node *otherroot)
{
    if (otherroot == NULL)
        return NULL;
    node *newnode = new node;
    newnode->item = otherroot->item;
    newnode->left = copyTree(otherroot->left);
    newnode->right = copyTree(otherroot->right);
    return newnode;
}
const BST &BST::operator=(const BST &b)
{
    if (this != &b)
    {

        destroyTree(root);
        root = NULL;
        if (b.root == NULL)
            return *this;
        root = copyTree(b.root);
    }
    return *this;
}
bool BST::isEmpty()
{
    return root == NULL;
}
void BST::insert(int data)
{
    node *newnode = new node;
    newnode->item = data;
    newnode->left = NULL;
    newnode->right = NULL;
    if (isEmpty())
    {
        root = newnode;
        return;
    }
    node *t = root;
    while (true)
    {
        if (data < t->item)
        {
            if (t->left == NULL)
            {
                t->left = newnode;
                break;
            }
            t = t->left;
        }
        else
        {
            if (t->right == NULL)
            {
                t->right = newnode;
                break;
            }
            t = t->right;
        }
    }
}
void BST::preorder(node *root)
{
    if (root)
    {
        cout << root->item << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void BST::inorder(node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->item << " ";
        inorder(root->right);
    }
}
void BST::postorder(node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->item << " ";
    }
}
void BST::del(int data)
{
    if (root == NULL)
    {
        cout << "Tree is Empty." << endl;
        return;
    }
    node *ptr=root, *parptr=NULL;
    while (ptr)
    {
        if (ptr->item == data)
            break;
        if (data < ptr->item)
        {
            parptr = ptr;
            ptr = ptr->left;
        }
        else
        {
            parptr = ptr;
            ptr = ptr->right;
        }
    }
    if (ptr == NULL)
        throw DATA_NOT_FOUND;
    if (parptr == NULL && ptr != NULL) // root node to be deleted
    {
        if (ptr->left == NULL && ptr->right == NULL) // no chlid
        {
            delete ptr;
            root = NULL;
        }
        else if (ptr->left && ptr->right) // two child class
        {
            node *suc,*parsuc;
            suc=ptr->right;
            parsuc=ptr;
            while(suc->left!=NULL)
            {
                parsuc=suc;
                suc=suc->left;
            }
            ptr->item=suc->item;
            // now delete successor

            if(suc==parsuc->left)
            parsuc->left=suc->right;
            else
            parsuc->right=suc->right;
            delete suc;
        }
        else // one chlid
        {
            if (ptr->left)
                root = ptr->left;
            else
                root = ptr->right;
            delete ptr;
        }
    }
    else // node to be deleted is not a root node
    {
        if (ptr->left == NULL && ptr->right == NULL) // no chlid
        {
            if (ptr == parptr->left) // ptr is left child of parent ptr
            {
                parptr->left = NULL;
                delete ptr;
            }
            else // ptr is right child of parent ptr
            {
                parptr->right = NULL;
                delete ptr;
            }
        }
        else if (ptr->left && ptr->right) // two child class
        {
            node *suc,*parsuc;
            suc=ptr->right;
            parsuc=ptr;
            while(suc->left!=NULL)
            {
                parsuc=suc;
                suc=suc->left;
            }
            ptr->item=suc->item;
            // now delete successor

            if(suc==parsuc->left)
            parsuc->left=suc->right;
            else
            parsuc->right=suc->right;
            delete suc;
        }
        else // one chlid
        {
            if (ptr == parptr->left) // ptr is left child of parent ptr
            {
                if (ptr->left)
                    parptr->left = ptr->left;
                else
                    parptr->left = ptr->right;
                delete ptr;
            }
            else // ptr is right child of parent ptr
            {
                if (ptr->left)
                    parptr->right = ptr->left;
                else
                    parptr->right = ptr->right;
                delete ptr;
            }
        }
    }
}
bool BST::search(node *root, int data)
{
    while (root != NULL)
    {
        if (data == root->item)
            return true;

        if (data < root->item)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return false;
}
void BST::display()
{
    inorder(this->root);
    cout << endl;
}
void BST::destroyTree(node *root)
{
    if (root)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
        root = NULL;
    }
}
BST::~BST()
{
    destroyTree(root);
}

int main()
{
    BST b;
    b.insert(50);
    b.insert(20);
    b.insert(40);
    b.insert(80);
    b.insert(60);

    b.display();
}
 */

 
