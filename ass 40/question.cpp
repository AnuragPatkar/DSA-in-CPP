//! Assignment-40: Array

/* //? 1. Define a class Array to implement array data structure with member variables to store capacity of array, last index of the last filled block of the array and a pointer to hold the address of the first block of the dynamically created array.
#include <iostream>
using namespace std;
class Array
{
private:
    int capacity;
    int lastindex;
    int *ptr;

public:
    Array(int);
    bool isEmpty();
    bool isFull();
    void append(int);
    void insert(int, int);
    void edit(int, int);
    void del(int);
    int getElement(int);
    int num_of_element();
    int find_Element(int);
    ~Array();
};
Array::Array(int c)
{
    capacity = c;
    lastindex = -1;
    ptr = new int[capacity];
}
bool Array::isEmpty()
{
    return lastindex == -1;
}
void Array::append(int data)
{
    if (isFull())
    {
        cout << "Array is full." << endl;
        return;
    }
    lastindex++;

    ptr[lastindex] = data;
}
bool Array::isFull()
{
    return lastindex == capacity - 1;
}
void Array::insert(int index, int data)
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
    ptr[index] = data;
    lastindex++;
}
void Array::edit(int index, int data)
{
    if (index < 0 || index > lastindex )
    {
        cout << "invalid index." << endl;
        return;
    }
    ptr[index] = data;
}
void Array::del(int index)
{
    if (index < 0 || index > lastindex)
    {
        cout << "Invalid index.";
        return;
    }
    int i;
    for (i = index; i < lastindex; i++)
    {
        ptr[i] = ptr[i + 1];
    }
    lastindex--;
}
int Array::getElement(int index)
{
    if (index < 0 || index > lastindex)
    {
        cout << "Invalid index\n";
        return -1;
    }
    return ptr[index];
}
int Array::num_of_element()
{
    return lastindex + 1;
}
int Array::find_Element(int data)
{
    int i;
    for(i=0;i<=lastindex;i++)
    {
        if(ptr[i]==data)
         return i;
    }
    return -1;
}
Array::~Array()
{
    delete[] ptr;
} */

/* //? 2. In question 1, define a parameterised constructor to create an array of specified size.
Array::Array(int c)
{
    capacity=c;
    lastindex=-1;
    ptr=new int[capacity];
} */

/* //? 3. In the question 1, add a method to check whether an array is empty or not by returning True or False.
bool Array::isEmpty()
{
    return lastindex!=-1;
} */

/* //? 4. In question 1, define a method to append a new element in the array
void Array::append(int data)
{
    if (isFull())
    {
        cout << "Array is full." << endl;
    }
    lastindex++;

    ptr[lastindex] = data;
}
bool Array::isFull()
{
    return lastindex == capacity - 1;
} */

/* //? 5. In question 1, define a method to insert a new element at specified index
void Array::insert(int index, int data)
{
    if (index < 0 || index > lastindex + 1 )
    {
        cout << "Invalid index or array is full\n";
        return;
    }
    for (int i = lastindex; i >= index; i--)
    {
        ptr[i + 1] = ptr[i];
    }
    ptr[index]=data;
    lastindex++;

} */

/* //? 6. In question 1, define a method to edit an element at specified index.
void Array::edit(int index, int data)
{
    if (index < 0 || index > lastindex + 1)
    {
        cout << "invalid index." << endl;
        return;
    }
    ptr[index] = data;
} */

/* //? 7. In question 1, define a method to delete an element at specified index.
void Array::del(int index)
{
    if(index<0||index>lastindex)
    {
        cout<<"Invalid index.";
        return;
    }
    int i;
    for(i=index;i<=lastindex;i++)
    {
        ptr[i]=ptr[i+1];
    }
    lastindex--;
} */

/* //? 8. In question 1, define a method to check if the array is full by returning true or false.
bool Array::isFull()
{
    return lastindex == capacity - 1;
} */

/* //? 9. In question 1, define a method to get element at specified index.
int Array::getElement(int index)
{
    if (index < 0 || index > lastindex)
    {
        cout << "Invalid index\n";
        return -1;
    }
    return ptr[index];
} */

/* //? 10. In question 1, define a method to count number of elements present in the array.
int Array::num_of_element()
{
    return lastindex+1;
} */

/* //? 11. In question 1, define a destructor to deallocate the memory of array.
Array::~Array()
{
    delete[] ptr;
} */

/* //? 12. In question 1, define a method to find an element in the array. Return index if the element found, otherwise return -1.
int Array::find_Element(int data)
{
    int i;
    for(i=0;i<=lastindex;i++)
    {
        if(ptr[i]==data)
         return i;
    }
    return -1;
} */