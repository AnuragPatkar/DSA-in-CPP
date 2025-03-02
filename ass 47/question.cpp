//! Assignment-47: Stack using arrays

/* //? 1. Define a class Stack with capacity, top and ptr pointer as member variables. Implement stack using array.
#include <iostream>
using namespace std;
class STACK
{
private:
    int capacity;
    int top;
    int *ptr;
}; */

/* //? 2. In question 1, define a parameterzied constructor to initialise member variables.
STACK(int size)
{
    capacity = size;
    top = -1;
    ptr = new int[capacity];
} */

/* //? 3. In question 1, define a method to push a new element on to the Stack.
void push(int data)
{
    if (top >= capacity - 1)
    {
        cout << "STACK is FULL." << endl;
        return;
    }
    ptr[++top] = data;
} */

/* //? 4. In question 1, define a method to peek top element of the stack.
int peek()
{
    if (top < 0)
    {
        cout << "STACK is Empty." << endl;
        return -1;
    }
    return ptr[top];
} */

/* //? 5. In question 1, define a method to pop the top element of the stack.
int pop()
{
    if (top < 0)
    {
        cout << "STACK is Empty." << endl;
        return -1;
    }
    return ptr[top--];
} */

/* //? 6. In question 1, define a destructor to deallocates the memory.
~STACK()
{
    delete []ptr;
} */

/* //? 7. In question 1, define a method to check stack overflow
bool stackOverflow()
{
    return top >= capacity - 1;
} */

/* //? 8. In question 1, define a method to check stack underflow.
bool stackUnderflow()
{
    return top < 0;
} */

/* //? 9. In question 1, define a copy constructor to implement deep copy.
STACK(STACK &s)
{
    capacity = s.capacity;
    top = s.top;
    ptr = new int[capacity];

    for (int i = 0; i <= top; i++)
    {
        ptr[i] = s.ptr[i];
    }
} */

/* //? 10. In question 1, define a copy assignment operator to implement deep copy
STACK &operator=(STACK &s)
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
} */