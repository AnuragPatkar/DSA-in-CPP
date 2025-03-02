//! Assignment-42: Dynamic Arrays

/* //? 1. Define a class DynArray to implement dynamic array data structure with member variables to store capacity of array, last index of the last filled block of the array and a pointer to hold the address of the first block of the dynamically created array.
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

/* //? 2. In question 1, define a parameterised constructor to create an array of specified size.
DynArray::DynArray(int c)
{
    capacity=c;
    lastindex=-1;
    ptr=new int[capacity];
} */

/* //? 3. In question 1, define a method doubleArray() to increase the size of the array by double of its size.
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
} */

/* //? 4. In question 1, define a method halfArray() to decrease the size of the array by half of its size.
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
} */

/* //? 5. In question 1, define a method which returns the current capacity of the array.
int DynArray::cap_of_array()
{
    return capacity;
} */

/* //? 6. In the question 1, add a method to check whether an array is empty or not by returning True or False.
bool DynArray::isEmpty()
{
    return lastindex == -1;
} */

/* //? 7. In question 1, define a method to append a new element in the array
void DynArray::append(int data)
{
    if(lastindex==capacity-1)
    {
        doubleArray();
    }
    lastindex++;

    ptr[lastindex] = data;
} */

/* //? 8. In question 1, define a method to insert a new element at specified index
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
} */

/* //? 9. In question 1, define a method to edit an element at specified index.
void DynArray::edit(int index, int data)
{
    if (index < 0 || index > lastindex)
    {
        cout << "Invalid Index." << endl;
        return;
    }
    ptr[index] = data;
} */

/* //? 10. In question 1, define a method to delete an element at specified index.
void DynArray::del(int index)
{
    if (index < 0 || index > lastindex)
    {
        cout << "Invalid Index." << endl;
        return;
    }
    int i;
    for(i=index;i<lastindex;i++)
    {
        ptr[i]=ptr[i+1];
    }
    lastindex--;
     if (capacity > 1 && lastindex + 1 <= capacity / 2)
        halfArray();
} */

/* //? 11. In question 1, define a method to check if the array is full by returning true or false.
bool DynArray::isFull()
{
    return lastindex == capacity - 1;
} */

/* //? 12. In question 1, define a method to get element at specified index.
int DynArray::getElement(int index)
{
    if(index<0||index>lastindex)
    {
        cout<<"invalid index.";
        return -1;
    }
    return ptr[index];
} */

/* //? 13. In question 1, define a method to count number of elements present in the array.
int DynArray::count()
{
    return lastindex+1;
} */

/* //? 14. In question 1, define a destructor to deallocate the memory of array.
DynArray::~DynArray()
{
    delete[] ptr;
} */

/* //? 15. In question 1, define a method to find an element in the array. Return index if the element found, otherwise return -1.
int DynArray::findElement(int data)
{
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        if (ptr[i] == data)
            return i;
    }
    return -1;
} */

/* //? 16. In question 1, define a copy constructor to implement deep copy.
DynArray::DynArray(DynArray &arr)
{
    capacity = arr.capacity;
    lastindex = arr.lastindex;
    ptr = new int[capacity];
    for (int i = 0; i <= lastindex; i++)
    {
        ptr[i] = arr.ptr[i];
    }
} */

/* //? 17. In question 1, define a copy assignment operator to implement deep copy.
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
} */